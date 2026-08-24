// 844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/description/

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    std::stack<char> stack1;
    std::stack<char> stack2;

    bool backspaceCompare(string s, string t) {
        //s 먼저 순회해서 #이 아니면 스택에 담고, #이면 스택이 비지 않았을 때만 pop.
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '#')
            {
                if(!stack1.empty())
                {
                    stack1.pop();
                }
            }
            else stack1.push(s[i]);
        }

        //t도 s와 마찬가지로 진행
        for(int i = 0; i < t.size(); ++i)
        {
            if(t[i] == '#')
            {
                if(!stack2.empty())
                {
                    stack2.pop();
                }
            }
            else stack2.push(t[i]);
        }

        //stack1과 stack2의 사이즈가 다르면 애초에 다른 문장이므로 false 반환
        if(stack1.size() != stack2.size())
        {
            return false;
        }
        else
        {
            //스택이 빌때까지 stack에서 하나씩 뽑아서 비교해서 다르면 false 반환
            while(!stack1.empty() && !stack2.empty()) 
            {
                if(stack1.top() != stack2.top())
                {
                    return false;
                }
                stack1.pop();
                stack2.pop();
            }
            //여기까지 왔으면 문자가 같은 것임
            return true;
        }
    }

    
};