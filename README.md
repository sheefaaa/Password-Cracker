# Password Cracking System

## Description
The **Password Cracking System** is a simple C program that demonstrates two types of password attacks:
1. **Dictionary Attack**: Compares the hashed password against a list of common weak passwords.
2. **Brute Force Attack**: Attempts to crack short passwords by generating all possible character combinations.

The program utilizes the **DJB2 hashing algorithm** to generate hashes for password comparison.

## Features
- Uses a predefined dictionary of common passwords.
- Implements a brute force attack for passwords of length 3 (a-z, A-Z, 0-9).
- Provides a simple command-line interface for user interaction.

## Usage
### Compilation
Use the following command to compile the program:
```bash
gcc password_cracking.c -o password_cracking
```

### Running the Program
Execute the compiled file:
```bash
./password_cracking
```

### Menu Options
- **1. Brute Force Attack**: Attempts to guess the password by generating all possible 3-character combinations.
- **2. Dictionary Attack**: Checks if the password exists in a predefined dictionary of weak passwords.
- **3. Exit**: Terminates the program.

## Example Usage
```
============================
   PASSWORD CRACKING SYSTEM  
============================
1. Brute Force Attack
2. Dictionary Attack
3. Exit
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Enter your choice: 2

Enter password to check: password123

Weak password found in dictionary! (password123)
```

## Limitations
- The brute force attack is limited to passwords of **exactly 3 characters**.
- The dictionary attack is restricted to the predefined list of common passwords.
- The program does not handle salts or advanced cryptographic hashing methods.

## Future Improvements
- Expand brute force attack to handle longer passwords.
- Implement support for multi-threading to improve brute-force efficiency.
- Enhance security with more advanced cryptographic techniques.

## License
This project is for educational purposes only. Unauthorized use against real-world systems without permission is strictly prohibited.

