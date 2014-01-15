//elements are not assumpted to be distinct

bool search(int A[], int n, int target) {
    if(n<1) return false;

    return search(A, 0, n-1, target);
}

bool search(int A[], int low, int high, int target) {
    if(high < low) return false;

    int mid = (low +high)/2;
    if(A[mid] == target) return true;

    if(A[mid] > A[low]) { // left is in normal order
	if(target >= A[low] && A[mid] > target)
	    return search(A, low, mid-1, target);
	else 
	    return search(A, mid+1, high,  target);
    } else if(A[mid] < A[low]) {
	//right is in normal order
	if(A[mid] < target && target <= A[high])
	    return search(A, mid+1, high, target);
	else 
	    return search(A, low, mid-1, target);
    } else { //left == mid, one side is the smae
        if(A[mid] != A[high])  //left side is same
	    return search(A, mid+1, high, target);
	else {
	    if(search(A, low+1, mid-1, target)) 
	        return true;
	    else
	        return search(A, mid+1, high-1, target);
	}
    }
}
