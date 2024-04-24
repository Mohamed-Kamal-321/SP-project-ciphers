
#include<iostream>
#include<string>
#include <cctype>
#include<vector>
#include<algorithm>
#include<sstream>
#include <bits/stdc++.h>
#define endl "\n"
#define all(v)  v.begin() ,v.end()
using namespace std;

void Affine_Encrypt();
void Affine_Decrypt();
void Route_Cipher();
void Route_Decipher();
void Atbash_Cipher();
void vignere_Encrypt();
void vignere_Decrypt();
string decToBinary(int n);
int binaryToDecimal(int n);
void Baconian_Cipher();
void Baconian_Decipher();
void Morse_Code_Cipher();
void Morse_Code_Decipher();
void Rail_fence(int choice);
void Simple_Substitution(int op);
void xor_cipher(int n);


int main() {
    // Display welcome message
    cout << "Welcome to message cipher and decipher program." << endl;

    // Main program loop
    while (true) {
        // Display options to the user
        cout << "What do you want to do?" << endl;
        cout << "1-Cipher a message" << endl << "2-Decipher a message" << endl << "3-Exit" << endl << endl;
        string user_choice1;
        cout << "Please enter a number from 1 to 3" << endl;
        cin >> user_choice1;

        // Validate user input for the main menu
        while (true) {
            if (user_choice1 != "1" && user_choice1 != "2" && user_choice1 != "3") {
                cout << "Invalid choice. Please enter a number from 1 to 3" << endl;
                cin >> user_choice1;
            }
            else break;
        }

        // Cipher a message
        if (user_choice1 == "1") {
            cout << endl;
            string user_choice2;
            cout << "Which Cipher do you want to use?" << endl
            << "1-Affine Cipher" << endl
            << "2-Atbash Cipher" << endl
            << "3-Vignere Cipher" << endl
            << "4-Rail-fence Cipher" << endl
            <<"5-Route Cipher"<<endl
            <<"6-Baconian Cipher"<<endl
            <<"7-Morse Code Cipher"<<endl
            <<"8-Simple Substitution Cipher"<<endl
            <<"9-Xor Cipher"<<endl;
            cin >> user_choice2;

            // Validate user input for cipher selection
            while (true) {
                if (stoi(user_choice2)<1 or stoi(user_choice2)>10) {
                    cout << "Invalid choice. Please enter a number from 1 to 10" << endl;
                    cin >> user_choice2;
                }
                else break;
            }
            cout << endl;

            // Perform selected cipher operation
            if (user_choice2 == "1") {
                Affine_Encrypt();
                cout << endl;
            }
            else if (user_choice2 == "2") {
                Atbash_Cipher();
                cout << endl;
            }
            else if (user_choice2 == "3") {
                vignere_Encrypt();
                cout << endl;
            }
            else if (user_choice2 == "4") {
                Rail_fence(1);
                cout << endl;
            }
            else if (user_choice2 == "5") {
                Route_Cipher();
                cout << endl;
            }
            else if (user_choice2 == "6") {
                Baconian_Cipher();
                cout << endl;
            }
            else if (user_choice2 == "7") {
                Morse_Code_Cipher();
                cout << endl;
            }
            else if (user_choice2 == "8") {
                Simple_Substitution(1);
                cout << endl;
            }
            else if (user_choice2 == "9") {
                 xor_cipher(1);
                cout << endl;
            }
        }

        // Decipher a message
        if (user_choice1 == "2") {
            cout << endl;
            string user_choice2;
            cout << "Which Cipher do you want to use?" << endl
                 << "1-Affine Decipher" << endl
                 << "2-Atbash Decipher" << endl
                 << "3-Vignere Decipher" << endl
                 << "4-Rail-fence Decipher" << endl
                 <<"5-Route Decipher"<<endl
                 <<"6-Baconian Decipher"<<endl
                 <<"7-Morse Code Decipher"<<endl
                 <<"8-Simple Substitution Decipher"<<endl
                 <<"9-Xor Decipher"<<endl;
            cin >> user_choice2;
            // Validate user input for decipher selection
            while (true) {
                if (stoi(user_choice2)<1 or stoi(user_choice2)>10) {
                    cout << "Invalid choice. Please enter a number from 1 to 10" << endl;
                    cin >> user_choice2;
                }
                else break;
            }
            cout << endl;

            // Perform selected decipher operation
            if (user_choice2 == "1") {
                Affine_Decrypt();
                cout << endl;
            }
            else if (user_choice2 == "2") {
                Atbash_Cipher();
                cout << endl;
            }
            else if (user_choice2 == "3") {
                vignere_Decrypt();
                cout << endl;
            }
            else if (user_choice2 == "4") {
                Rail_fence(2);
                cout << endl;
            }
            else if (user_choice2 == "5") {
                Route_Decipher();
                cout << endl;
            }
            else if (user_choice2 == "6") {
                Baconian_Decipher();
                cout << endl;
            }
            else if (user_choice2 == "7") {
                Morse_Code_Decipher();
                cout << endl;
            }
            else if (user_choice2 == "8") {
                Simple_Substitution(2);
                cout << endl;
            }
            else if (user_choice2 == "9") {
                xor_cipher(2);
                cout << endl;
            }
        }

        // Exit the program
        if (user_choice1 == "3") {
            break;
        }
    }
    return 0;
}

