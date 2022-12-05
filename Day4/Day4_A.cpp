#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int overlappingCheck(vector<string> pairs);
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

    cout << overlappingCheck(inp) << endl;
    return 1;
};

int overlappingCheck(vector<string> pairs){
    int count = 0;
    int num1, num2, num3, num4;
    string firstHalf, secondHalf;
    for (int i = 0; i < pairs.size(); i++){
        firstHalf = pairs[i].substr(0, pairs[i].find(','));
        secondHalf = pairs[i].substr(pairs[i].find(','), pairs[i].length());

        num1 = stoi(firstHalf.substr(0, firstHalf.find('-')));
        num2 = stoi(firstHalf.substr(firstHalf.find('-') + 1, firstHalf.length()));
        num3 = stoi(secondHalf.substr(1, secondHalf.find('-')));
        num4 = stoi(secondHalf.substr(secondHalf.find('-') +1, secondHalf.length()));

        if (num1 >= num3 && num2 <= num4 || num1 <= num3 && num2 >= num4){
            count++;
        }
    }

    return count;
}