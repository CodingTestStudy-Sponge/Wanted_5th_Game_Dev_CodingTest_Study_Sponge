#pragma once
#include <string>
#include <vector>

//두 문자열 s와 t가 주어졌을 때, 빈 텍스트 편집기에 두 문자열을 입력했을 때 두 문자열이 같다면 true를 반환하라. '#'는 백스페이스 문자를 의미합니다.
//
//빈 텍스트를 백스페이싱한 후에는 텍스트가 계속 비어 있게 된다는 점을 유의하세요.
//
//
//
//예시 1:
//
//입력: s = "ab#c", t = "ad#c"
//출력 : 참
//설명 : s와 t 모두 "ac"가 됩니다.
//예시 2 :
//
//    입력 : s = "ab##", t = "c#d#"
//    출력 : 참
//    설명 : s와 t 모두 ""가 됩니다.
//    예시 3 :
//
//    입력 : s = "a#c", t = "b"
//    출력 : 거짓
//    설명 : s는 "c"가 되고 t는 "b"가 됩니다.
//
//
//    제약 조건 :
//
//1 <= s.length, t.length <= 200
//s와 t는 소문자와 '#' 문자만 포함합니다.
//
//
//추가 질문 : O(n) 시간과 O(1) 공간으로 해결할 수 있나요 ?



using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> v1(200);
        vector<char> v2(200);

        for (char c : s)
        {
            // # 아니면 푸시, #이면 pop
            if (c != '#') v1.push_back(c);
            else
            {
                if (!v1.empty())
                {
                    v1.pop_back();
                }

            }
        }

        for (char c : t)
        {
            // # 아니면 푸시, #이면 pop
            if (c != '#') v2.push_back(c);
            else
            {
                if (!v2.empty())
                {
                    v2.pop_back();
                }

            }
        }
        // 사이즈 틀리면 false
        if (v1.size() != v2.size()) return false;

        // 글자 틀리면 false
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i]) return false;
        }

        // 맞으면 true
        return true;
    }
};


/* Input
    s = "y#fo##f"
    t = "y#f#o##f" -> #이 두번 이상 나올 경우: !EMPTY() 예외처리해도오류남 왜지

    Use Testcase
    Output
    false
    Expected
    true
*/