// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(int i, int n, string& half, int count[], vector<string>& res) {
    if(i == n) {
        res.push_back(half);
        return;
    }
    for(int i = 0;i < 256; i++) {
        if(count[i] == 0) continue;
        half[i] = (char) i;
        count[i]--;
        dfs(i+1, n, half, count, res);
        count[i]++;
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
    if(odd > 2) return res;
    int n = s.length() / 2;
    if(n == 0) {res.push_back(s); return res;}
    string half(n, ' ');
    char mid = "";
    for(int i = 0; i < 256; i++) {
        if(count[i] == 0) continue;
        if(count[i] % 2 == 1) mid = (char) i;
        count[i] /= 2;
    }
    dfs(0, n, half, count, res);
    for(int i = 0; i < res.size(); i++) {
        string sec (res[i]);
        reverse(sec.begin(), sec.end());
        res[i] += mid + sec;
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
