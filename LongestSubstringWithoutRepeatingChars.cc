class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
   	int begin = 0, ret = 0;
	vector<int> pos(256, -1); //works just for ASCII, not for unicode 
	for(int i=0; i<s.size(); i++) {
	    begin = max(begin, pos[s[i]]+1);
	    pos[s[i]] = i;
	    ret = max(ret, i-begin+1);
	}
	return ret;
    }
};
