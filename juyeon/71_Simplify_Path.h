#pragma once

#include <string>
#include <sstream>
#include <vector>

using namespace std;

// 71. Simplify Path(Medium)
class Solution
{
public:
	string simplifyPath(string path)
	{
		/*경로를 구성하는 문자열을 나누기 위한 stream*/
		stringstream ss(path);
		string token;

		/*결과 경로를 조합하기 위해 경로 문자열을 쌓아 둘 벡터*/
		vector<string> v;

		/* '/' 기준으로 나눈 문자열 값을 토큰으로 받는다(이때 '/' 자체는 제외) */
		while (getline(ss, token, '/'))
		{
			//공백, 폴더 자기 자신 위치('/.')는 건너뛴다.
			if (token.empty() || token == ".")
			{
				continue;
			}
			else if (token == "..") //직전 디렉토리('/..')의 경우 바로 직전에 쌓였던 폴더 경로 하나를 제거한다.
			{
				//비어있지않은경우 == 루트디렉토리가 아닐때
				if (!v.empty())
				{
					//직전 경로 제거
					v.pop_back();
				}
			}
			else
			{
				//그외 경로를 구성하는 폴더경로는 모두 추가
				v.push_back(token);
			}
		}

		//경로 조합
		string result;
		for (const string& token : v)
		{
			//경로 시작 및 구분은 '/'로 해야 함
			result += "/" + token;
		}

		//경로가 비어있음 == 루트 디렉토리
		if (result.empty())
		{
			//공백이 존재할 수 없으므로 '/'를 반환해야 함
			result = "/";
		}

		//결과 반환
		return result;
	}
};


