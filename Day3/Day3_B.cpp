#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

int findTheScore(vector<string> arr);
char findCommonChar(string str1, string str2, string str3);

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
    for (int i = 0; i < arr.size(); i+=3){
        common = findCommonChar(arr[i], arr[i+1], arr[i+2]);
        if (common != '-'){
            sum += table[common];
        }
    }
    return sum;
}

char findCommonChar(string str1, string str2, string str3){
    int length1 = str1.length();
    int length2 = str2.length();
    int length3 = str3.length();

    bool flag2 = false;
    bool flag3 = false;

    for (int i = 0; i < length1; i++){
        for (int j = 0; j < length2; j++){
            if (str1[i] == str2[j]){
                flag2= true;
            }
        }
        for (int j = 0; j < length3; j++){
            if (str1[i] == str3[j]){
                flag3 = true;
            }
        }
        if (flag2 && flag3){
            return str1[i];
        }

        flag2 = false;
        flag3 = false;
        
    }
    return '-';
}
