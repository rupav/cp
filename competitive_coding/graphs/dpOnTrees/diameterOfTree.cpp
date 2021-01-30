#include<bits/stdc++.h>
using namespace std;

/// leet code: https://leetcode.com/problems/diameter-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

using pii = pair<int, int>;
class Solution {
    int ans;
public:

    /// pair<a, b> : 'a' stores max diameter when that node is starting of it. 'b' stores max diameter when that node is part of max dia.
    pii solve(TreeNode* root){
        if(root == NULL) return {0, 0};

        pii lp = solve(root->left);
        pii rp = solve(root->right);

        int x = max(lp.first, rp.first)+1;
        int y = 1+lp.first+rp.first;
        ans = max(ans, max(x, y));

        return make_pair(x, y);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        /// consider root as starting of the diameter and find answer in subtree.
        /// consider root as a part of the longest diameter which passes through it, and rest elements are in subtree of it.
        ans = 0;
        solve(root);
        return max(0, ans-1);  /// edges
    }
};

int main(){
    return 0;
}
