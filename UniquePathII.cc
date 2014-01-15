public int uniquePathsWithObstacles(vector<vector<int> > &grid) {
     int m = grid.size();
     int n = grid[0].size();

     vector<int> p(n+1, 0);

     m--;
     int i=n-1;
     while(i>=0 && grid[m][i]==0) {
	p[i] = 1;
	i--;
     }

     while(m-- > 0) {
	for(i=n-1; i>=0; i--) {
	    p[i] = (grid[m][i] == 1)?0 : r[i]+r[i-1];
	}
     }

     return r[0];

}
