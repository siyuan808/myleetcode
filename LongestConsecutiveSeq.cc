class Solution {
public:
    int longestConsecutive(vector<int> &num) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
	unordered_map<int, int> hash;
	//hash->second 0:visited, 1: initial state, >1 consetive number starting from this number
	for(int i=0; i<num.size(); i++) {
	    hash.insert(make_pair(num[i], 1));
	}

	int max = 1;
	unordered_map<int, int>::iterator it = hash.begin();
	for(; it!=hash.end(); it++) {
	    int s = it->second;
	    if(s != 0) {
	   	int next = it->first + it->second;
		unordered_map<int, int>::iterator nextIt = hash.find(next);
		while(nextIt!=hash.end()) {
		    it->second += nextIt->second;
		    next = it->first+it->second;
		    nextIt->second = 0;
		    nextIt = hash.find(next);
		}
		if(it->second > max) max = it->second;
	    }
	}
	return max;
    }
    
    // The above method will run in a O(n^2) time
    // This following one is modified from leetcode, in O(n^2) time
    int longestConsecutive(vector<int> &num) {
	if(num.size() <= 0) return 0;
	int n = num.size();
	unordered_map<int, int> hash;
	unordered_map<int, int>::iterator it;
	int maxLen = 1;
	for(int i = 0; i < n; i++) {
	    int x = num[i];
	    it = hash.find(x);
	    if( it == hash.end() ) {
	        // Not processed
		hash[x] = 1;
		if( hash.find(x-1) != hash.end())
		    maxLen =  max(maxLen, merge(hash, x-1, x));
		if( hash.find(x+1) != hash.end())
		    maxLen = max(maxLen, merge(hash, x, x+1));
	    }
	}
	return maxLen;
    }

    int merge(unordered_map<int, int> &hash, int left, int right) { 
        int upper = right + hash[right] - 1;
        int lower = left - hash[left] + 1;
	int len = upper - lower + 1;
	hash[upper] = len;
	hash[lower] = len;
        return len;
    }
};

