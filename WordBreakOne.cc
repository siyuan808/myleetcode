#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <limits.h>

using namespace std;

vector<string> wordBreakOne(string s, unordered_set<string>& wordList) {
    int strLen = s.length();
    vector<int> breakLen(strLen+1,-1);
    breakLen[strLen] = 0;
    
    for(int pos=strLen-1; pos>=0; pos--) {
        for(int len = 1; pos+len <= strLen; len++) {
            if(wordList.find(s.substr(pos,len)) != wordList.end() && breakLen[pos+len] >= 0) {
                breakLen[pos] = len;
                break;
            }
        }
    }
    if(breakLen[0] < 0) return vector<string>();
    vector<string> res;
    int pos = 0;
    while(pos < strLen) {
        res.push_back(s.substr(pos,breakLen[pos]));
        pos += breakLen[pos];
    }
    
    return res;
}

int main() {
    unordered_set<string> wordList;
    wordList.insert("hello");
    wordList.insert("world");
    vector<string> words = wordBreakOne("helloworld",wordList);
    for(string s: words) cout <<s<<" ";
    return 0;
}
