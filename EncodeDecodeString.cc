#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <math.h>
#include <algorithm>

using namespace std;

class StringCode {
    string codeBook;
public:
    string encode(string& str) {
        if(str == "") return "";
        unordered_map<char, int> countMap;
        for(char c : str) {
            if(countMap.find(c) == countMap.end()) 
                countMap[c] = 0;
            countMap[c] += 1;
        }
        
        vector<pair<int,char>> occChar;
        for(unordered_map<char,int>::iterator it = countMap.begin();
            it != countMap.end(); it++) {
                occChar.push_back(make_pair(it->second, it->first));
        }
        
        sort(occChar.begin(),occChar.end());
        
        unordered_map<char, string> codeMap;
        string code="1";
        codeMap[occChar.back().second] = code;
        codeBook += occChar.back().second;
        for(int i = occChar.size()-2; i>= 0; i--) {
            code = "0" + code;
            codeMap[occChar[i].second] = code;
            codeBook += occChar[i].second;
        }
        
        string res;
        for(char c : str) {
            res += codeMap[c];
        }
        return res;
    }
    
    string decode(string str) {
        string res = "";
        int pos = 0;
        for(char c : str) {
            if(c == '1') {
                if(pos > codeBook.size()) return "";
                res += codeBook[pos];
                pos = 0;
            } else pos ++;
        }
        return res;
    }
};

int main() {
    StringCode sc;
    string str = "bjbb++b++";
    cout <<sc.decode(sc.encode(str));
}
