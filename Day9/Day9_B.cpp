#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

int myFunc (vector<string> inp);
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
    cout << myFunc(inp) << endl;
    return 1;
};

int myFunc (vector<string> inp){
    string direction;
    int numOfSteps;
    pair<int,int> coords;
    vector<pair<int,int>> coordsArr;

    pair<int,int> origin;
    origin.first = 0;
    origin.second = 0;

    vector<pair<int,int>> knotsArray;
    for (int i = 0; i < 10; i++){
        knotsArray.push_back(origin);
    }    

    bool left = true, right = true, down = true, up = true;
    string prevDirection;

    for (int i = 0; i < inp.size(); i++){
        direction = inp[i][0];
        numOfSteps = stoi(inp[i].substr(2, inp[i].size() -2));

        for (int j = 0; j < numOfSteps; j++){
            if (direction == "R"){
                knotsArray[0].second++;
            }
            else if (direction == "L"){
                knotsArray[0].second--;

            }else if (direction == "U"){
                knotsArray[0].first++;     

            }else if (direction == "D"){
                knotsArray[0].first--;
            }
            for (int k = 0; k < knotsArray.size() - 1; k++){
                if(abs(knotsArray[k].second - knotsArray[k+1].second) >=2 && abs(knotsArray[k].first - knotsArray[k+1].first) >=2){
                    if(knotsArray[k+1].first < knotsArray[k].first){
                        knotsArray[k+1].first = knotsArray[k].first -1;
                    }else{
                        knotsArray[k+1].first = knotsArray[k].first + 1;
                    }

                    if(knotsArray[k+1].second < knotsArray[k].second){
                        knotsArray[k+1].second = knotsArray[k].second -1;
                    }else{
                        knotsArray[k+1].second = knotsArray[k].second + 1;
                    }
                }else if (abs(knotsArray[k].first - knotsArray[k+1].first) >= 2){
                    if(knotsArray[k+1].first < knotsArray[k].first){
                        knotsArray[k+1].first = knotsArray[k].first - 1;
                    }else{
                        knotsArray[k+1].first = knotsArray[k].first + 1;
                    }
                    knotsArray[k+1].second = knotsArray[k].second;
                }
                
                else if(abs(knotsArray[k].second - knotsArray[k+1].second) >= 2){
                    if(knotsArray[k+1].second < knotsArray[k].second){
                        knotsArray[k+1].second = knotsArray[k].second - 1;
                    }else {
                        knotsArray[k+1].second = knotsArray[k].second + 1;
                    }

                    knotsArray[k+1].first = knotsArray[k].first; 
                }
                
                if(k == 8 && find(coordsArr.begin(), coordsArr.end(), knotsArray[9]) == coordsArr.end()){
                    coordsArr.push_back(knotsArray[9]);
                }
            }
            
            
        }
    }
    return coordsArr.size();
}

