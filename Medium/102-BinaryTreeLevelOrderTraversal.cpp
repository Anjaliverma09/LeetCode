class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> ans;

            for(int i=0; i<size; i++){
                TreeNode* current = q.front();
                q.pop();
                ans.push_back(current->val);

                if(current->left != NULL)
                    q.push(current->left);

                if(current->right != NULL)
                    q.push(current->right);
            }
            result.push_back(ans);
        }
        return result;
    }
};