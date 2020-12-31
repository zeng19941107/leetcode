#include<vector>
#include<unordered_map>
#include<iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(std::vector<int>& preOrder, std::vector<int>& inOrder, int preL, int preR, int inL, int inR, std::unordered_map<int, int>& index)
{
    if(preL > preR || inL > inR) return nullptr;

    TreeNode* root = new TreeNode(preOrder[preL]);
    int rootIn = index[preOrder[preL]];
    root->left = createTree(preOrder, inOrder, preL + 1, preL + rootIn - inL, inL, rootIn - 1, index);
    root->right = createTree(preOrder, inOrder, preL + rootIn - inL + 1, preR, rootIn + 1, inR, index);
    return root;
}

TreeNode* buildTree(std::vector<int>& preOrder, std::vector<int>& inOrder)
{
    int n = inOrder.size();
    std::unordered_map<int, int> index;
    for(int i = 0; i < n; i++)
    {
        index[inOrder[i]] = i;
    }
    TreeNode* root = createTree(preOrder, inOrder, 0, n - 1, 0, n - 1, index);
    return root;
}

void preTree(TreeNode* root)
{
    if(root == nullptr) return;
    std::cout<<root->val<<" ";
    preTree(root->left);
    preTree(root->right);
}

void inTree(TreeNode* root)
{
    if(root == nullptr) return;
    inTree(root->left);
    std::cout<<root->val<<" ";
    inTree(root->right);
}


int main()
{
    std::vector<int> preOrder = {3,9,20,15,7};
    std::vector<int> inOrder = {9,3,15,20,7};
    TreeNode* root = buildTree(preOrder, inOrder);

    preTree(root);
    std::cout<<std::endl;
    inTree(root);
    std::cout<<std::endl;
}