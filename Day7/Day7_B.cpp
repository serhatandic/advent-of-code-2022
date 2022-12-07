#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <limits.h>

using namespace std;
int sumDirectorySizes (vector<string> inp);

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
    cout << sumDirectorySizes(inp) << endl;
    return 1;
};

int sumDirectorySizes (vector<string> inp){
    int sum = 0, min = INT32_MAX;
    map<vector<string>,int> myMap;
    vector<string> path, tempPath;

    for (int i = 0; i < inp.size(); i++){
        if(inp[i].find("$ cd") != string::npos){
            if (inp[i].find("$ cd ..") != string::npos){
                path.pop_back();
            }else{
                path.push_back(inp[i].substr(4, inp[i].size() - 4));
            }
        }else if (inp[i].find("dir") != string::npos){
            continue;
        }else if (inp[i].find("$") != string::npos){
            continue;
        }else{
            for (int k = 0; k < path.size(); k++){
                tempPath.push_back(path[k]);
                myMap[tempPath] += stoi(inp[i].substr(0, inp[i].find(" ")));
            }
        tempPath.clear();
        }
    }
    for (auto i : myMap){    
        
        if ((70000000 - 43636666) + i.second >= 30000000){
            if (i.second < min){
                min = i.second;
            }
        }
    }
    return min;
}


