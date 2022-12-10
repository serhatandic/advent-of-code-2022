#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int findSignalStrength(vector<string> inp);

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
    findSignalStrength(inp);
    return 1;
};

int findSignalStrength(vector<string> inp){
    string command;
    int number, cycle = 1, regValue = 1, innerCycle = 0, triggerCycle = 20, sum = 0, s1 = 0, s2 = 1, s3 = 2;
    vector<string> myQueue = inp;

    while(!myQueue.empty()){

        command = myQueue[0].substr(0, 4);
        if(command == "noop"){
            myQueue.erase(myQueue.begin());
            if (cycle - 1 == s1 || cycle - 1 == s2 || cycle - 1 == s3){
                cout << '#';
            }else{
                cout << '.';
            }
            cycle++;
        }else{
            if (cycle - 1 == s1 || cycle - 1 == s2 || cycle - 1 == s3){
                cout << '#';
            }else{
                cout << '.';
            }
            cycle += 1;
            
            innerCycle += 1;

            if (innerCycle == 2){
                number = stoi(myQueue[0].substr(5, myQueue[0].length() - 5));
                regValue+=number;
                innerCycle = 0;
                myQueue.erase(myQueue.begin());

                s1 = regValue -1;
                s2 = s1 + 1;
                s3 = s2 + 1;
            }
            
        }

        if (cycle == triggerCycle){
            sum += regValue * triggerCycle;
            triggerCycle += 40;
        }
        if (cycle % 40 == 1){
            cout << endl;
            cycle -=40;
        }

        

    }
    return sum;
}