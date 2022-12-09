#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
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

    pair<int,int> currCoords;
    currCoords.first = 0;
    currCoords.second = 0;

    pair<int,int> headCoords;
    headCoords.first = 0;
    headCoords.second = 0;

    bool left = true, right = true, down = true, up = true;
    string prevDirection;

    for (int i = 0; i < inp.size(); i++){
        

        direction = inp[i][0];
        numOfSteps = stoi(inp[i].substr(2, inp[i].size() -2));

        for (int j = 0; j < numOfSteps; j++){
            if (direction == "R"){
                headCoords.second++;
                if(abs(headCoords.second - currCoords.second) > 1){
                    currCoords.first = headCoords.first;
                    currCoords.second++;
                }
                if(find(coordsArr.begin(), coordsArr.end(), currCoords) == coordsArr.end()){
                    coordsArr.push_back(currCoords);
                }
                
            }else if (direction == "U"){
                headCoords.first++;
                if (abs(headCoords.first - currCoords.first) > 1){
                    currCoords.second = headCoords.second;
                    currCoords.first++;
                }
                if(find(coordsArr.begin(), coordsArr.end(), currCoords) == coordsArr.end()){
                    coordsArr.push_back(currCoords);
                }
                
            }else if (direction == "L"){
                headCoords.second--;
                if(abs(headCoords.second - currCoords.second) > 1){
                    currCoords.first = headCoords.first;
                    currCoords.second--;
                }
                if(find(coordsArr.begin(), coordsArr.end(), currCoords) == coordsArr.end()){
                    coordsArr.push_back(currCoords);
                }
            }else if (direction == "D"){
                headCoords.first--;
                if (abs(headCoords.first - currCoords.first) > 1){
                    currCoords.second = headCoords.second;
                    currCoords.first--;
                }
                if(find(coordsArr.begin(), coordsArr.end(), currCoords) == coordsArr.end()){
                    coordsArr.push_back(currCoords);
                }
            }
        }
    }
    return coordsArr.size();
}