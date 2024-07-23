
class Solution {
public:
    void inorder(TreeNode *root,vector<int>&v){
        if(root==NULL){
            return;}
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res;
        inorder(root,res);
        return res[k-1];}};
   