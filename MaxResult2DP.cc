#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxResult(vector<int>& nums) {
    //dynamic programming
    int n = nums.size();
    if(n == 0) return 0;
    int dp[n][n][2]; //0: minValue 1: maxVal
    
    for(int len = 0; len < n; len++) {
        for(int i = 0; i+len < n; i++) {
            if(len == 0) {
                dp[i][i][0] = dp[i][i][1] = nums[i];
            } else {
                int j = i+len;
                int maxi2j = INT_MIN;
                int mini2j = INT_MAX;
                for(int k = i; k < j; k++) {
                    int min1 = dp[i][k][0];
                    int max1 = dp[i][k][1];
                    int min2 = dp[k+1][j][0];
                    int max2 = dp[k+1][j][1];
                    //min: min1-min2, min1*max2, max1*min2
                    mini2j = min(mini2j, min(min1-min2, min(min1*max2, max1*min2)));
                    //max: max1+max2, max1*max2, min1*min2
                    maxi2j = max(maxi2j, max(max1+max2, max(max1*max2, min1*min2)));
                }
                dp[i][j][0] = mini2j;
                dp[i][j][1] = maxi2j;
            }
        }
    }
    return dp[0][n-1][1];
}

int main() {
	vector<int> nums{-1,2,3,1};
	cout <<maxResult(nums);
	return 0;
}
