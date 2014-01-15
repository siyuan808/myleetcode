vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
	//         // DO NOT write int main() function
	//
    int low =0, high = n-1, mid;
    int a=-1, b=-1;
    
    vector<int> range = searchRange(A, low, high, target);
    if(range.size()>0){
        mid = (range[0]+range[1])/2;
	a=b= mid;
    } else {
	    vector<int> aRange = searchRange(A, low, mid-1, target);
	    while(aRange.size()>0) {
		int aMid = (aRange[0]+aRange[1])/2;
		a = aMid;
		aRange = searchRange(A, aRange[0], aMid-1, target);
	    }
	    vector<int> bRange = searchRange(A, mid+1, high, target);
	    while(bRange.size() > 0) {
		int bMid = (bRange[0] + bRange[1])/2;
		b = bMid;
		bRange = searchRange(A, bMid+1, bRange[1], target);
	    }
    }
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    return res;
}

vector<int> searchRange(int A[], int low, int high, int target) {
    vector<int> res;
    if(high < low) return res;
    int mid = low + (high-low)/2;
    if(A[mid] == target) {
	res.push_back(low);
	res.push_back(high);
	return res;
    } else if(A[mid] < target)
        return searchRange(A, mid+1, high, target);
          else 
	    return searchRange(A, low, mid-1, target);
}
