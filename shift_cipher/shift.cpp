#include <iostream> // std::cout
#include <string> // std::string

/*
 * Shift cipher (or Ceasar Cipher) makes a N shifts in the alphabet.
 * Assuming 26 letters, we have a Z26 ring.
 */


/*
 * getChar returns the char letter in alphabet with the modulo's position 
 * in the ring
 */
char getChar(int n)
{
	char a = 'a';
	int n_ = n % 26;
	if (n_ < 0) n_ += 26; // It's necessary because e.i. -1 % 26 = -1. (In Python it works better)
	return a+n_;
}

/*
 * Crypter() does the shift right letter key times, generating the cipher text from
 * the plain text
 */
void crypter(std::string *plain_text, int key)
{
	for (auto &letter: *plain_text) {
		letter = getChar((letter-97) + key); // the 'a' (first letter) is 97th char as integer
	}
}

/*
 * Decrypter() does the shift left, geting the plain text from ciphertext
 */
void decrypter(std::string *cipher_text, int key)
{
	for (auto &letter: *cipher_text) {
		int in_ring = letter - 97;
		letter = getChar(in_ring - key);
	}
}


int main(void)
{
	std::string text = "palavraz";
	int key = 3;
	// Encryption pass
	std::cout << ">>> Original plain text: " << text << std::endl;
	crypter(&text, key);
	std::cout << ">>>     Encryption function with key " << key << std::endl;
	std::cout << ">>> Generated cipher text: " << text << std::endl;
	// Decryption pass
	std::cout << ">>>     Decryption function with key " << key << std::endl;
	decrypter(&text, 3);
	std::cout << ">>> Decrypted plain text: " << text << std::endl;
	
	return EXIT_SUCCESS;
}
