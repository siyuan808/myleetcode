#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
    	return uniqueBSTHelper(1, n);
    }
    int uniqueBSTHelper(int s, int e) {
    	if(s>=e)
	    return 1;
	int ret = 0;
	for(int i=s; i<=e; i++)
	    ret += uniqueBSTHelper(s, i-1) * uniqueBSTHelper(i+1, e);

	return ret;
    }

    int catalanNum(int n) {
        int a[n+1];
	for(int i=0; i<= n; i++) {
	    a[i]=0;
	}
	a[0]=1;
	a[1]=1;
	return catalanHelper(a, n);
    }

    int catalanHelper(int a[], int n) {
    	if(a[n]>0)
	    return a[n];
	for(int i=0; i<n; i++)
	    a[n] += catalanHelper(a, i) * catalanHelper(a, n-1-i);
	return a[n];
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    cout <<"The catalan number of " <<n<<" is:  " <<s.catalanNum(n)<<endl;
    return 0;
}