// Function to encrypt a message using Affine cipher
void Affine_Encrypt() {
    // Declare variables to store message and keyword
    string message, keyword;

    // Prompt user to enter message (up to 80 characters) and keyword (up to 8 characters)
    cin.ignore();
    cout << "Enter the message (up to 80 characters): ";
    getline(cin, message);

    // Check if message or keyword exceeds length limit
    while (message.length() > 80 ) {
        cout << "Enter the message (up to 80 characters): ";
        getline(cin, message);
    }

    // Declare variable to store encrypted message
    string encryptedMessage;
    // Initialize index for keyword
    int keywordIndex = 0;

    // Convert message to uppercase
    for (char& ch : message) {
        if (isalpha(ch))
            ch = toupper(ch);
    }


    // Encrypt the message using the Vigenere cipher
    for (int i = 0; i < message.length(); i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            // Apply the Affine encryption formula
            ch = ((5*(ch - 'A')+8) % 26) + 'A';
        }
        // Append the encrypted character to the encrypted message
        encryptedMessage += ch;
    }

    // Output the encrypted message
    cout << "Encrypted message: " << encryptedMessage << endl;
}

// Function to decrypt a message encrypted using Affine cipher
void Affine_Decrypt() {
    // Declare variables to store encrypted message and keyword
    string encryptedMessage, keyword;

    // Prompt user to enter encrypted message (up to 80 characters) and keyword (up to 8 characters)
    cin.ignore();
    cout << "Enter the message (up to 80 characters): ";
    getline(cin, encryptedMessage);

    // Check if encrypted message or keyword exceeds length limit
    while (encryptedMessage.length() > 80 ) {
            cout << "Enter the message (up to 80 characters): ";
            getline(cin, encryptedMessage);
    }

    // Declare variable to store decrypted message
    string decryptedMessage = "";
    // Initialize index for keyword
    int keywordIndex = 0;


    // Convert message to uppercase
    for (char& ch : encryptedMessage) {
        if (isalpha(ch))
            ch = toupper(ch);
    }

    // Decrypt the message using the Affine cipher
    for (int i = 0; i < encryptedMessage.length(); i++) {
        char ch = encryptedMessage[i];
        if (isalpha(ch)) {
            // Apply the Affine decryption formula
            ch = ((ch - 'A' - 8 + 26)*21 % 26) + 'A';

        }
        // Append the decrypted character to the decrypted message
        decryptedMessage += ch;
    }

    // Output the decrypted message
    cout << "Decrypted message: " << decryptedMessage << endl;
}
// Function to cipher a message using Route Cipher
void Route_Cipher() {
    // Declare necessary variables
    string s, q, output;
    int key, x, y, t, k;

    // Prompt user to enter the message to cipher
    cout << "Enter the message to cipher: " << endl;
    cin.ignore();
    // Read the message including whitespaces
    getline(cin, s);

    // Prompt user to enter the secret key
    cout << "Enter the secret key: " << endl;
    // Read the secret key
    cin >> key;

    // Initialize variables
    y = k = 0;

    // Convert input to uppercase and remove non-alphabetic characters
    for (char v: s) {
        if (isalpha(v)) {
            q += char(toupper(v));
        }
    }

    // Pad the string with 'X' to make its length a multiple of the key
    while (q.size() % key != 0) {
        q += 'X';
    }

    // Calculate the number of rows in the matrix
    x = q.size() / key;

    // Declare a 2D array to hold the characters of the message
    char arr[key][x];

    // Fill the matrix with characters from the padded string
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < key; ++j) {
            arr[j][i] = q[i + j + y];
        }
        y = y + (key - 1);
    }

    // Print the matrix (for debugging)
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < key; ++j) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    // Initialize the variable to track the remaining characters
    t = q.size();

    // Encrypt the message
    while (t > 0) {
        k++;
        for (int j = k-1; j < x - k && t > 0; ++j) {
            output += arr[key  - k][j];
            t--;
        }
        for (int j = key  - k; j >= k-1 && t > 0; --j) {
            output += arr[j][x  - k];
            t--;
        }
        for (int j = x  - k-1; j >= k-1 && t > 0; --j) {
            output += arr[k-1][j];
            t--;
        }
        for (int j =  k; j < key - k && t > 0; ++j) {
            output += arr[j][ k-1];
            t--;
        }
    }

    // Output the ciphered message
    cout << "The ciphered message is: " << output << endl;
}

