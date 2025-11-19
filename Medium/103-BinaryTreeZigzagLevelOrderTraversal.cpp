class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool order{true};

        while(q.size()){
            vector<int> level;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front->val);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(order)
                result.push_back(level);
            
            else
                result.push_back(vector<int>{level.rbegin(), level.rend()});
            
            order = !order;     //flip ✌️
        }
        return result;
    }
};