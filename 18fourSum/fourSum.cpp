#include<vector>
#include<algorithm>
#include<iostream>
std::vector<std::vector<int>> fourSum(std::vector<int> nums, int target)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    int len = nums.size();
    //std::cout<<"len = "<<len<<std::endl;
    for(int i = 0; i < len - 3; i++)
    {
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        //std::cout<<"i = "<<i<<std::endl;
        for(int j = i + 1; j < len - 2; j++)
        {
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;
            //std::cout<<"j = "<<j<<std::endl;
            int left = j + 1;
            int right = len - 1;
            //std::cout<<"left = "<<left<<std::endl;
            //std::cout<<"right = "<<right<<std::endl;
            while(left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                //std::cout<<"sum = "<<sum<<std::endl;
                if(sum == target)
                {
                    /*
                    std::cout<<"i = "<<i<<std::endl;
                    std::cout<<"j = "<<j<<std::endl;
                    std::cout<<"left = "<<left<<std::endl;
                    std::cout<<"right = "<<right<<std::endl;
                    */
                    std::vector<int> cmp;
                    cmp.push_back(nums[i]);
                    cmp.push_back(nums[j]);
                    cmp.push_back(nums[left]);
                    cmp.push_back(nums[right]);
                    //std::cout<<"cmp"<<std::endl;
                    res.push_back(cmp);
                    //std::cout<<"res"<<std::endl;
                    while(++left && nums[left] == nums[left - 1]);
                    while(--right && nums[right] == nums[right + 1]);
                }
                else if(sum < target)
                {
                    //std::cout<<"sum < target"<<std::endl;
                    while(++left && nums[left] == nums[left - 1]);
                    //std::cout<<"left = "<<left<<std::endl;
                }
                else if(sum > target)
                {
                    //std::cout<<"sum > target"<<std::endl;
                    while(--right && nums[right] == nums[right + 1]);
                    //std::cout<<"right = "<<right<<std::endl;
                }
            }
        }
    }
    return res;
}

int main()
{
    std::vector<int> nums{-2,-1,-1,1,1,2,2};
    int target = 0;
    std::vector<std::vector<int>> res = fourSum(nums, target);
    for(auto r : res)
    {
        for(int n : r)
        {
            std::cout<<n<<" ";
        }
        std::cout<<std::endl;
    }
}