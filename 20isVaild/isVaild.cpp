#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

bool isVaild(std::string s)
{
    int len = s.size();
    std::vector<char> stack;
    std::unordered_map<char, char> m;
    m.insert(std::make_pair(')', '('));
    m.insert(std::make_pair('}', '{'));
    m.insert(std::make_pair(']', '['));

    for(int i = 0; i < len; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack.push_back(s[i]);
        }
        else
        {
            if(stack.size() == 0 || m[s[i]] != stack.back())
            {
                return false;
            }
            stack.pop_back();
        }
    }
    if(stack.size() != 0) return false;
    return true;
}

int main(int argc, char* argv[])
{
    std::string s1 = "()";
    std::cout<<(isVaild(s1)?"true":"false");
    std::cout<<std::endl;
   
    std::string s2 = "()[]{}";
    std::cout<<(isVaild(s2)?"true":"false");
    std::cout<<std::endl;

    std::string s3 = "(]";
    std::cout<<(isVaild(s3)?"true":"false");
    std::cout<<std::endl;

    std::string s4 = "([)]";
    std::cout<<(isVaild(s4)?"true":"false");
    std::cout<<std::endl;

    std::string s5 = "{[]}";
    std::cout<<(isVaild(s5)?"true":"false");
    std::cout<<std::endl;
    
}