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
#include "Compare.cpp"

using namespace std;

int main(int argc, char * argv[]) {
	
	if(argc<3) {
		cout << "Not enough files" << endl;
	}
	else {
		for(int i = 1;i<argc;i++) {
			for(int k = i+1;k<argc;k++) {
				Tokeniser tokeniser;
				Compare compare;
				cout << "Comparing " << argv[i] << " and " << argv[k] << "..." << endl;
				vector<string> ret = tokeniser.getTokens(argv[i]);
				vector<string> ret2 = tokeniser.getTokens(argv[k]);
				compare.print(ret,ret2,compare.clones(ret,ret2));
				cout << endl;
			}
		}
	}
   
	/*if(argc==3) { 
		
		
		//char fileptr[] = "test.cpp";
		//char fileptr2[] = "test2.cpp";
		
		vector<string> ret = tokeniser.getTokens(argv[1]);
		vector<string> ret2 = tokeniser.getTokens(argv[2]);
		compare.print(ret,ret2,compare.clones(ret,ret2));
    }
	else {
		cout << "Incorrect input" << endl;
	}*/
    
    return 0;
}
