void merge(int A[], int m, int B[], int n) {
    //assume A can hold the total number of A and B
    int i=m-1, j=n-1, k=m+n-1;
    while(i>=0 && j>=0) {
	if(A[i] > B[j]) {
	    A[k--] = A[i--];
	}else {
	    A[k--] = B[j--];
	}
    }

    while(i>=0) 
        A[k--] = A[i--];
    while(j>=0)
        A[k--] = B[j--];

}
