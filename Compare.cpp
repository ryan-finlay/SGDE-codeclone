#include "Compare.h"
#include <iostream>
#define CLONE_LENGTH 5
using namespace std;


// Compute Levenshtein Distance
// Martin Ettl, 2012-10-05

size_t Compare::uiLevenshteinDistance(const std::string &s1, const std::string &s2)
{
    const size_t m(s1.size());
    const size_t n(s2.size());
    
    if( m==0 ) return n;
    if( n==0 ) return m;
    
    size_t *costs = new size_t[n + 1];
    
    for( size_t k=0; k<=n; k++ ) costs[k] = k;
    
    size_t i = 0;
    for ( std::string::const_iterator it1 = s1.begin(); it1 != s1.end(); ++it1, ++i )
    {
        costs[0] = i+1;
        size_t corner = i;
        
        size_t j = 0;
        for ( std::string::const_iterator it2 = s2.begin(); it2 != s2.end(); ++it2, ++j )
        {
            size_t upper = costs[j+1];
            if( *it1 == *it2 )
            {
                costs[j+1] = corner;
            }
            else
            {
                size_t t(upper<corner?upper:corner);
                costs[j+1] = (costs[j]<t?costs[j]:t)+1;
            }
            
            corner = upper;
        }
    }
    
    size_t result = costs[n];
    delete [] costs;
    
    return result;
}



vector<int> Compare::clones(vector<string> tokens1, vector<string> tokens2) {
	
	vector<int> results; //four ints per pair of clones: start of clone from file 1, end of clone from file 1, start of 2, end of 2
	
	for(int i = 0;i<tokens1.size();i++) {
		for(int j = 0;j<tokens2.size();j++) {
			if(tokens1[i]==tokens2[j]) {
				int ni = i;
				int nj = j;
				while(ni<tokens1.size()&&nj<tokens2.size()&&tokens1[ni]==tokens2[nj]) {
					ni++;
					nj++;
				}
				if(ni-i>=CLONE_LENGTH) {
					bool copy = false;
					for(int k = 1;k<results.size();k+=4) {
						if(ni==results[k]&&nj==results[k+2]) copy = true;
					}
					if(copy==false) {
						results.push_back(i);
						results.push_back(ni);
						results.push_back(j);
						results.push_back(nj);
					}
				}
			}
		}
	}
	/*for(int i = 0;i<results.size();i++) {
		cout << results[i] << ":";
	}
	cout << endl;*/
	return results;
	
}



vector<int> Compare::partClones(vector<string> tokens1, vector<string> tokens2){
    
    int f1 = 0;
    int f2 = 0;
    string str1;
    string str2;
    vector<int> results;
    
    
    while (f1 < tokens1.size()-5) {
        while (f2 < tokens2.size()-5) {
            
            str1 = tokens1[f1] + tokens1[f1+1] + tokens1[f1+2] + tokens1[f1+3] + tokens1[f1+4];
            str2 = tokens2[f2] + tokens2[f2+1] + tokens2[f2+2] + tokens2[f2+3] + tokens2[f2+4];
            
            size_t changes = uiLevenshteinDistance(str1, str2);
            
            int percentage;
            
            if(str1.length() >= str2.length()){
                percentage = (changes/(float)str1.length())*100;
            }
            else{
                percentage = (changes/(float)str2.length())*100;
            }
            
            if(percentage <= 20){
                results.push_back(f1);
                results.push_back(f1+4);
                results.push_back(f2);
                results.push_back(f2+4);
                
                f2 += 5;
                continue;
            }
            
            f2++;
        }
        f1+= 5;
        f2=0;
    }
    
    return results;
}




void Compare::print(char* file1, char* file2, vector<string> tokens1, vector<string> tokens2, vector<int> results) {
    if(results.size()==0) return;
    cout << "Comparing " << file1 << " and " << file2 << "..." << endl;
	cout << results.size()/4 << " clones found" << endl;
   
	for(int i = 0;i<results.size();i+=4) {
		cout << endl;
		cout << "Clone from file 1:" << endl;
		for(int k = results[i];k<results[i+1];k++) {
			cout << tokens1[k] << endl;
		}
		cout << endl;
		cout << "Clone from file 2:" << endl;
		for(int k = results[i+2];k<results[i+3];k++) {
			cout << tokens2[k] << endl;
		}
	}
    cout << endl;
}
