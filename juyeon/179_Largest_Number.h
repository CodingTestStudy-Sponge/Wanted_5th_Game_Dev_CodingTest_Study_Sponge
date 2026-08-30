#pragma once

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 179. Largest Number
class Solution
{
public:
	string largestNumber(vector<int>& nums)
	{
		const size_t numsSize = nums.size();

		/* 정수형 숫자를 string으로 변환 */
		vector<string> stringNums(numsSize);
		for (size_t i = 0; i < numsSize; ++i)
		{
			stringNums[i] = std::to_string(nums[i]);
		}

		/* 문자열 비교 람다 */
		auto compare = [](const string& lhs, const string& rhs)
			{
				/* 바로 앞 뒤의 숫자 조합을 문자열로 비교함 (ex : 3430 > 3034) */
				/* true : 앞 뒤의 순서 유지, false : 앞 뒤 순서 바꿈 */
				return lhs + rhs > rhs + lhs;
			};
		
		/* 람다 식 내 기준으로 문자열들의 조합이 가장 큰 숫자가 나올 수 있도록 내림차순 정렬 */
		std::sort(stringNums.begin(), stringNums.end(), compare);

		/* 숫자 조합이 0으로 시작하면 바로 0 반환 */
		if ("0" == stringNums[0])
		{
			return "0";
		}
		else
		{
			/* 정렬된 문자 배열을 하나로 합쳐서 반환 */
			string result;
			for (const string& numStr : stringNums)
			{
				result += numStr;
			}

			return result;
		}
	}
};

