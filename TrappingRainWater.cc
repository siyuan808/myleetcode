int trap(int A[], int n) {
    if(n <= 2) return 0;
    int maxIndex = 0, max = 0;
    
    //find the max
    for( int i=0; i < n; i++) 
        if(A[i] > max) {
	    max = A[i];
	    maxIndex = i;
	}

    if(max == 0) return 0;
    int res = 0;
    
    //calculate the left part
    for(int left = 0, leftMax = 0; left < maxIndex; left++ ) {
	if(A[left] < leftMax)
	    res += (leftMax - A[left]);
	else 
	    leftMax = A[left];
    }

    for(int right = n-1, rightMax = 0; right > maxIndex; right-- ) {
	if(A[right] < rightMax ) 
	    res += (rightMax - A[right]);
	else 
	    rightMax = A[right];
    }

    return res;
}
