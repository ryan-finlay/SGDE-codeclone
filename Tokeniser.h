//
//  Tokeniser.h
//  codeclone
//
//  Created by Ryan Finlay on 31/08/2016.
//  Copyright © 2016 sgde. All rights reserved.
//

#ifndef Tokeniser_h
#define Tokeniser_h

#include <string>
#include <vector>
#include <iostream>

class Tokeniser {
private:
    std::vector<std::string> tokens; //vector of all the tokens
    void removeWhitespace();
    void removeComments();
    void removeEmptyLines();
    void removeIncludes();
    
    
public:
    std::vector<std::string> getTokens(char* file);
    Tokeniser();
    ~Tokeniser();
};

#endif /* Tokeniser_h */
