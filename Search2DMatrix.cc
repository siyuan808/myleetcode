/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 */
bool searchMatrix(vector<vector<int> > &matrix, int target) {
    //search for the candidate row
    int low = 0; int high = matrix.size()-1;
    int mid;
    while(high >= low) {
	mid = (low+high)/2;
	if(matrix[mid][0] == target) 
	    return true;
	else if(matrix[mid][0] > target) 
	    high = mid-1;
	else low = mid+1;
    }
    int r = high >= 0 ? high : 0;
    low = 0; high = matrix[r].size()-1;
    while(high >= low) {
	mid = (low + high)/2;
	if(matrix[r][mid] == target)
	    return true;
	else if (matrix[r][mid] > target)
	    high = mid-1;
	else low = mid+1;
    }
    return false;
}
