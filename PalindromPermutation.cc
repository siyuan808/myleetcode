// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int ind, int n, string& half, int count[], vector<string>& res) {
    if(ind == n) {
        res.push_back(half);
        return;
    }
    for(int c = 0;c < 256; c++) {
        if(count[c] == 0) continue;
        half[ind] = (char) c;
        count[c]--;
        dfs(ind+1, n, half, count, res);
        count[c]++;
    }
}

vector<string> palind(string& s) {
    int odd = 0; 
    vector<string> res;
    int count[256] = {0};
    for(char c: s) {
        count[c]++;
        if(count[c] % 2 == 1) odd++;
        else odd--;
    }
    if(odd >= 2) {
        cout <<"Not palindrom string"<<endl;
        return res;
    }
    int n = s.length() / 2;
    if(n == 0) {res.push_back(s); return res;}
    string half(n, ' ');
    char mid;
    for(int i = 0; i < 256; i++) {
        if(count[i] == 0) continue;
        if(count[i] % 2 == 1) mid = (char) i;
        count[i] /= 2;
    }
    dfs(0, n, half, count, res);
    for(int i = 0; i < res.size(); i++) {
        string sec(res[i]);
        if(odd) sec += mid;
        reverse(sec.begin(), sec.end());
        res[i] += sec;
    }
    return res;
}

int main()
{
  string s;
  cin >>s;
  vector<string> ps = palind(s);
  for(string p: ps)
    cout << p <<endl;
}
