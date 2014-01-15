/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.*/

int minPathSum(vector<vector<int> > &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp_array(n, 0);
    dp_array[n-1] = grid[m-1][n-1];
    int j=n-2;
    while(j>=0){
        dp_array[j] = dp_array[j+1] + grid[m-1][j];
	j--;
    };
    
    int i=m-2;
    while(i>=0) {
        dp_array[n-1] += grid[i][n-1];
	j = n-2;
	while(j>=0){
	    dp_array[j] = (dp_array[j] < dp_array[j+1] ? dp_array[j]+grid[i][j] : dp_array[j+1] + grid[i][j]);
	    j--;
	}
	i--;
    }
    return dp_array[0];
}
