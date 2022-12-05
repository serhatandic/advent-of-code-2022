#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
void moveTheCrates(vector<vector<char>> refactoredInput, vector<string> input);
int main(){
    vector<string>  inp = {};
    vector<vector<char>> refactoredInp = {};

    fstream newfile;
    newfile.open("input.txt",ios::in);
    if (newfile.is_open()){
      string tp;
      while(getline(newfile, tp)){
        inp.push_back(tp);
      }}

    newfile.close();

    for (int i = 0; i < 9; i++){
        refactoredInp.push_back({});
    }
    for (int i = 0; i < 8; i++){
        vector<char> temp;
        for(int j = 1; j < inp[i].length(); j+=4){
            temp.push_back(inp[i][j]);
        }
        for (int j = 0; j < temp.size(); j++){
            if(temp[j] != ' '){
                refactoredInp[j].push_back(temp[j]);
            }
        }
    }

    moveTheCrates(refactoredInp, inp);
    return 1;
};

void moveTheCrates(vector<vector<char>> refactoredInput, vector<string> input){
    int howMany, from, to;

    for (int i = 10; i < input.size(); i++){

        int moveNumBegin = input[i].find("move") + 5;
        int moveNumEnd = input[i].find("from") -1;

        int fromNumBegin = input[i].find("from") + 5;
        int fromNumEnd = input[i].find("to") -1;

        int toNumBegin = input[i].find("to")+3;
        int toNumEnd = input[i].length();

        howMany = stoi(input[i].substr(moveNumBegin, moveNumEnd - moveNumBegin));
        from = stoi(input[i].substr(fromNumBegin, fromNumEnd - fromNumBegin));
        to = stoi(input[i].substr(toNumBegin, toNumEnd - toNumBegin));

        for (int j = 0; j < howMany; j++){
            refactoredInput[to - 1].insert(refactoredInput[to - 1].begin(), refactoredInput[from - 1][0]);
            refactoredInput[from - 1].erase(refactoredInput[from - 1].begin());
        }
    }

    for (int i = 0; i < refactoredInput.size(); i++){
        cout << refactoredInput[i][0] ;
    }
    cout << endl;
}
