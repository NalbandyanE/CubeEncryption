#include "decoder.h"
#include <iostream>
#include <vector>

Decoder::Decoder() = default;

Decoder::Decoder(const std::string& et, const std::string& k) : encodedText{et}, key{k} {}

void Decoder::setEncodedText(const std::string& et) {
	encodedText = et;
}

std::string Decoder::getEncodedText() const {
	return encodedText;
}

void Decoder::setKey(const std::string& k) {
	key = k;
}

std::string Decoder::getKey() const {
	return key;
}

void Decoder::decode(Encoder& encoder) {
    	std::vector<std::string> keyParts = encoder.splitString(key, ':');
    	std::string decodedText;
    	for (size_t i = 0; i < keyParts.size(); ++i) {
        	std::vector<std::string> subParts = encoder.splitString(keyParts[i], ',');
        	bool reverseRotation = (i == keyParts.size() - 1);
        	for (size_t j = 0; j < subParts.size(); ++j) {
            		char direction = subParts[j][0];
            		int rotationCount = std::stoi(subParts[j].substr(1));
            		if (direction == 'U') 
            		{
                		encoder.getCubes()[i].rotateDown(rotationCount);
            		} 
            		else if (direction == 'D') {
                		if (reverseRotation) {
                    			encoder.getCubes()[i].rotateUp(rotationCount);
                		} 
                		else {
                   	 		encoder.getCubes()[i].rotateDown(rotationCount);
                		}
            		} 
            		else if (direction == 'L') {
                		encoder.getCubes()[i].rotateRight(rotationCount);
            		} 
            		else if (direction == 'R') {
                		encoder.getCubes()[i].rotateLeft(rotationCount);
            		}
        	}
        	decodedText += encoder.getCubes()[i].getCube();
    	}
    	setEncodedText(decodedText);
}
