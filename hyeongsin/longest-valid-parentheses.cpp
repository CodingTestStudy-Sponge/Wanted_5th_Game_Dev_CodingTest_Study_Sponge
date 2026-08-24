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
                //')' 일 경우 top 제거
                stack.pop();
                //스택이 비어있다면 새로운 기준점으로 설정.
                 if(stack.empty())
                    {
                        stack.push(ix);
                    }
                    //스택이 채워져 있다면 완전한 괄호라고 봐도 되기 때문에 최댓값 구하기.
                    else
                    {
                        answer = max(answer, ix - stack.top());
                    }
            }
        }

        return answer;
    }
};
