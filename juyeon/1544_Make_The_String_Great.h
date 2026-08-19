#pragma once

#include <string>

using namespace std;

// 1544. Make The String Great(Easy)
class Solution
{
public:
	string makeGood(string s)
	{
		string result;

		/* 원본 문자열의 문자 순회 */
		for (char c : s)
		{
			if (result.empty())
			{
				/* 첫 문자의 경우 무조건 삽입 */
				result.push_back(c);
			}
			else if(abs(result[result.length() - 1] - c) == 32)
			{
				/* 직전 문자와 현재 문자 관계가 '나쁜 관계(한쪽이 대문자이면 다른쪽이 소문자)'인지 확인 */
				/* 그 관계가 맞으면 직전 문자 제거, 현재 문자는 추가 안함 */
				result.erase(result.length() - 1);
			}
			else
			{
				/* 그 외의 경우 '좋은 관계'이므로 추가*/
				result.push_back(c);
			}
		}

		/* 결과 반환 */
		return result;
	}
};

