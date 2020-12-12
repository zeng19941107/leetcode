#include<vector>
#include<iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildListNode(std::vector<int>& nums)
{
    ListNode* head = new ListNode();
    ListNode* currNode = head;
    for(auto num : nums)
    {
        currNode->next = new ListNode(num);
        currNode = currNode->next;
    }
    ListNode* res = head->next;
    delete head;
    return res;
}

void printListNode(ListNode* head)
{
    auto currNode = head;
    while(currNode != nullptr)
    {
        std::cout<<currNode->val<<"->";
        currNode = currNode->next;
    }
    std::cout<<"null"<<std::endl;
}

ListNode* swapPairs(ListNode* head)
{
    ListNode* myHead = new ListNode(0, head);
    ListNode* currNode = myHead;
    ListNode* firstNode, *secondNode;
    while(currNode != nullptr && currNode->next != nullptr && currNode->next->next != nullptr){
        firstNode = currNode->next;
        secondNode = currNode->next->next;
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;
        currNode->next = secondNode;
        currNode = firstNode;
    }
    //printListNode(myHead);
    ListNode* res = myHead->next;
    delete myHead;
    return res;
}

int main()
{
    std::vector<int> nums{1,2,3};
    ListNode* head = buildListNode(nums);
    std::cout<<"origin head"<<std::endl;
    printListNode(head);
    ListNode* res = swapPairs(head);
    std::cout<<"swap head"<<std::endl;
    printListNode(res);
}