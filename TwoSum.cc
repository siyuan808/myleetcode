class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
    	vector<int> res;
	unordered_map<int, vector<int>> hash;
	//put the numbers into the hash;
	for(int i= 0; i<numbers.size(); i++) {
	    unordered_map<int, vector<int>>::iterator it = hash.find(numbers[i]);
	    if(it==hash.end()) {
  		vector<int> v;
		v.push_back(i);
		hash.insert(make_pair(numbers[i], v));
	    } else {
		//duplicate
		it->second.push_back(i);
	    }
	}
	for(int i=0; i<numbers.size(); i++) {
	    unordered_map<int, vector<int>>::iterator it = hash.find(target - numbers[i]);
	    if(it!=hash.end()) {
	        vector<int> opts = it->second;
		for(int j = 0; j<opts.size(); j++) {
		    if(opts[j] != i) {
			res.push_back(i+1);
			res.push_back(opts[j]+1);
			return res;
		    }
		}
	    }
	}
	return res;
    }
};
