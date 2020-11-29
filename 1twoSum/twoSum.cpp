#include<vector>
#include<iostream>
#include<unordered_map>
std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::vector<int> res;
    std::unordered_map<int, int> m;
    int len = nums.size();

    for(int index = 0; index < len; index++)
    {
        int num2 = target - nums[index];
        if(m.find(num2) != m.end())
        {
            res.push_back(m[num2]);
            res.push_back(index);
            return res;
        }
        else
        {
            m[nums[index]] = index; 
        }
    }
    return res;
}

int main()
{
    std::vector<int> nums = {2, 7 , 11, 5};
    int target = 9;
    std::vector<int> res = twoSum(nums, target);
    for(auto num : res)
    {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
}