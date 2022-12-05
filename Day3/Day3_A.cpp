#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

int findTheScore(vector<string> arr);
char findCommonChar(string str1, string str2);

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
    
    cout << findTheScore(inp) << endl;
    return 1;
};

int findTheScore(vector<string> arr){
    int sum = 0;
    char common;

    string str1 = "";
    string str2 = "";

    map<char, int> table;

    vector<char> upperCase = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<char> lowerCase = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (int i = 0; i < upperCase.size(); i++){
        table[upperCase[i]] = i+27;
    }

    for (int i = 0; i < lowerCase.size(); i++){
        table[lowerCase[i]] = i+1;
    }
    for (int i = 0; i < arr.size(); i++){
        int strlen = arr[i].length();
        string str1 = "";
        string str2 = "";
        for (int j = 0; j < strlen/2; j++){
            str1 += arr[i][j];
        }
        for (int j = strlen/2; j < strlen; j++){
            str2 += arr[i][j];
        }
        common = findCommonChar(str1, str2);
        if (common != '-'){
            sum += table[common];
        }
        str1 = "";
        str2 = "";
    }
    return sum;
}

char findCommonChar(string str1, string str2){
    int length = str1.length();

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            if (str1[i] == str2[j]){
                return str1[i];
            }
        }
    }
    return '-';
}
