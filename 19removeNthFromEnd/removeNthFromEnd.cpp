#include<iostream>
#include<vector>
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr){}
    ListNode(int val):val(val), next(nullptr){}
    ListNode(int val, ListNode* next):val(val), next(next){}
};

ListNode* buildList(std::vector<int> nums)
{
    ListNode* head = new ListNode();
    ListNode* currNode = head;
    for(int n : nums)
    {
        currNode->next = new ListNode(n);
        currNode = currNode->next;
    }
    ListNode* res = head->next;
    return res;
}

void printList(ListNode* head)
{
    ListNode* currNode = head;
    while(currNode != nullptr)
    {
        std::cout<<currNode->val<<"->";
        currNode = currNode->next;
    }
    std::cout<<"end"<<std::endl;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(n == 0) return head;
    ListNode* addHead = new ListNode(0, head);
    ListNode* theFrontNode = addHead;
    ListNode* theEndNode = addHead;
    for(int i = 0; i < n + 1; i++)
    {
        //std::cout<<"i = "<<i<<std::endl;
        theEndNode = theEndNode->next;
    }
    while(theEndNode != nullptr)
    {
        theFrontNode = theFrontNode->next;
        theEndNode = theEndNode->next;
    }
    ListNode* currNode = theFrontNode->next;
    theFrontNode->next = currNode->next;
    delete currNode;
    return addHead->next;
}

int main()
{
    std::vector<int> nums{1,2};
    ListNode* head = buildList(nums);
    printList(head);
    
    head = removeNthFromEnd(head, 2);
    printList(head);
}