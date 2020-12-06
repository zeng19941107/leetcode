#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

void backtrack(std::vector<std::string>& combinations, std::unordered_map<char, std::string>& m, std::string& digits, int index, std::string& combination)
{
    //std::cout<<"backtrack"<<std::endl;
    if(index == digits.size())
    {
        combinations.push_back(combination);
    }
    else
    {
        char digit = digits[index];
        const std::string& letters = m.at(digit);
        for(const char& letter : letters)
        {
            combination.push_back(letter);
            backtrack(combinations, m, digits, index + 1, combination);
            combination.pop_back();
        }
    }
}

std::vector<std::string> letterCombination(std::string digits)
{
    std::vector<std::string> combinations;
    if(digits.empty()) return combinations;
    std::unordered_map<char, std::string> m;
    m.insert({'2', "abc"});
    m.insert({'3', "def"});
    m.insert({'4', "ghi"});
    m.insert({'5', "jkl"});
    m.insert({'6', "mno"});
    m.insert({'7', "pqrs"});
    m.insert({'8', "tuv"});
    m.insert({'9', "wxyz"});
    std::string combination;
    backtrack(combinations, m, digits, 0, combination);
    return combinations;
}

int main()
{
    std::string digits = "23";
    std::vector<std::string> res = letterCombination(digits);
    for(auto r : res)
    {
        std::cout<<r<<std::endl;
    }
}