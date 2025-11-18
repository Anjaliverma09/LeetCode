class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int lastVal = 0;

            for(int i=0; i<size; i++){        
                TreeNode* current = q.front();
                q.pop();
                
                lastVal = current->val;
                
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }  
            ans.push_back(lastVal); 
        }
        return ans;
    }
};