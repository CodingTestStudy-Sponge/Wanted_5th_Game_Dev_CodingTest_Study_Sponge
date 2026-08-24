#include <string>
#include <stack>
#include <cctype>     // isdigit(), isalpha()
#include <algorithm> // reverse()

using namespace std;

/*
* https://leetcode.com/problems/clear-digits/?envType=problem-list-v2&envId=stack
* LeetCode.3174 Clear Digits
* Input: "cb34" Output: ""
* Input: "abc"  Output: "abc"

문자열이 주어집니다 s.
여러분의 과제는 이 연산을 반복적으로 수행하여 모든 숫자를 제거하는 것입니다 .
첫 번째 숫자와 그 왼쪽 에 가장 가까운 숫자 이외의 문자를 삭제합니다 .
모든 숫자를 제거한 후의 문자열을 반환합니다.
왼쪽에 숫자 이외의 문자가 없는 숫자에 대해서는 해당 연산을 수행 할 수 없다는 점에 유의하십시오 .
예시 1:
입력: s = "abc"
출력: "abc"
설명:
해당 문자열에는 숫자가 없습니다.
예시 2:
입력: s = "cb34"
출력: ""
설명:
s[2]먼저, 에 연산을 적용하면 는 s가 됩니다 "c4".
그런 다음 에 연산을 적용하면 는 s[1]가 s됩니다 "".
제약 조건:
1 <= s.length <= 100
s소문자 영문자와 숫자로만 구성되어 있습니다.
입력값은 모든 숫자를 삭제할 수 있도록 생성됩니다.
---------------------------
stack
4
3       c
b       b
c       a

꺼낼 때 거꾸로 꺼내야  abc.
*/
class Solution {
public:
    string clearDigits(string s)
    {
        // 스택 사용을 위한 스택 선언.
        stack<char>mixString;

        // 리턴 값 문자열.
        string str = "";

        // 현재 문자가 숫자라면.
        for (char c : s)
        {
            if (isdigit(c))
            {
                // 이미 있는 문자도 제거 해야하기 떄문에 pop
                mixString.pop();
            }

            // 숫자가 아니라면 현재 문자 저장.
            else
            {
                mixString.push(c);
            }
        }

        // 문자열에 스택에 남아 있는 문자들 넣기.
        while (!mixString.empty())
        {
            str += mixString.top();
            mixString.pop();
        }

        // 스택에서 꺼낸 값은 역순으로 원래 순서로 뒤집기.
        reverse(str.begin(), str.end());

        return str;
    }
};
