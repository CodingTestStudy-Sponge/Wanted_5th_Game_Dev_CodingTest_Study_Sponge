#pragma once

#include <string>

using namespace std;

// 387. First Unique Character in a String(Easy)
class Solution
{
public:
	int firstUniqChar(string s)
	{
		/* 알파벳 소문자별로 카운트되는 갯수 저장 배열 */
		int alphabetCount['z' - 'a' + 1] = { 0 };

		/* 문자열을 순회하면서 등장하는 문자의 갯수를 증가*/
		size_t length = s.length();
		for (size_t i = 0; i < length; ++i)
		{
			++alphabetCount[s[i] - 'a'];
		}

		/* 다시 문자열을 순회 */
		for (size_t i = 0; i < length; ++i)
		{
			/* 등장하는 문자들 중 최초로 갯수가 1인(반복되지 않는) 문자의 인덱스 반환 */
			if (1 == alphabetCount[s[i] - 'a'])
			{
				return i;
			}
		}

		/* 반복되지 않는 문자가 존재하지 않는 경우 */
		return -1;
	}
};


