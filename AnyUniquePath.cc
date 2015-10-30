#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <limits.h>
#include <math.h>

using namespace std;



void dfs(int x, int y, int eX, int eY, int remSteps, vector<vector<bool>>& passed, int &res) {
    if(passed[x][y]) return;
    int distance = abs(x-eX) + abs(y-eY);
    if(distance > remSteps) return;
    if(remSteps == 0) {
        res += distance==0; //one path;
        return;
    }
    passed[x][y] = true;
    //check all four neighbors
    if(x-1 >= 0) dfs(x-1, y, eX,eY, remSteps-1, passed, res);
    if(y-1 >= 0) dfs(x, y-1, eX, eY, remSteps-1, passed,res);
    if(x+1 < 8) dfs(x+1, y, eX, eY, remSteps-1,passed, res);
    if(y+1 < 8) dfs(x, y+1, eX, eY, remSteps-1,passed, res);
    passed[x][y] = false;
}

int uniquePath(int sX, int sY, int eX, int eY, int k) {
    int res = 0;
    vector<vector<bool>> passed(8, vector<bool>(8, false));
    dfs(sX,sY,eX,eY,k,passed,res);
    return res;
}

int main()
{
    cout <<uniquePath(0,1,1,0,6);
    return 0;
}
