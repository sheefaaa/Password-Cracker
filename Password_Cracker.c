#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Structure for Password Data
typedef struct {
    char password[20];
    int hash;
} PasswordData;

// Function to generate hash
int generate_hash(char *password) {
    int hash = 5381;
    for (int i = 0; password[i] != '\0'; i++) {
        hash = ((hash << 5) + hash) + password[i];  // DJB2 Hashing Algorithm (hash * 33 + char)
    }
    return hash;
}

// Dictionary Attack Function
void dictionary_attack(PasswordData *user) {
    char *common_passwords[] = { "123", "admin", "password", "hello", "abc",
    "qwerty", "letmein", "123456", "monkey", "sunshine",
    "password1", "welcome", "iloveyou", "football", "123123",
    "abc123", "password123", "admin123", "123456789", "000000",
    "login", "starwars", "superman", "batman", "trustno1",
    "qwerty123", "dragon", "baseball", "shadow", "master",
    "666666", "123qwe", "121212", "photoshop", "ashley",
    "1234", "qwe123", "hello123", "letmein123", "passw0rd",
    "welcome123", "michael", "ninja", "mustang", "jennifer",
    "hunter", "freedom", "charlie", "qazwsx", "killer",
    "zaq1zaq1", "trustme", "iloveu", "soccer", "princess",
    "whatever", "nothing", "654321", "hockey", "cookie", "shefa"};

    int found = 0;
    for (int i = 0; i < 61; i++) {
        if (user->hash == generate_hash(common_passwords[i])) {
            printf("\nWeak password found in dictionary! (%s)\n", common_passwords[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nPassword not found in dictionary.\n");
    }
}

// Brute Force Attack Function (For 3-character passwords)
void brute_force_attack(PasswordData *user) {
    char guess[4] = "";
    char characters[62];  // a-z + A-Z + 0-9 = 26 + 26 + 10 = 62
    int index = 0;

    // Create character set
    for (char c = 'a'; c <= 'z'; c++) {
        characters[index++] = c;
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        characters[index++] = c;
    }
    for (char c = '0'; c <= '9'; c++) {
        characters[index++] = c;
    }

    printf("\nTrying Brute Force Attack (a-z, A-Z, 0-9)...\n");

    for (int i = 0; i < 62; i++) {
        for (int j = 0; j < 62; j++) {
            for (int k = 0; k < 62; k++) {
                guess[0] = characters[i];
                guess[1] = characters[j];
                guess[2] = characters[k];
                guess[3] = '\0';

                printf("Trying: %s\r", guess);
                fflush(stdout);  // Flush output buffer to show each attempt
                usleep(10000);   // 10ms delay (shorter than before for demonstration)

                if (user->hash == generate_hash(guess)) {
                    printf("\nPassword cracked using brute force: %s\n", guess);
                    return;
                }
            }
        }
    }
    printf("\nPassword not found using brute force.\n");
}

int main() {
    int choice;
    PasswordData user;

    while (1) {
        printf("\n============================\n");
        printf("   PASSWORD CRACKING SYSTEM  \n");
        printf("============================\n");
        printf("1. Brute Force Attack\n");
        printf("2. Dictionary Attack\n");
        printf("3. Exit\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("\nExiting... Thank you!\n");
            break;
        }
        if (choice==1){
        printf("\nEnter password to check (Only 3 characters): ");
        }
        else{
             printf("\nEnter password to check: ");
        }
        scanf("%s", user.password);
        user.hash = generate_hash(user.password); // Hashing the input password

        if (choice == 1) {
            brute_force_attack(&user);
        } else if (choice == 2) {
            dictionary_attack(&user);
        } else {
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}

