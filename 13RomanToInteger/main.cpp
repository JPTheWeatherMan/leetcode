#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int returnNum = 0;

        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case 'I':
                    returnNum = returnNum + 1;
                    break;
                case 'V':
                    returnNum = returnNum + 5;
                    break;
                case 'X':
                    returnNum = returnNum + 10;
                    break;
                case 'L':
                    returnNum = returnNum + 50;
                    break;
                case 'C':
                    returnNum = returnNum + 100;
                    break;
                case 'D':
                    returnNum = returnNum + 500;
                    break;
                case 'M':
                    returnNum = returnNum + 1000;
                    break;
            }

            if(i + 1 > s.size()) break;
            char nextCharacter = s[i + 1];
            switch(s[i]){
                case 'I':
                    if(nextCharacter == 'V' || nextCharacter == 'X'){
                        returnNum = returnNum - 2;
                    }
                    break;
                case 'X':
                    if(nextCharacter == 'L' || nextCharacter == 'C'){
                        returnNum = returnNum - 20;
                    }
                    break;
                case 'C':
                    if(nextCharacter == 'D' || nextCharacter == 'M'){
                        returnNum = returnNum - 200;
                    }
                    break;
            }
        }
        return returnNum;
    }
};