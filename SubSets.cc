class Solution {
public:
    vector<vector<int>> subsets(vector<int> &s) {
	sort(s.begin(), s.end());
	return subsets(s, s.size()-1);
    }

    vector<vector<int>> subsets(vector<int> &s, int i) {
	if( i < 0) {
	    vector<vector<int>> result;
	    vector<int> empty;
	    result.push_back(empty);
	    return result;
	} else {
	    vector<vector<int>> result = subsets(s, i-1);
	    //add the current number to the result;
	    int len = result.size();
	    for(int j=0; j < len; j++) {
		result.push_back(result[j]);
		result.back().push_back(s[i]);
	    }
	    return result;
	}
    }
};
