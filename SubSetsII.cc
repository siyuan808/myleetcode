class Solution {
    vector<vector<int>> subsetsWithDup(vector<int> &s) {
	sort(s.begin(), s.end());
	vector<vector<int>> result(1);
	
	int lastoutput=0;
	for(int i=0; i<s.size(); i++) {
	    int j= result.size();
	    if(i > 0 && s[i] == s[i-1]) 
	        j = lastoutput;
	    lastoutput = 0;
	    while(j-- > 0) {
		result.push_back(result[j]);
		result.back().push_back(s[i]);
		lastoutput ++;
	    }
	}
    }
};