// Function to decipher a message encoded in Route Decipher
void Route_Decipher() {
    string s, q, output; // Input message, processed message, and output
    int key, x, y, t, k; // Key, matrix dimensions, counters
    y = k = 0; // Initialize counters
    cout<<"Enter the message to decipher: "<<endl; // Prompt for input
    cin.ignore();
    getline(cin,s); // Read input
    cout<<"Enter the secret key: "<<endl; // Prompt for key
    cin >> key; // Read key
    // Process input: convert to uppercase, remove non-alphabetic characters
    for (char v: s) {
        if (isalpha(v)) {
            q += char(toupper(v));
        }
    }
    // Ensure processed message length is multiple of key
    while(q.size() % key != 0) {
        cout<<"Invalid message length. Re-enter the message: "<<endl;
        q="";
        cin.ignore();
        getline(cin,s);
        for (char v: s) {
            if (isalpha(v)) {
                q += char(toupper(v));
            }
        }
        cout<<"Enter the secret key: "<<endl;
        cin >> key;
    }
    x = q.size() / key; // Calculate matrix rows
    char arr[key][x]; // Matrix to hold characters
    // Fill matrix with characters from processed message
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < key; ++j) {
            arr[j][i] = q[i + j + y];
        }
        y = y + (key - 1);
    }

    t = 0; // Counter for processed message
    // Decrypt message by rearranging characters in matrix
    while (t < q.size()) {
        k++; // Counter for spiral loop
        for (int j = k-1; j < x - k && t < q.size(); ++j) {
            arr[key - k][j] = q[t];
            t++;
        }
        for (int j = key - k; j >= k-1 && t < q.size(); --j) {
            arr[j][x - k] = q[t];
            t++;
        }
        for (int j = x - k-1; j >= k-1 && t < q.size(); --j) {
            arr[k-1][j] = q[t];
            t++;
        }
        for (int j = k; j < key - k && t < q.size(); ++j) {
            arr[j][k-1] = q[t];
            t++;
        }
    }
    // Print the matrix
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < key; ++j) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    // Reconstruct the original message
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < key; ++j) {
            output += arr[j][i];
        }
    }
    cout<<"The original message is: "<<output<<endl;
}

