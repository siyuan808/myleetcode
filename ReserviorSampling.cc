#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <limits.h>
#include <math.h>

using namespace std;

vector<int> reserviorSampling(vector<int>& nums, int k) {
    int size = nums.size();
    if(size <= k) return nums;
    
    vector<int> res(k, 0);
    for(int i = 0; i < k; i++) res[i] = nums[i];
    
    for(int i = k; i < size; i++) {
        srand(time(NULL));
        int j = rand() % i;
        if(j < k) res[j] = nums[i];
    }
    return res;
}

int main()
{
    vector<int> nums;
    for(int i = 1;  i <= 100;i++) nums.push_back(i);
    vector<int> rk = reserviorSampling(nums, 5);
    for(int x : rk) cout <<x <<" ";
    cout <<endl;
    return 0;
}
