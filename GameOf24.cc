#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <limits.h>
#include <math.h>

using namespace std;

bool dfs(vector<int>& nums, int cur, string expr, vector<bool>& visited) {
    int allVisited = true;
    for(int i = 0; i < nums.size(); i++) {
        if(visited[i] == false) {
            allVisited = false;
            visited[i] = true;
            if(expr == ""){
                if(dfs(nums, nums[i], ""+to_string(nums[i]), visited)) return true;
            }
            else {
                if(dfs(nums, cur + nums[i], expr+"+"+to_string(nums[i]), visited)) return true;
                if(dfs(nums, cur - nums[i], expr+"-"+to_string(nums[i]), visited)) return true;
                if(dfs(nums, cur * nums[i], expr+"*"+to_string(nums[i]), visited)) return true;
                if(dfs(nums, cur / nums[i], expr+"/"+to_string(nums[i]), visited)) return true;
            } 
            visited[i] = false;
        }
    }
    if(allVisited && cur == 24) {
        cout <<expr<<endl;
        return true;
    }
    return false;
}

bool gameOf24(vector<int>& nums) {
    int cur = 0;
    string expr = "";
    vector<bool> visited(nums.size(), false);
    return dfs(nums,cur, expr, visited);
}

int main()
{
    vector<int> nums;
    for(int i = 1;  i <= 24;i++) nums.push_back(i);
    cout <<gameOf24(nums);
    return 0;
}
