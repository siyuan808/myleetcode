#include <iostream>
#include <vector>

using namespace std;

int cal(string & str, int& ind, int level) {
    int res = 0;
    int num = 0;
    for(; ind < str.size(); ind++) {
        if(str[ind] == ' ') continue;
        if(str[ind] == ',') {
            res += num * level;
            num = 0;
        }
        else if(str[ind] == '[') {
            ind++;
            res += cal(str, ind, level+1);
        } else if(str[ind] == ']') {
            res += num * level;
            return res;
        }
        else num = num * 10 + str[ind]-'0';
    }
    return res;
}

int weightSum(string& str) {
    int ind = 0;
    return cal(str, ind, 0);
}

int main() {
    string str = "[1, [2,3],[[4]]]";
    cout <<weightSum(str);
    return 0;
}
