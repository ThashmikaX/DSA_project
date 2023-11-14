#include <iostream>

using namespace std;

// Encrypts the given text using the given key.
string encrypt(string text, string key) {
  string encryptedText;
  for (int i = 0; i < text.length(); i++) {
    encryptedText += text[i] ^ key[i % key.length()];
  }
  return encryptedText;
}

// Decrypts the given encrypted text using the given key.
string decrypt(string encryptedText, string key) {
  string decryptedText;
  for (int i = 0; i < encryptedText.length(); i++) {
    decryptedText += encryptedText[i] ^ key[i % key.length()];
  }
  return decryptedText;
}

int main() {
  string text = "Viraj";
  string key = "password";

  // Encrypt the text.
  string encryptedText = encrypt(text, key);

  // Decrypt the encrypted text.
  string decryptedText = decrypt(encryptedText, key);

  // Print the encrypted and decrypted texts.
  cout << "Encrypted text: " << encryptedText << endl;
  cout << "Decrypted text: " << decryptedText << endl;

  return 0;
}




// Line 1: Includes the iostream header file, which is needed for input and output operations.
// Line 3: Uses the using namespace std statement to bring the contents of the std namespace into the current scope.
// Line 6: Defines the encrypt() function, which encrypts the given text using the given key.
// Line 7: Creates a string to store the encrypted text.
// Line 8: Iterates over each character of the text.
// Line 9: XORs the current character of the text with the corresponding character of the key.
// Line 10: If the key is shorter than the text, repeats the key from the beginning.
// Line 11: Returns the encrypted text.
// Line 14: Defines the decrypt() function, which decrypts the given encrypted text using the given key.
// Line 15: Creates a string to store the decrypted text.
// Line 16: Iterates over each character of the encrypted text.
// Line 17: XORs the current character of the encrypted text with the corresponding character of the key.
// Line 18: If the key is shorter than the encrypted text, repeats the key from the beginning.
// Line 19: Returns the decrypted text.
// Line 22: Defines the main() function, which is the entry point for the program.
// Line 23: Defines the text and key variables.
// Line 25: Encrypts the text.
// Line 27: Decrypts the encrypted text.
// Line 29: Prints the encrypted and decrypted texts.
// Line 31: Returns 0 from the program.