#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <string>

class Cube {
public:
	Cube();
	Cube(const std::string&);
	void setCube(const std::string&);
	std::string getCube() const;
	void rotateUp(int);
	void rotateDown(int);
	void rotateLeft(int);
	void rotateRight(int);
private:
	std::string cube;
};

#endif