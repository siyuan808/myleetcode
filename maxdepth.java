/**
 *  * Definition for binary tree
 *   * public class TreeNode {
 *    *     int val;
 *     *     TreeNode left;
 *      *     TreeNode right;
 *       *     TreeNode(int x) { val = x; }
 *        * }
 *         */
public class Solution {
    public int maxDepth(TreeNode root) {
            // Start typing your Java solution belo                
	if(root == null) return 0;
	int left=0, right = 0;
	left = maxDepth(root.left);
	right = maxDepth(root.right);
	return left>right? (left+1):(right+1);
    }
}
