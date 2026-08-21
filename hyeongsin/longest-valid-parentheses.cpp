#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int answer = 0;
        int save1 = 0;
        int save2 = 0;

        //스택 생성
        stack<char> stack = {};

        for (int ix = 0; ix < s.size(); ++ix)
        {
            if (s[ix] == '(')
            {
                stack.push('(');

                if (s[ix + 1] != '\0' && s[ix + 1] == '(')
                {
                    save1 = answer;
                    answer = 0;
                }
            }

            else if (s[ix] == ')')
            {
                if (stack.empty())
                {
                    continue;
                }

                answer += 2;
                char val = stack.top();
                stack.pop();

                if (s[ix + 1] != '\0' && s[ix + 1] == ')')
                {
                    save2 += answer;
                    answer = 0;
                }
            }
        }

        if (!stack.empty())
        {
            return answer + save2;
        }

        if (stack.empty())
        {
            return answer + save2 + save1;
        }

        return 0;
    }
};