#include<iostream>
#include<string>
#include<vector>
#include<queue>
#define INT_MIN 1<<31
typedef struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): data(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): data(x), left(left), right(right){}
}TreeNode;

TreeNode* buildTree(std::vector<std::string> layData)
{
    if(layData.empty())
    {
        return nullptr;
    }    

    std::queue<TreeNode*> q;
    TreeNode* head = new TreeNode;
    head->data = std::stoi(layData[0]);
    q.push(head);
    TreeNode* bt;
    int i = 1;

    while(!q.empty())
    {
        bt = q.front();
        q.pop();
        if(i < layData.size() && layData[i] != "null")
        {
            bt->left = new TreeNode();
            bt->left->data = std::stoi(layData[i]);
            q.push(bt->left);
            i++;
            //std::cout<<bt->left->data<<std::endl;
        }
        else
        {
            i++;
            bt->left = nullptr;
        }

        if(i < layData.size() && layData[i] != "null")
        {
            bt->right = new TreeNode();
            bt->right->data = std::stoi(layData[i]);
            q.push(bt->right);
            i++;
            //std::cout<<bt->right->data<<std::endl;
        }
        else
        {
            i++;
            bt->right = nullptr;
        }
    }
    return head;
}

void printTree(TreeNode* head)
{
    if(head == nullptr)
    {
        std::cout<<"head is nullptr";
    }
    std::queue<TreeNode*> q;
    q.push(head);
    int i = 1;
    std::cout<<head->data<<" ";
    TreeNode* bt;
    while(!q.empty())
    {
        bt = q.front();
        q.pop();
        if(bt->left != nullptr)
        {
            std::cout<<bt->left->data<<" ";
            q.push(bt->left);
        }
        else
        {
            std::cout<<"null"<<" ";
        }

        if(bt->right != nullptr)
        {
            std::cout<<bt->right->data<<" ";
            q.push(bt->right);
        }
        else
        {
            std::cout<<"null"<<" ";
        }
    }
    std::cout<<std::endl;
}

int ans = INT_MIN;
int maxPathsum(TreeNode* root)
{
    if(root == nullptr) return 0;
    int left = std::max(0, maxPathsum(root->left));
    int right = std::max(0, maxPathsum(root->right));

    ans = std::max(ans, left + right + root->data);
    return std::max(left, right) + root->data;
}

int main()
{
    //std::vector<std::string> layerData1{"1", "2", "3"};
    std::vector<std::string> layerData2{"-10", "9", "20", "null", "null", "15", "7"};
    //TreeNode* head1 = buildTree(layerData1);
    TreeNode* head2 = buildTree(layerData2);
    //printTree(head1);
    printTree(head2);
    maxPathsum(head2);
    std::cout<<"The result = "<<ans<<std::endl;
}