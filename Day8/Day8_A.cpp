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
    int sum = 0;
    int trivials = inp.size()*2;
    bool leftFlag = true, rightFlag = true, topFlag = true, bottomFlag = true;
    trivials += (inp[0].length()-2)*2;

    for (int i = 1; i < inp.size() - 1; i++){
        for (int j = 1; j < inp[i].length() - 1; j++){
            int currentHeight = static_cast<int>(inp[i][j]);
            for (int k = 0; k < inp[i].length(); k++){
                if (k < j){
                    if (static_cast<int>(inp[i][k]) >= currentHeight){
                        leftFlag = false;
                    }
                }

                if (k > j){
                    if (static_cast<int>(inp[i][k]) >= currentHeight){
                        rightFlag = false;
                    }
                }
            }

            for (int k = 0; k < inp.size(); k++){
                if (k < i){
                    if (static_cast<int>(inp[k][j]) >= currentHeight){
                        topFlag = false;
                    }
                }

                if (k > i){
                    if (static_cast<int>(inp[k][j]) >= currentHeight){
                        bottomFlag = false;
                    }
                }
            }

            if (leftFlag || rightFlag || topFlag || bottomFlag){
                sum+=1;        
            }

            leftFlag = true;
            rightFlag = true;
            topFlag = true;
            bottomFlag = true;
         }
    }

    return sum + trivials;
}