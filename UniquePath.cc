int uniquePaths(int m, int n) {
    
    return uniquePaths(0, 0, m, n);

}

int uniquePaths(int x, int y, int m, int n) {
    if(x>=m || y>=n) return 0;
    if(x==m-1 && y==n-1) return 1;

    int right = uniquePaths(x, y+1, m, n);
    int down = uniquePaths(x+1, y, m, n);
    return right + down;
}

//The above is a recursive solution. Effectively, we should use DP
int uniquePaths(int m, int n) {

    int path[m][n];
    for(int i=0;i<m; i++) 
        for(int j=0; j<n; j++)
	    path[i][j] = -1;
    path[m-1][n-1] = 1;

    return uniquePaths(path, 0, 0, m, n);
}

int uniquePaths(int p[][N], int x, int y, int m, int n) {
    if(x>=m || y>=n) return 0;
    if(p[x][y] != -1) return p[x][y];

    int right = uniquePaths(p, x, y+1, m, n);
    int down = uniquePaths(p, x+1, y, m, n);
    p[x][y] = right + down;
    return p[x][y];
}


//Actually we can reduce the space into one array and use a bottom up approach
int uniquePaths(int m , int n) {
    
    vector<int> p(n+1, 0);
    int i = m-1;
    int j = n-1;
    while(j>=0) 
        p[j--] = 1;

    while(i-- > 0) {
	for(j=n-1; j>=0; j--)
	    p[j] = p[j] + p[j+1];
    }

    return p[0];

}
