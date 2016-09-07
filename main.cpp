//
//  main.cpp
//  codeclone
//
//  Created by Ryan Finlay on 31/08/2016.
//  Copyright © 2016 sgde. All rights reserved.
//

#include <iostream>
#include <string>
#include "Tokeniser.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Tokeniser tokeniser;
    
    char fileptr[] = "test.cpp";
    
    tokeniser.getTokens(fileptr);
    return 0;
}
