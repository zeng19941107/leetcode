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

ListNode* merge(std::vector<ListNode*>& lists, int l, int r)
{
    if(l == r) return lists[l];
    if(l > r) return nullptr;
    int mid = (l + r) / 2;
    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
}

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    return merge(lists, 0, lists.size() - 1);    
}

int main()
{
    std::vector<ListNode*> numsList;
    std::vector<int> nums1 = {1, 4, 5};
    std::vector<int> nums2 = {1, 3, 4};
    std::vector<int> nums3 = {2, 6};
    ListNode* l1 = buildListNode(nums1);
    ListNode* l2 = buildListNode(nums2);
    ListNode* l3 = buildListNode(nums3);
    numsList.push_back(l1);
    numsList.push_back(l2);
    numsList.push_back(l3);
    ListNode* res = mergeKLists(numsList);
    printListNode(res);
}