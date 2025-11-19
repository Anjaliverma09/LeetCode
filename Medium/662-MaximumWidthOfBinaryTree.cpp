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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;       //bcz of CBT indexing
        q.push({root, 0});
        int maxWidth = 0;

        while(q.size() > 0){
            int lvlSize = q.size();
            unsigned long long startIdx = q.front().second;
            unsigned long long lastIdx = q.back().second;

            maxWidth = max(maxWidth, (int)(lastIdx - startIdx + 1));

            for(int i=0; i<lvlSize; i++){
                auto node = q.front();
                q.pop();

                if(node.first->left)
                    q.push({node.first->left, node.second*2+1});

                if(node.first->right)
                    q.push({node.first->right, node.second*2+2});
            }
        }
        return maxWidth;
    }
};