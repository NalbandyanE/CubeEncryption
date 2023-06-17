#include "encoder.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>

Encoder::Encoder() = default;

Encoder::Encoder(const std::string& input) {
	inputString = input;
	int n = input.size();
    int cubeSize = 8;
    int cubesCount = (n + cubeSize - 1) / cubeSize;

    for (int i = 0; i < cubesCount; ++i) {
        int startPos = i * cubeSize;
        int length = std::min(cubeSize, n - startPos);
        std::string cubeString = input.substr(startPos, length);

        if (length < cubeSize) {
            cubeString += std::string(cubeSize - length, '\0'); 
        }

        Cube cube(cubeString);
        cubes.push_back(cube);
    }
}

void Encoder::setCubes(const std::vector<Cube>& c) {
	cubes = c;
}

std::vector<Cube> Encoder::getCubes() const {
	return cubes;
}

void Encoder::printCubes() const {
	for (int i = 0; i < cubes.size(); ++i) {
		std::cout << cubes[i].getCube() << " ";
	}
	std::cout << std::endl;
}

std::string Encoder::generateKey() {
	std::string key;
	srand(static_cast<unsigned int>(time(0)));
    for (const Cube& cube : cubes) {
    	int u = rand() % 10;
        int d = rand() % 10;
        int l = rand() % 10;
        int r = rand() % 10;
        std::string cubeKey;
        cubeKey += 'U' + std::to_string(u);
        cubeKey += 'D' + std::to_string(d);
        cubeKey += 'L' + std::to_string(l);
        cubeKey += 'R' + std::to_string(r); 
        if (!key.empty()) {
            key += ":";
        }  
        key += cubeKey;
    }
    return key;
}

std::vector<std::string> Encoder::splitString(const std::string& str, char delimiter) {
    std::vector<std::string> parts;
    std::stringstream ss(str);
    std::string part;
    while (std::getline(ss, part, delimiter)) {
        parts.push_back(part);
    }
    return parts;
}

std::string Encoder::encodedText() {
    std::vector<std::string> keyParts = splitString(generateKey(), ':');
    std::string encoded = "";
    for (size_t i = 0; i < keyParts.size(); ++i) {
        Cube tempCube = getCubes()[i]; 
        std::vector<std::string> subParts = splitString(keyParts[i], ',');
        for (size_t j = 0; j < subParts.size(); ++j) {
            char direction = subParts[j][0];
            int rotationCount = std::stoi(subParts[j].substr(1));
            if (direction == 'U') {
                tempCube.rotateUp(rotationCount);
            } 
            else if (direction == 'D') {
                tempCube.rotateDown(rotationCount);
            } 
            else if (direction == 'L') {
                tempCube.rotateLeft(rotationCount);
            } 
            else if (direction == 'R') {
                tempCube.rotateRight(rotationCount);
            }
        }
        encoded += tempCube.getCube();
    }
    return encoded;
}