#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    auto begin = nums.begin();
    auto end = nums.end();
    for(auto now = begin; now != end - 2; now++)
    {
        if(now > nums.begin() && *now == *(now - 1))
        {
            continue;
        }
        auto left = now + 1;
        auto right = end - 1;
        int target = -(*now);
        while(left < right)
        {
            int sum = *left + *right;
            if(sum == target)
            {
                std::vector<int> tmp;
                tmp.push_back(*now);
                tmp.push_back(*left);
                tmp.push_back(*right);
                res.push_back(tmp);
                //update left and right
                while(++left != end && *left == *(left - 1));
                while(--right != begin && *right == *(right + 1));
            }
            else if(sum > target)
            {
                while(--right != begin && *right == *(right + 1));
            }
            else if(sum < target)
            {
                while(++left != end && *left == *(left - 1));
            }
        }
    }
    return res;
}


void printVector(std::vector<int>& nums)
{
    for(int num : nums)
    {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
}

int main(int argc, char* argv[])
{
    std::vector<int> nums{-2, 0, 0, 2, 2};
    printVector(nums);
    std::vector<std::vector<int>> res = threeSum(nums);
    for(auto r : res)
    {
        printVector(r);
    }
}