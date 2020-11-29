#include<iostream>
#include<vector>
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode *head = new ListNode();
    ListNode* currNode = head;
    while(l1 != nullptr && l2 != nullptr)
    {
        if(l1->val > l2->val)
        {
            currNode->next = new ListNode(l2->val);
            l2 = l2->next;
        }
        else
        {
            currNode->next = new ListNode(l1->val);
            l1 = l1->next;
        }
        currNode = currNode->next;
    }
    if(l1 == nullptr){ currNode->next = l2; }
    else{ currNode->next = l1;}
    ListNode* res = head->next;
    delete head;
    return res;
}

int main()
{
    std::vector<int> nums1 = {1, 2, 4};
    std::vector<int> nums2 = {1, 3, 4};

    ListNode* head1 = buildListNode(nums1);
    ListNode* head2 = buildListNode(nums2);

    std::cout<<"list1"<<std::endl;
    printListNode(head1);

    std::cout<<"list2"<<std::endl;
    printListNode(head2);

    ListNode* res = mergeTwoLists(head1, head2);
    std::cout<<"res List"<<std::endl;
    printListNode(res);
}