#include<vector>
#include<iostream>
#include<utility>

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

void printListByStartAndEnd(ListNode* start, ListNode* end)
{
    while(start != end)
    {
        std::cout<<start->val<<"->";
        start = start->next;
    }
    std::cout<<end->val<<"->";
    std::cout<<"null"<<std::endl;
}

std::pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail)
{
    ListNode* pre = tail->next;
    ListNode* curr = head;
    while(pre != tail)
    {
        ListNode* nex = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nex;
    }
    std::pair<ListNode*, ListNode*> res{tail, head};
    return res;
}


ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode* hair = new ListNode(0, head);
    ListNode* pre = hair;

    while(head){
        ListNode* tail = pre;
        for(int i = 0; i < k; i++)
        {
            tail = tail->next;
            if(tail == nullptr) return hair->next;
        }

        ListNode* nex = tail->next;
        std::pair<ListNode*, ListNode*> result = reverseList(head, tail);
        head = result.first;
        tail = result.second;

        pre->next = head;
        tail->next = nex;
        pre = tail;
        head = tail->next;
    }
    return hair->next;
}

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5};
    ListNode* head = buildListNode(nums);
    printListNode(head);
    ListNode* res = reverseKGroup(head, 3);
    printListNode(res);
}