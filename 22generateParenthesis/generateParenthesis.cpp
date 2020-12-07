#include<iostream>
#include<string>
#include<vector>

void backtrack(std::vector<std::string>& res, std::string& curr, int open, int close, int n)
{
    if(curr.size() == 2 * n)
    {
        res.push_back(curr);
        return;
    }
    if(open < n)
    {
        curr.push_back('(');
        backtrack(res, curr, open + 1, close, n);
        curr.pop_back();
    }

    if(close < open)
    {
        curr.push_back(')');
        backtrack(res, curr, open, close + 1, n);
        curr.pop_back();
    }
    return;
}

std::vector<std::string> generateParenthesis(int n)
{
    std::string curr;
    std::vector<std::string> res;
    backtrack(res, curr, 0, 0, n);
    for(std::string s : res)
    {
        std::cout<<s<<std::endl;
    }
    return res;
}

int main()
{
    std::vector<std::string> res = generateParenthesis(2);
}