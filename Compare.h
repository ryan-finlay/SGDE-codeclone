#ifndef Compare_h
#define Compare_h

#include <string>
#include <vector>
#include <iostream>

class Compare {
private:
    size_t uiLevenshteinDistance(const std::string &s1, const std::string &s2);
	
public:
	std::vector<int> clones(std::vector<std::string> tokens1, std::vector<std::string> tokens2);
    std::vector<int> partClones(std::vector<std::string> tokens1, std::vector<std::string> tokens2);
	void print(char* file1, char* file2,std::vector<std::string> tokens1, std::vector<std::string> tokens2, std::vector<int> results);
	
};

#endif
