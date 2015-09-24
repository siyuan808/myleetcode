// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstringTwoDistinct(string str) {
    int n = str.length();
    if(n <=2 ) return n;
    int res = 0;
    char a, b;
    int cnt_a=0, cnt_b = 0;
    int s = 0, e = 0;
    while(e < n) {
        char c = str[e];
        if(cnt_a == 0 || c == a) {
            a = c;
            cnt_a++;
        }else if(cnt_b == 0 || c == b) {
            b = c;
            cnt_b++;
        } else {
            if(e-s > res) res = e-s;
            while(s < e) {
                c = str[s];
                if(c == a) cnt_a--;
                else if(c == b) cnt_b--;
                s++;
                if(!cnt_a || !cnt_b) break;
            }
        }
        e++;
    }
    return max(res, n-s);
                
}
    
int main() {
    string s;
    cin >>s;
    cout <<"len: "<< lengthOfLongestSubstringTwoDistinct(s);
}
