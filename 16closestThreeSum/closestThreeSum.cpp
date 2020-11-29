#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>

int threeSumClosest(std::vector<int>& nums, int target)
{
    std::sort(nums.begin(), nums.end());
    int res;
    auto begin = nums.begin();
    auto end = nums.end();
    res = *(begin) + *(begin +  1) + *(begin + 2);
    for(auto now = begin; now < end - 2; now++)
    {
        if(now > begin && *now == *(now - 1))
        {
            continue;
        }
        
        int nowTarget = target - (*now);
        auto left = now + 1;
        auto right = end - 1;
        while(left < right)
        {
            int sum = *left + *right;
            if(nowTarget == sum)
            {
                return target;
            }
            //std::cout<<"now = "<<*now<<std::endl;
            if(abs(nowTarget - sum) < abs(target - res))
            {
                res = *now + *left + *right;
                //std::cout<<"res = "<<res<<std::endl;
            }
            
            if(sum > nowTarget)
            {
                while(--right != begin && *right ==*(right + 1));
            }
            else
            {
                while(++left != end && *left == *(left - 1));
            }
        }
    }
    return res;
}

int main()
{
    std::vector<int> nums = {0, 2, 1, -3};
    std::cout<<threeSumClosest(nums, 1)<<std::endl;
}
