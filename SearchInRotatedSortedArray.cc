// Assumption: There is no duplicates in the array

int search(int A[], int n, int target) {
    if(n<1) return -1;

    return search(A, 0, n-1, target);
}

int search(int A[], int low, int high, int target) {
    if(high < low) return -1;

    int mid = (low +high)/2;
    if(A[mid] == target) return mid;

    if(A[mid] > A[low]) { // left is in normal order
	if(target > A[low] && A[mid] > target)
	    return search(A, low, mid-1, target);
	else 
	    return search(A, mid+1, high,  target);
    } else if(A[mid] < A[low]) {
	//right is in normal order
	if(A[mid] < target && target < A[high])
	    return search(A, mid+1, high, target);
	else 
	    return seasrch(A, low, mid-1, target);
    }
}
