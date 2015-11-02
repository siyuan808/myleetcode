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
public:
    string encode(string& str) {
         /* Example
         * "bJbb++b"
         *    1. 'b' occurs 4 times.
         *       '+' occurs 2 times.
         *       'J' occurs 1 times.
         *    2. Thus, the following encodings are assigned:
         *       'b' -> "1"
         *       '+' -> "01"
         *       'J' -> "001"
         *    3. By concatenating the encodings together, we get:
         *       "10011101011".
         */
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
        for(int i = occChar.size()-2; i>= 0; i--) {
            code = "0" + code;
            codeMap[occChar[i].second] = code;
        }
        
        string res;
        for(char c : str) {
            res += codeMap[c];
        }
        return res;
    }
    
    string decode(string& str) {
        return "";
    }
};

int main() {
    StringCode sc;
    string str = "bjbb++b";
    cout <<sc.encode(str);
}