// Function to encrypt or decrypt a message using Atbash cipher
void Atbash_Cipher()
{
    string user_choice3; // Variable to store user's choice for type of Atbash cipher
    cout << "1-Use the whole alphabet" << endl << "2-Divide the alphabet into 2 groups" << endl;
    cin >> user_choice3; // Taking user's choice

    // Validation loop to ensure user enters a valid choice
    while (true)
    {
        if (user_choice3 != "1" and user_choice3 != "2")
        {
            cout << "Invalid choice. Please enter 1 or 2" << endl;
            cin >> user_choice3;
        }
        else
            break; // Break the loop if the choice is valid
    }
    cout << endl;

    if (user_choice3 == "1")
    {
        string msg, y, output; // Variables to store user's message, processed message, and output
        cin.ignore(); // Ignore any remaining characters in the input buffer
        cout << "Enter the message: ";
        getline(cin, msg); // Allowing input of a full line including spaces

        // Convert the message to uppercase and remove non-alphabetic characters
        for (char character : msg)
        {
            if (isalpha(character))
            {
                y = y + char(toupper(character));
            }
        }

        // Atbash encryption for whole alphabet
        for (char character : y)
        {
            // Atbash transformation: Replace each letter with its corresponding opposite in the alphabet
            output += char(int(character) + 25 - 2 * (int(character) - 65)); // ASCII manipulation for encryption
        }
        cout << "The output message is: " << output << endl; // Output the encrypted message
    }

    if (user_choice3 == "2")
    {
        string msg, y, output; // Variables to store user's message, processed message, and output
        cin.ignore(); // Ignore any remaining characters in the input buffer
        cout << "Enter the message: ";
        getline(cin, msg); // Allowing input of a full line including spaces

        // Convert the message to uppercase and remove non-alphabetic characters
        for (char character : msg)
        {
            if (isalpha(character))
            {
                y = y + char(toupper(character));
            }
        }

        // Atbash encryption for alphabet divided into two groups
        for (char character : y)
        {
            if (int(character) >= 65 and int(character) <= 77) // First group of alphabet
            {
                // Atbash transformation: Replace each letter with its corresponding opposite in the first group
                output += char(int(character) + 12 - 2 * (int(character) - 65)); // ASCII manipulation for encryption
            }
            if (int(character) >= 78 and int(character) <= 90) // Second group of alphabet
            {
                // Atbash transformation: Replace each letter with its corresponding opposite in the second group
                output += char(int(character) + 12 - 2 * (int(character) - 78)); // ASCII manipulation for encryption
            }
        }
        cout << "The output message is: " << output << endl; // Output the encrypted message
    }
}

// Function to encrypt a message using Vigenere cipher
void vignere_Encrypt() {
    // Declare variables to store message and keyword
    string message, keyword;

    // Prompt user to enter message (up to 80 characters) and keyword (up to 8 characters)
    cin.ignore();
    cout << "Enter the message (up to 80 characters): ";
    getline(cin, message);
    cout << "Enter the keyword (up to 8 characters): ";
    getline(cin, keyword);

    // Check if message or keyword exceeds length limit
    while (message.length() > 80 || keyword.length() > 8) {
        cout << "Message or keyword exceeds the length limit." << endl;
        cout << "Enter the message (up to 80 characters): ";
        getline(cin, message);
        cout << "Enter the keyword (up to 8 characters): ";
        getline(cin, keyword);
    }

    // Declare variable to store encrypted message
    string encryptedMessage;
    // Initialize index for keyword
    int keywordIndex = 0;

    // Convert message to uppercase
    for (char& ch : message) {
        if (isalpha(ch))
            ch = toupper(ch);
    }

    // Convert keyword to uppercase
    for (char& ch : keyword) {
        ch = toupper(ch);
    }

    // Extend the keyword to match the length of the message
    while (keyword.length() < message.length()) {
        keyword += keyword[keywordIndex++];
        keywordIndex %= keyword.length();
    }

    // Encrypt the message using the Vigenere cipher
    for (int i = 0; i < message.length(); i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            // Calculate the shift value based on the corresponding character in the keyword
            char keywordChar = keyword[i];
            int shift = (keywordChar - 'A') % 26;
            // Apply the Vigenere encryption formula
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Append the encrypted character to the encrypted message
        encryptedMessage += ch;
    }

    // Output the encrypted message
    cout << "Encrypted message: " << encryptedMessage << endl;
}

