#ifndef Compare_h
#define Compare_h

#include <string>
#include <vector>
#include <iostream>

class Compare {
	
	public:
	std::vector<int> clones(std::vector<std::string> tokens1, std::vector<std::string> tokens2);
	void print(std::vector<std::string> tokens1, std::vector<std::string> tokens2, std::vector<int> results);
	
};

#endif