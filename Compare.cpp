#include "Compare.h"
#define CLONE_LENGTH 5
using namespace std;

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

void Compare::print(vector<string> tokens1, vector<string> tokens2, vector<int> results) {
	if(results.size()==0) cout << "No clones" << endl;
	else cout << results.size()/4 << " clones found" << endl;
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
}