class Solution {
public:
    int longestValidParentheses(string s) {
        int answer = 0;


        //스택 생성
        stack<int> stack = {};
        stack.push(-1);

        for(int ix = 0; ix < s.size(); ++ix)
        {
            //'(' 일 경우 해당 인덱스 스택에 넣기
            if(s[ix] == '(')
            {
                stack.push(ix);
            }
            else
            {
                stack.pop();
                
                 if(stack.empty())
                    {
                        stack.push(ix);
                    }
                    
                    else
                    {
                        answer = max(answer, ix - stack.top());
                    }
            }
        }

        return answer;
    }
};
