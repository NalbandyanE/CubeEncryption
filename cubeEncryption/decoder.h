#ifndef DECODER_H
#define DECODER_H

#include <string>
#include "encoder.h"

class Decoder {
public:
	Decoder();
	Decoder(const std::string&, const std::string&);
	void setEncodedText(const std::string&);
	std::string getEncodedText() const;
	void setKey(const std::string&);
	std::string getKey() const;
	void decode(Encoder&);
private:
	std::string encodedText;
	std::string key;
};

#endif