// Function to decrypt a message encrypted using Vigenere cipher
void vignere_Decrypt() {
    // Declare variables to store encrypted message and keyword
    string encryptedMessage, keyword;

    // Prompt user to enter encrypted message (up to 80 characters) and keyword (up to 8 characters)
    cin.ignore();
    cout << "Enter the message (up to 80 characters): ";
    getline(cin, encryptedMessage);
    cout << "Enter the keyword (up to 8 characters): ";
    getline(cin, keyword);

    // Check if encrypted message or keyword exceeds length limit
    while (encryptedMessage.length() > 80 || keyword.length() > 8) {
        cout << "Message or keyword exceeds the length limit." << endl;
            cout << "Enter the message (up to 80 characters): ";
            getline(cin, encryptedMessage);
            cout << "Enter the keyword (up to 8 characters): ";
            getline(cin, keyword);
    }

    // Declare variable to store decrypted message
    string decryptedMessage = "";
    // Initialize index for keyword
    int keywordIndex = 0;

        // Convert message to uppercase
    for (char& ch : encryptedMessage) {
        if (isalpha(ch))
            ch = toupper(ch);
    }

    // Convert keyword to uppercase
    for (char& ch : keyword)
        ch = toupper(ch);

    // Extend the keyword to match the length of the encrypted message
    while (keyword.length() < encryptedMessage.length()) {
        keyword += keyword[keywordIndex++];
        keywordIndex %= keyword.length();
    }

    // Decrypt the message using the Vigenere cipher
    for (int i = 0; i < encryptedMessage.length(); i++) {
        char ch = encryptedMessage[i];
        if (isalpha(ch)) {
            // Calculate the shift value based on the corresponding character in the keyword
            char keywordChar = keyword[i];
            int shift = (keywordChar - 'A') % 26;
            // Apply the Vigenere decryption formula
            ch = ((ch - 'A' - shift + 26) % 26) + 'A';
        }
        // Append the decrypted character to the decrypted message
        decryptedMessage += ch;
    }

    // Output the decrypted message
    cout << "Decrypted message: " << decryptedMessage << endl;
}

// Convert decimal to binary string
string decToBinary(int n) {
    string s, y; // Binary string and result
    while (n > 0) {
        s = s + char(n % 2 + int('0')); // Append binary digit
        n = n / 2; // Get next digit
    }
    while (s.size() < 5) {
        s = s + '0'; // Add leading zeros
    }
    reverse(s.begin(), s.end()); // Reverse binary string
    for (char r : s) {
        if (r == '0') {
            y = y + 'a'; // Convert to 'a' or 'b'
        } else {
            y = y + 'b';
        }
    }
    return y; // Return result
}

// Convert binary to decimal integer
int binaryToDecimal(int n) {
    int num = n; // Store binary number
    int dec_value = 0; // Initialize decimal value
    int base = 1; // Initialize base value
    int temp = num; // Temporary binary number
    while (temp) {
        int last_digit = temp % 10; // Extract last digit
        temp = temp / 10; // Remove last digit
        dec_value += last_digit * base; // Convert and add to decimal value
        base = base * 2; // Update base
    }
    return dec_value; // Return decimal value
}

// Function to implement Baconian Cipher
void Baconian_Cipher(){
    string s, q, output; // Input message, processed message, and output
    int x; // Variable to store ASCII value of character
    cout<<"Enter the message to cipher: "<<endl; // Prompt for input
    cin.ignore(); // Ignore previous newline character
    getline(cin,s); // Read input message
    // Process input: convert to uppercase, remove non-alphabetic characters
    for (char v: s) {
        if (isalpha(v)) {
            q += char(toupper(v)); // Convert to uppercase and append to processed message
        }
    }
    // Convert each character to binary using Baconian encoding
    for (char v: q) {
        x = int(v) - 65; // Convert character to ASCII value and adjust to range 0-25
        output += decToBinary(x); // Convert ASCII value to binary and append to output
    }
    cout<<"The ciphered message is: "<<output<<endl; // Print the ciphered message
}

