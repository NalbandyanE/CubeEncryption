#include "decoder.h"
#include <iostream>

int main() {
	Encoder encoder("hello, dear students");
	encoder.printCubes();
	std::cout << "Generated key: " << encoder.generateKey() << std::endl;
	std::cout << "Encoded text: " << encoder.encodedText() << std::endl;
	Decoder decoder(encoder.encodedText(), encoder.generateKey());
	decoder.decode(encoder);
	std::string decodedText = decoder.getEncodedText();
	std::cout << "Decoded text: " << decodedText << std::endl;

	return 0;
}