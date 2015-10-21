#include <iostream>
#include <string>

using namespace std;

int getFactorSum(int n) {
    //get the sum of all the factor of n except n
    if(n <= 1) return 0;
    int i = 2;
    int sum = 1; //factor 1
    while(1) {
        int j = n/i;
        if(i > j) break;
        if(n % i == 0) {
            if(i == j) {
                sum += i;
                break;
            }
            else sum += i + j;
        }
        i++;
    }
    return sum;
}

void printPairFactorSum(int n) {
    if(n <=1) return;
    int factorSum[n+1];
    for(int i = 1; i <=n; i++) 
        factorSum[i] = getFactorSum(i);
        
    for(int x = 1; x <= n; x++) {
        int y = getFactorSum(x);
        if(y <= n && y >= x && factorSum[y] == x) {
            cout <<x <<" "<<y<<endl;;
        }
    }
}
// Driver program to test above functions
int main()
{
	int n = 5000;
    printPairFactorSum(n);
	return 0;
}
