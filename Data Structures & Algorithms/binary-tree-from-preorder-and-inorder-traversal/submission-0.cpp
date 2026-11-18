class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;

        TreeNode* t = new TreeNode(preorder[0]);

        int r = 0;
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == t->val) {
                r = i;
                break;
            }
        }

        vector<int> preorderl(
            preorder.begin() + 1,
            preorder.begin() + 1 + r
        );

        vector<int> inorderl(
            inorder.begin(),
            inorder.begin() + r
        );

        vector<int> preorderr(
            preorder.begin() + 1 + r,
            preorder.end()
        );

        vector<int> inorderr(
            inorder.begin() + r + 1,
            inorder.end()
        );

        t->left = buildTree(preorderl, inorderl);
        t->right = buildTree(preorderr, inorderr);

        return t;
    }
};