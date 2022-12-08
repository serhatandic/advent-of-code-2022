#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;
int findVisibleTrees(vector<string> inp);

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
    cout << findVisibleTrees(inp) << endl;
    return 1;
};

int findVisibleTrees(vector<string> inp){
    int score = 0;
    int leftTrees = 0, rightTrees = 0, topTrees = 0, bottomTrees = 0;

    for (int i = 1; i < inp.size() - 1; i++){
        for (int j = 1; j < inp[i].length() - 1; j++){
            int currentHeight = static_cast<int>(inp[i][j]);

            for (int k = j-1; k >= 0; k--){
                if (k == 0 || static_cast<int>(inp[i][k]) >= currentHeight ){
                    leftTrees = j - k;
                    break;
                }
                
            }

            for (int k = j+1; k < inp[i].length(); k++){
                if (k == inp[i].length() - 1 || static_cast<int>(inp[i][k]) >= currentHeight ){
                    rightTrees = k - j;
                    break;
                }
            }

            for (int k = i-1; k >= 0; k--){
                if (k == 0 || static_cast<int>(inp[k][j]) >= currentHeight ){
                    topTrees = i - k;
                    break;
                }
            }

            for (int k = i+1; k < inp.size(); k++){
                if (k == inp.size() - 1 || static_cast<int>(inp[k][j]) >= currentHeight ){
                    bottomTrees =  k-i;
                    break;
                }
            }
            cout << leftTrees << rightTrees << topTrees << bottomTrees << endl;
            score = std::max(score, leftTrees * rightTrees * topTrees * bottomTrees);
            topTrees = 0;
            bottomTrees = 0;
            leftTrees = 0;
            rightTrees = 0;
         
         }
    }

    return score;
}