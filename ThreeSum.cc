//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
//Find all unique triplets in the array which gives the sum of zero.

vector<vector<int> > threeSum(vector<int> &num) {
    set<vector<int>> triplets; //use set to ensure uniqueness
    sort(num.begin(), num.end());

    vector<int> triplet(3);
    int n = num.size();
    for(int i= 0; i < n-2; i++) {
	int j = i+1;
	int k = n-1;
	while( j < k) {
	    int two_sum = num[i] + num[j];
	    if( two_sum + num[k] < 0) {
	  	triplet[0] = num[i];
		triplet[1] = num[j];
		triplet[2] = num[k];
		triplets.push_back(triplet);
		j++;
		k--;
	    } else if( two_sum + num[k] < 0) {
		j++;
	    } else 
	    	k--;
	}
    }

    vector<vector<int>> res;
    for(set<vector<int>>::iterator it = triplets.begin(); it != triplets.end(); it++) {
	res.push_back(*it);
    }
    return res;
}
