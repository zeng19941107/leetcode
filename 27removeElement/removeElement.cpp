#include<iostream>
#include<vector>

int removeElement(std::vector<int>& nums, int val) {
    int res = 0;
    int len = nums.size();

    for(int i = 0; i < len; i++)
    {
        if(nums[i] == val) continue;
        nums[res++] = nums[i];
    }
        return res;
}

int main()
{
    std::vector<int> nums{0,1,2,2,3,0,4,2};
    int res = removeElement(nums, 2);
    for(int i = 0; i < res; i++)
    {
        std::cout<<nums[i]<<" ";
    }
    std::cout<<std::endl;
}