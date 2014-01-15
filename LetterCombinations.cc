vector<string> letterCombinations(string digits) {
    string rep[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;
    if(digits.size() == 0) {
        ret.push_back("");
    	return ret;
    }
    string s(digits.size(), '0');
    build(digits, rep, 0, s, ret);
    return ret;
}

void build(const string digits, string rep[], int index, string &s, vector<string> &ret) {
    if(index == digits.length()) {
	ret.push_back(s);
	return;
    }
    int n = digits[index] - '0';
    for(int i=0; i<rep[n].size(); i++){
	s[index] = rep[n][i];
	build(digits, rep, index+1, s, ret);
    }
}
