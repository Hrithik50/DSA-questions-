222. Count Complete Tree Nodes
Medium

5619

330

Add to List

Share
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
Accepted
443,300
Submissions
777,892
Seen this question in a real interview before?

CODE:-
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int countNodes(struct TreeNode* root){
    if(root == NULL)
        return 0;
    int lh  = leftheight(root);
    int rh = rightheight(root);
    if(lh == rh)
    {
       return (1 << lh)-1 ;  //2^h-1; 
    }
    else
    {
        return 1 + countNodes(root->left) + countNodes(root->right);  
    }
}
int leftheight(struct TreeNode* node)
{
    int lh = 0;
    while(node)
    {
        lh++;
        node = node->left;
    }
    return lh;
}
int rightheight(struct TreeNode* node)
{
    int rh = 0;
    while(node)
    {
        rh++;
        node = node->right;
    }
    return rh;
}
