#include <iostream>
#include <vector>

using namespace std;


void generateChar(char s[], int left, int right, int pos, vector<string> &res) {
    if(left < 0 || right < left) return;
    if(left == 0 && right==0) {
	res.push_back(string(s));
	return;
    }
    if(left > 0) {
        s[pos] = '(';   
	generateChar(s, left-1, right, pos+1, res);
    }
    if(right > left) {
	s[pos] = ')';
	generateChar(s, left, right-1, pos+1, res);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if(n==0) return res;
    char s[2*n];
    int left = n, right = n;
    generateChar(s, left, right, 0, res);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> p = generateParenthesis(n);
    for(int i=0; i<p.size(); i++)
        cout <<p[i]<<endl;
    return 0;
}
