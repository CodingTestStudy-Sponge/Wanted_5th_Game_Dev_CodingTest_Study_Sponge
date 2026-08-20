#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        bool answer = true;
        //스택
        stack<char> stack = {};

        //범위 확장 for문 s 순회
        for (char t : s)
        {
            if (t == '(' || t == '{' || t == '[')
            {
                stack.push(t);
            }

            else if (t == ')' || t == '}' || t == ']')
            {
                if (stack.empty())
                {
                    return false;
                }

                char val = stack.top();
                stack.pop();

                //짝이 맞지 않을 경우 false 반환
                if ((t == ')' && val != '(') || (t == '}' && val != '{') || (t == ']' && val != '['))
                {
                    return false;
                }
            }  
        }

        //스택이 비어있지 않다면 false반환
        if (!stack.empty())
        {
            return false;
        }

        return answer;
    }
};

// 그냥 &&로 top이 ')', '}', ']'일 경우로 했을 때 else if 문을 돌지 않고 그냥 넘어가버려서 초기 answer 값이 반환됨.

//#include <stack>
//#include <string>
//
//using namespace std;
//
//class Solution {
//public:
//    bool isValid(string s) {
//
//        bool answer = true;
//        //스택
//        stack<char> stack = {};
//
//        //문자열 배열 순회
//        for (int ix = 0; ix < s.size(); ++ix)
//        {
//            //'(' 일 경우 push
//            if (s[ix] == '(' || s[ix] == '{' || s[ix] == '[')
//            {
//                stack.push('(' && '{' && '[');
//            }
//
//            //')' 찾을 경우 pop
//            else if (s[ix] == ')' && stack.top() == '(')
//            {
//                //스택이 비어있을 경우 false
//                if (stack.empty())
//                {
//                    return false;
//                }
//
//                stack.pop();
//            }
//
//            else if (s[ix] == '}' && stack.top() == '{')
//            {
//                //스택이 비어있을 경우 false
//                if (stack.empty())
//                {
//                    return false;
//                }
//
//                stack.pop();
//            }
//
//            else if (s[ix] == ']' && stack.top() == '[')
//            {
//                //스택이 비어있을 경우 false
//                if (stack.empty())
//                {
//                    return false;
//                }
//
//                stack.pop();
//            }
//        }
//
//        return answer;
//    }
//};
