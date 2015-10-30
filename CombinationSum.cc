#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <limits.h>

using namespace std;
//A number can be used anytimes, and the result doesn't have to be sorted.

void dfs(vector<int>& nums, int target, vector<int>& sol, vector<vector<int>>& res) {
    if(target == 0) {
        res.push_back(sol);
        return;
    }
    if(target < 0) return;
    
    for(int n : nums) {
        sol.push_back(n);
        dfs(nums, target-n, sol, res);
        sol.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    vector<int> sol;
    dfs(nums, target, sol, res);
    return res;
}


int main() {
    vector<int> nums{4,3,1};
    vector<vector<int>> combinations = combinationSum(nums, 5);
    for(vector<int> comb : combinations ) {
        for(int x : comb) {
            cout <<x<<" ";
        }
        cout <<endl;
    }
    return 0;
}
