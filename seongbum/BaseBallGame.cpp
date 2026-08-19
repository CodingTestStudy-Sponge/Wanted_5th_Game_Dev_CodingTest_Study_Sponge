#include <vector>
#include <string>
#include <stack>

//682.Baseball Game
//https://leetcode.com/problems/baseball-game/description/?envType=problem-list-v2&envId=stack

using namespace std;
class Solution {
public:
    int calPoints(std::vector<string>& operations) {
        std::stack<int> stack;
        int before = 0;
        int sum = 0;
        int result = 0;
        for (const auto& elem : operations)
        {
            switch (elem[0]){
                //스택의 첫번째와 두번째 원소 더하기
            case '+':
                before = stack.top();
                stack.pop();
                sum = before + stack.top();
                stack.push(before);
                stack.push(sum);
                break;
                //D면 스택 top 원소 * 2한 값을 push
            case 'D':
                stack.push(stack.top() * 2);
                break;
                //스택이 빈 상태에서 pop하면 언더플로우 발생
            case 'C':
                if (!stack.empty())
                {
                    stack.pop();
                }
                break;
            default:
                //string int로 변환 후 stack에 push
                stack.push(stoi(elem));
                break;
            }
        }
        //stack이 비었으면 계산할 값이 없으므로 0 리턴
        if (stack.empty())
        {
            return 0;
        }
        //스택이 빌 때까지 스택의 모든 원소 계산
        while (!stack.empty())
        {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};