// Function to decipher a message encoded using Baconian Cipher
void Baconian_Decipher(){
    string s, q, w, r, output; // Input message, processed message, substrings, binary string, and output
    bool check = true; // Flag to check input validity
    cout<<"Enter the message to decipher: "<<endl; // Prompt for input
    cin.ignore(); // Ignore previous newline character
    getline(cin,s); // Read input message
    // Process input: convert to lowercase, remove non-alphabetic characters
    for (char v: s) {
        if (isalpha(v)) {
            q += char(tolower(v)); // Convert to lowercase and append to processed message
        }
    }
    // Check if the processed message contains only 'a' and 'b' and has length multiple of 5
    for (char v: q) {
        if (v != 'a' and v != 'b') {
            check = false; // If non-'a'/'b' character found, set flag to false
            break; // Exit loop
        }
    }
    if (q.size() % 5 != 0) { // Check if length is not multiple of 5
        check = false; // If not, set flag to false
    }
    // Repeat until a valid input is provided
    while(!check) {
        check = true; // Reset flag
        cout<<"Invalid input. Please re-enter the message to decipher: "<<endl; // Prompt for correct input
        getline(cin,s); // Read input message
        q = ""; // Clear processed message
        for (char u: s) {
            if (isalpha(u)) {
                q += char(tolower(u)); // Convert to lowercase and append to processed message
            }
        }
        // Check if the processed message contains only 'a' and 'b' and has length multiple of 5
        for (char t: q) {
            if (t != 'a' and t != 'b') {
                check = false; // If non-'a'/'b' character found, set flag to false
                break; // Exit loop
            }
        }
        if (q.size() % 5 != 0) { // Check if length is not multiple of 5
            check = false; // If not, set flag to false
        }
    }
    // Decipher the message by converting binary strings to characters
    for (int i = 0; i < q.size(); i = i + 5) {
        w = q.substr(i,5); // Extract a substring of length 5
        for (char v: w) {
            if (v == 'a'){
                r = r + '0'; // If 'a', append '0' to binary string
            }
            else {
                r = r + '1'; // If 'b', append '1' to binary string
            }
        }
        output = output + char(binaryToDecimal(stoi(r)) + 65); // Convert binary string to character and append to output
        w = r = ""; // Clear substrings
    }
    cout<<"The original message is: "<<output<<endl; // Print the original message
}

// Function to cipher a message using Morse Code
void Morse_Code_Cipher(){

    // Array of Morse codes for each letter of the alphabet
    string morseCodes[26] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",
                             ".---", "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                             "...",  "-",    "..-",  "...-", ".--",  "-..-", "-.--", "--.."};

    string s, q, output; // Input message, processed message, and output
    int x; // Variable for ASCII value of character

    cout<<"Enter the message to cipher: "<<endl; // Prompt for input
    cin.ignore();
    getline(cin,s); // Read input message

    for (char v:s) {
        if (v==' ') {
            q = q + "  "; // Double space indicates word boundary in Morse code
        }
        if (isalpha(v)){
            q=q+char(toupper(v)); // Convert to uppercase and append to processed message
        }
    }

    // Convert each letter to its Morse code equivalent
    for (char v:q) {
        if(v==' '){
            output=output+' '; // If space, append space to output
        }
        if (isalpha(v)){
            output=output+morseCodes[int(v-65)]+' '; // Convert letter to Morse code and append to output
        }
    }

    cout<<"The ciphered message is: "<<output<<endl; // Print the ciphered message
}

