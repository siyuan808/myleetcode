#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <limits.h>

using namespace std;

bool containPermutation(string hay, string needle) {
    int PRIM[26]={2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 
                        31, 37, 41, 43, 47, 53, 59, 61, 
                        67, 71, 73, 79, 83, 89, 97, 101};
    long target = 1;
    for(char c : needle) target *= PRIM[c-'a'];
    
    int lenHay = hay.length(), lenNeedle = needle.length();
    if(lenHay < lenNeedle) return false;
    
    int cand = 1;
    for(int pos = 0; pos < lenNeedle; pos++) {
        cand *= PRIM[hay[pos]-'a'];
    }
    
    int cntPos = lenNeedle;
    while(target != cand && cntPos < lenHay) {
        cand /= PRIM[hay[cntPos-lenNeedle] -'a'];
        cand *= PRIM[hay[cntPos]-'a'];
        cntPos++;
    }
    return target == cand;
}

int main() {
    string hay, needle;
    cin >>hay>>needle;
    cout <<containPermutation(hay, needle);
    return 0;
}
