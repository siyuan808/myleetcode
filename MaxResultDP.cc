#include <iostream>
#include <vector>

using namespace std;

int maxResult(vector<int>& nums) {
    //dynamic programming
    int n = nums.size();
    if(n == 0) return 0;
    int dp[n][n];
    
    for(int len = 0; len < n; len++) {
        for(int i = 0; i+len < n; i++) {
            if(len == 0) {
                dp[i][i] = nums[i];
            } else {
                int j = i+len;
                int maxi2j = 0;
                for(int k = i; k < j; k++) {
                    maxi2j = max(maxi2j,max(dp[i][k]*dp[k+1][j], dp[i][k]+dp[k+1][j]));
                }
                dp[i][j] = maxi2j;
            }
        }
    }
    return dp[0][n-1];
}

int main() {
	vector<int> nums{1,2,3,1};
	cout <<maxResult(nums);
	return 0;
}
