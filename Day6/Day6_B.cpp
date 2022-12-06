#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int findTheMarker (string input);
bool containsDuplicate (string input);

int main(){
    vector<string>  inp = {};

    fstream newfile;
    newfile.open("input.txt",ios::in);
    if (newfile.is_open()){
      string tp;
      while(getline(newfile, tp)){
        inp.push_back(tp);
      }}

    newfile.close();
    cout << findTheMarker(inp[0]) << endl;
    return 1;
};

int findTheMarker (string input){
    for (int i = 0; i < input.length(); i++){
        if (!containsDuplicate(input.substr(i, 14))){{
            return i+14;
        }
        }
    }
    return -1;
}

bool containsDuplicate (string input){
    for(int i = 0; i < input.length(); i++){
        for (int j = i+1; j < input.length(); j++){
            if(input[i] == input[j]){
                return true;
            }
        }
    }
    return false;
}