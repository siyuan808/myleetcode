int removeDuplicates(int A[], int n) {
    if(n<=1) return n;
    int curPos= 1,  curEle = A[0];
    for(int i=1; i<n; i++) {
	if(A[i] != curEle) {
	    curEle = A[i];
	    A[curPos++] = A[i];
	}
    }
    return curPos;
}
