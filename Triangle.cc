class Solution {
public:
    int minimumTotal(vector<vector<int> > &t) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
	    // Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
    	int nRows = t.size();
	if(nRows == 0) return 0;
	vector<int> p(nRows+1, 0);
	int row = nRows-1;
	while(row >= 0){
	    for(int i=0; i<=row; i++) {
		p[i] = t[row][i] + ((p[i] < p[i+1])?p[i]:p[i+1]);
	    }
	    row--;
	}
	return p[0];
    }
};

