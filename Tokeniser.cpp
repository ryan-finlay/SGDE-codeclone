//
//  Tokeniser.cpp
//  codeclone
//
//  Created by Ryan Finlay on 31/08/2016.
//  Copyright © 2016 sgde. All rights reserved.
//

#include "Tokeniser.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


Tokeniser::Tokeniser(){
    
}

Tokeniser::~Tokeniser(){
    
}

/*
 *  getTokens - turns a file into a vector of all the lines in that file with the whitespace and comments removed
 *  params - string of a file in the same directory (probably going to change to some other way)
 *  returns - vector of all the tokens
 */

vector<string> Tokeniser::getTokens(char* file){
    
    //clear the previous tokens
    tokens.erase(tokens.begin(), tokens.end());
    
    //add the new tokens in line by line
    ifstream fptr(file);
    string line;
   
    while(getline(fptr,line)){
        tokens.push_back(line); //push to back of tokens vector
        
    }
    fptr.close();
    
    removeWhitespace();
    removeComments();
    removeEmptyLines();
    
    
    return tokens;
}


void Tokeniser::removeComments(){
    string currToken;
    string temp;
    size_t pos;
    bool block = false;
    
    
    for(int i = 0; i < tokens.size() ; i++){
        currToken = tokens[i];
        
        //removal of multiline comments
        
        //if a continuing block comment from the previous line
        if(block){
            pos = currToken.find("*/");
            
            if(pos != string::npos){    //if found
                currToken = currToken.substr(pos+2); //the string after the block comment
                block = false;
            }
            else{
                currToken.clear(); // clear the line if a continuing block comment
            }
        }
        
        //find a block comment
        pos = currToken.find("/*");
        
        if(pos != string::npos){    //if found
            temp = currToken.substr(0,pos);//the string before the block comment
            
            
            //look for the end in that line
            pos = currToken.find("*/",pos+1);
            
            if (pos != string::npos) {  //if found
                temp += currToken.substr(pos+2); //the string after the block comment
            }
            else{
                block = true; //set the next line is a continuing block comment
            }
            
            currToken = temp;
        }
        
        
        //removal of single line comments
        pos = currToken.find("//");
        
        if(pos != string::npos){
            currToken = currToken.substr(0,pos);
        }
        
        tokens[i] = currToken;
    }
}

void Tokeniser::removeWhitespace(){
    string currToken;
    for(int i = 0; i < tokens.size() ; i++){
        currToken = tokens[i];
        //remove if whitespace
        currToken.erase(remove_if(currToken.begin(), currToken.end(), ::isspace),currToken.end());
        
        //remove all the end of line chars
        while(currToken[currToken.size()-1] == '\r' || currToken[currToken.size()-1] == '\n'){
            currToken.erase(currToken.size()-1);
        }
        tokens[i] = currToken;
    }
}

void Tokeniser::removeEmptyLines(){
    vector<string> temp;
    
    for(int i = 0; i < tokens.size() ; i++){
        //if empty skip
        if(tokens[i].empty()){
            continue;
        }
        //otherwise push to the back of the new tokens
        temp.push_back(tokens[i]);
    }
    //update the tokens
    tokens = temp;
}
