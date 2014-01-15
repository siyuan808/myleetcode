#include<iostream>

using namespace std;

int firstMissingPositive(int A[], int n) {
    // find the first missing positive starting from the min positive

    //first find the min
    int min = A[0];
    for(int i=0; i<n; i++) 
        if(A[i] > 0 && A[i] < min)
	    min = A[i];

    cout <<"Min: " <<min<<endl;
    if(min < 0) return 1;
    //make the A[i]-min in the pos of i
    for(int i = 0; i < n; i++) {
	if(A[i] > 0 && A[i] < n + min) {
	    if(A[i]-min != i && A[i] != A[A[i]-min]) {
		int temp = A[A[i] - min];
		A[A[i]-min] = A[i];
		A[i] = temp;
		i--;
	    }
	}
    }

    for(int j=0; j<n; j++) 
        if(A[j]-min != j)
	    return j+min;

    return n+min;
}

int main() {
    int A[5] = { 6, 8, 7, 10, 100 };
    cout <<"first missing positive: " <<firstMissingPositive(A, 5)<<endl;
    return 0;
}