// Function to decipher a message encoded in Morse Code
void Morse_Code_Decipher(){

    // Array of characters corresponding to each Morse code
    string characters[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                             "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    // Array of Morse codes for each letter of the alphabet
    string morseCodes[26] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",
                             ".---", "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                             "...",  "-",    "..-",  "...-", ".--",  "-..-", "-.--", "--.."};

    string s; // Input message in Morse Code

    cout<<"Enter the message to decipher: "<<endl; // Prompt for input
    cin.ignore();
    getline(cin,s); // Read input message

    stringstream textStream; // Stream to hold deciphered text
    string currentMorse; // Variable to hold current Morse code
    stringstream morseStream(s); // Stream to iterate through Morse Code message

    // Iterate through Morse Code message and convert each Morse code to its corresponding character
    while (morseStream >> currentMorse) {
        for (int i = 0; i < 26; ++i) {
            if (morseCodes[i] == currentMorse) {
                textStream << characters[i]; // Append corresponding character to text stream
                break;
            }
        }
    }

    cout<<"The original message is: "<<textStream.str(); // Print the original message
}

// Function to perform Rail Fence cipher encryption or decryption based on the choice provided
void Rail_fence(int choice) {
    int key;
    string s;

    // Ignore any previous input
    cin.ignore();

    // Perform encryption
    if (choice == 1) {
        cout << "Please enter the message to cipher : " << endl;
        getline(cin, s);
        // Calculate the size of the message excluding spaces
        int size = s.size() - count(all(s), ' ');
        // Remove spaces from the message
        remove(all(s), ' ');

        cout << "Please enter the Key : ";
        cin >> key;

        // Validate the key
        while (!(key <= size / 2)) {
            cout << "Please enter a valid Key : ";
            cin >> key;
        }

        // Vector to store rail fence pattern
        vector<string> v(key, "");

        // Initialize variables for traversing the rail fence
        int x = 0;
        bool flag = 1;

        // Fill the rail fence pattern
        for (int i = 0; i < size; i++) {
            v[x] += s[i];
            if (flag)
                x++;
            else
                x--;
            if (x == 0 || x == key - 1)
                flag = !flag;
        }

        // Output the cipher text
        cout << "Cipher text : ";
        for (int i = 0; i < key; i++) {
            cout << v[i];
        }
        cout << endl;
    }
    // Perform decryption
    else if (choice == 2) {
        cout << "Please enter the cipher text : " << endl;
        cin >> s;
        cout << "Please enter the Key : ";
        cin >> key;

        // Validate the key
        while (!(key <= s.size() / 2)) {
            cout << "Please enter a valid Key : ";
            cin >> key;
        }

        // Vector to represent the rail fence pattern
        vector<vector<char>> v(key, vector<char>(s.size(), '.'));

        string ans = "";
        bool flag = 0;
        int x = 0, y = 0;

        // Fill the rail fence pattern with spaces to represent the position of characters
        for (int i = 0; i < s.size(); i++) {
            if (x == 0)
                flag = 1;
            else if (x == key - 1)
                flag = 0;
            v[x][y] = ' ';
            y++;
            if (flag)
                x++;
            else
                x--;
        }

        // Fill the rail fence pattern with characters
        int position = 0;
        for (int i = 0; i < key; i++) {
            for (int j = 0; j < s.size(); j++) {
                if (v[i][j] == ' ') {
                    if (position < s.size()) {
                        v[i][j] = s[position];
                        position++;
                    }
                }
            }
        }

        x = 0; y = 0;
        for (int i = 0; i < s.size(); i++) {
            if (x == 0)
                flag = 1;
            else if (x == key - 1)
                flag = 0;
            if (v[x][y] != '.')
                ans += v[x][y++];
            if (flag)
                x++;
            else
                x--;
        }
        // Output the decrypted message
        cout << "Cipher text is : " << ans << endl;
    }
}

// Function to perform simple substitution encryption or decryption based on the given operation
void Simple_Substitution(int op) {
    if (op == 1) { // If operation is encryption
        string letters = "abcdefghijklmnopqrstuvwxyz"; // Define alphabet
        string plain; // Declare variable to store plain text
        string key; // Declare variable to store encryption key

        cout << "enter the key :"; // Prompt user to enter encryption key
        cin >> key; // Read encryption key from user input
        cout << "enter the plain text :"; // Prompt user to enter plain text
        cin.ignore(); // Ignore newline character left in the input buffer
        getline(cin, plain); // Read plain text including spaces

        // Remove characters in the key from the alphabet
        for (int i = 0; i < key.size(); i++) {
            letters.erase(letters.begin() + letters.find(key[i]));
        }
        letters = key + letters; // Append the key to the modified alphabet

        string res = ""; // Initialize variable to store cipher text

        // Iterate over each character in the plain text
        for (int i = 0; i < plain.size(); i++) {
            if (isalpha(plain[i])) { // If the character is alphabetic
                res += letters[tolower(plain[i]) - 'a']; // Substitute the character with its corresponding cipher letter
            }
            else res += plain[i]; // If the character is not alphabetic, append it unchanged
        }
        cout << "cipher text :" << res << endl;; // Output the resulting cipher text
    }
    else if (op == 2) { // If operation is decryption
        string letters = "abcdefghijklmnopqrstuvwxyz"; // Define alphabet
        string cipher; // Declare variable to store cipher text
        string key; // Declare variable to store encryption key

        cout << "enter the key :"; // Prompt user to enter encryption key
        cin >> key; // Read encryption key from user input
        cout << "enter the cipher text :"; // Prompt user to enter cipher text
        cin.ignore(); // Ignore newline character left in the input buffer
        getline(cin, cipher); // Read cipher text including spaces

        // Remove characters in the key from the alphabet
        for (int i = 0; i < key.size(); i++) {
            letters.erase(letters.begin() + letters.find(key[i]));
        }
        letters = key + letters; // Append the key to the modified alphabet

        string res = ""; // Initialize variable to store plain text

        // Iterate over each character in the cipher text
        for (int i = 0; i < cipher.size(); i++) {
            if (isalpha(cipher[i])) { // If the character is alphabetic
                // Substitute the character with its corresponding plain letter
                res += letters.find(tolower(cipher[i])) + 'a';
            }
            else res += cipher[i]; // If the character is not alphabetic, append it unchanged
        }
        cout << "plain text :" << res << endl; // Output the resulting plain text
    }
}

// Function to perform XOR encryption or decryption based on the given operation
void xor_cipher(int n) {
    string msg, key; // Declare variables to store message and key
    stringstream ss; // Declare stringstream for converting hex string to characters

    if (n == 1) { // If operation is encryption
        cout << "enter the plain text : ";
        cin.ignore();
        getline(cin, msg); // Input plain text
        cout << "enter the key : ";
        cin >> key; // Input encryption key

        // Repeat the key to match the length of the message
        int keyindex = 0;
        while (key.size() < msg.size()) {
            key += key[keyindex];
            keyindex %= key.size();
            keyindex++;
        }

        string res = ""; // Initialize variable to store encrypted text
        for (int i = 0; i < msg.size(); i++) {
            // Perform XOR operation between each character of the message and key
            res += (char)(msg[i] ^ key[i]);
        }

        // Output the encrypted text
        cout << "Encrypted text : " << res << endl;

        // Convert encrypted text to hexadecimal representation
        cout << endl<<"Hexa : ";
        for (char c : res) {
            ss << hex << setw(2) << setfill('0') << static_cast<int>(c);
        }
        cout << ss.str()<<endl; // Output the hexadecimal representation
    }
    else if(n==2) { // If operation is decryption
        cout << "enter the cipher hexa : ";
        cin.ignore();
        getline(cin, msg); // Input hexadecimal representation of cipher text
        cout << "enter the key : ";
        cin >> key; // Input decryption key

        // Repeat the key to match the length of the message
        int keyindex = 0;
        while (key.size() < msg.size()) {
            key += key[keyindex];
            keyindex %= key.size();
            keyindex++;
        }

        // Convert hexadecimal string to characters
        for (int i = 0; i < msg.length(); i += 2) {
            string byteStr = msg.substr(i, 2); // Get two characters at a time
            char byte = static_cast<char>(stoi(byteStr, nullptr, 16)); // Convert hexadecimal to integer
            ss << byte; // Append the character to the stringstream
        }
        msg = ss.str(); // Convert stringstream to string containing characters

        string res = ""; // Initialize variable to store decrypted text
        for (int i = 0; i < msg.size(); i++) {
            // Perform XOR operation between each character of the message and key
            res += (char)(msg[i] ^ key[i]);
        }

        // Output the decrypted text
        cout << "plain text : " << res;
    }
}
