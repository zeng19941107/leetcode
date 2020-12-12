#include<iostream>
#include<vector>

int removeDuplicates(std::vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int res = 1;
    int currNum = nums[0];
    int len = nums.size();
    for(int i = 0; i < len; i++)
    {
        if(nums[i] != currNum)
        {
            nums[res++] = nums[i];
            currNum = nums[i];
        }
    }
    return res;
}

int main()
{
    std::vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    int res = removeDuplicates(nums);
    for(int i = 0; i < res; i++)
    {
        std::cout<<nums[i]<<" ";
    }
    std::cout<<std::endl;
}