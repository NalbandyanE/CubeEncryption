#ifndef ENCODER_H
#define ENCODER_H

#include "cube.h"
#include <string>

class Encoder {
public:
	Encoder();
	Encoder(const std::string&);
	void setCubes(const std::vector<Cube>&);
	std::vector<Cube> getCubes() const;
	void printCubes() const;
	std::string generateKey();
	std::string encodedText();
	std::vector<std::string> splitString(const std::string&, char);
private:
	std::string inputString;
	std::vector<Cube> cubes;
};

#endif