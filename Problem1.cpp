// Time Complexity : O(2^n) n is # of nodes in tree.
// Space Complexity : O(n) .
// Did this code successfully run on Leetcode : Yes 


// Your code here along with comments explaining your approach:
// 1. Perform BFS using queue and maintain level and max at each level variable.
// 2. Travel left and right node for each node and push it to queue if not null.
// 3. If current nodes val is greater and maxl store it and after completing each level store it in vector for each level max
// and reset maxl(INT_MIN).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if(root!=nullptr){q.push(root);}
        int l=0,maxl=INT_MIN,nl=1;
        vector<int> ans;
        while(!q.empty()){
            TreeNode* t= q.front();
            if((t->val)>maxl){
                maxl=t->val;
            }
            if( (t->left)!=nullptr ){q.push(t->left);}
            if( (t->right)!=nullptr ){q.push(t->right);}
            q.pop();nl--;
            if(nl==0){
                nl=q.size();
                ans.push_back(maxl);maxl=INT_MIN;
            }
        }
        return ans;
    }
};