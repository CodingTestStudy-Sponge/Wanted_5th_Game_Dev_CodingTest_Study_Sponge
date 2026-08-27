#pragma once

#include <string>
#include <stack>
#include <cctype>

using namespace std;

/*
https://leetcode.com/problems/decode-string/description/?envType=problem-list-v2&envId=stack
LeetCode.394 Decode String
인코딩된 문자열이 주어졌을 때, 디코딩된 문자열을 반환합니다.
인코딩 규칙은 다음과 같습니다. k[encoded_string], 여기서 encoded_string대괄호 안의 는 정확히 k번 반복됩니다. 는 k양의 정수임이 보장됩니다.
입력 문자열은 항상 유효하다고 가정할 수 있습니다. 불필요한 공백이 없고, 대괄호의 형식이 올바르다는 등의 조건을 만족합니다. 
또한, 원본 데이터에는 숫자가 포함되어 있지 않으며, 숫자는 반복되는 숫자에만 존재한다고 가정할 수 있습니다 . 
예를 들어, 또는 k와 같은 입력은 없을 것입니다 .3a2[4]
테스트 케이스는 출력 길이가 절대 초과하지 않도록 생성됩니다 .105


예시 1:
입력: s = "3[a]2[bc]"
출력: "aaabcbc"
예시 2:

입력: s = "3[a2[c]]"
출력: "accaccacc"
예시 3:

입력: s = "2[abc]3[cd]ef"
출력: "abcabccdcdcdef"


제약 조건:

1 <= s.length <= 30
s소문자 영문자, 숫자 및 대괄호로 구성됩니다 '[]'.
s유효한 입력 값임이 보장됩니다 .
의 모든 정수는 s범위 내에 있습니다 [1, 300].

*/

//class Solution
//{
//public:
//    string decodeString(string s)
//    {
//        stack<char>stack;
//        string str = "";
//
//        for (char c : s)
//        {
//            stack.push(c);
//        }
//
//        while (!stack.empty())
//        {
//            if (stack.top() == ']')
//            {
//                stack.pop();
//            }
//
//            else if (isalpha(stack.top()))
//            {
//                str += stack.top();
//
//                stack.pop();
//            }
//
//            else if (stack.top() == '[')
//            {
//                stack.pop();
//
//                if (isdigit(stack.top()))
//                {
//                    // 숫자 만큼 반복
//                    int replay = stack.top() - '0';
//
//                    string previousStr = str;
//
//                    stack.pop();
//
//                    for (int ix = 0; ix < replay - 1; ++ix)
//                    {
//                        str += previousStr;
//                    }
//                }
//            }
//            else
//            {
//                stack.pop();
//            }
//        }
//        reverse(str.begin(), str.end());
//        return str;
//    }
//};


class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> numberStack;
        stack<string> stringStack;

        string current = "";
        int number = 0;

        for (char c : s)
        {
            // 숫자
            if (isdigit(c))
            {
                // 두자리 숫자를 고려해 *10 처리
                number = number * 10 + (c - '0');
            }

            // [
            else if (c == '[')
            {
                // 반복 횟수 저장
                numberStack.push(number);

                // 문자열 저장
                stringStack.push(current);

                // 새로운 처리를 위해 초기화
                number = 0;
                current = "";
            }

            // ]
            else if (c == ']')
            {
                // 반복 횟수 가져오기
                int repeat = numberStack.top();
                numberStack.pop();

                // 만들어졌던 문자열 가져오기
                string previous = stringStack.top();
                stringStack.pop();

                // 반복 횟수만큼 추가
                for (int ix = 0; ix < repeat; ++ix)
                {
                    previous += current;
                }
                // 현재 문자열로 지정
                current = previous;
            }

            // 알파벳
            else
            {
                current += c;
            }
        }

        return current;
    }
};