class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        queue<Node*> q;
        q.push(root);

        while(q.size()){
            int size = q.size();
            Node* prev = NULL;

            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();

                if(prev) prev->next = node;
                prev = node;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            prev->next = NULL;
        }
        return root;
    }
};