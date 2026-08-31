class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        //1부터 9까지의 수가 몇개인지 담을 배열
        vector<int> count(10, 0);
        for (int i : digits)
        {
            //digits 순회하면서 0~9까지의 숫자가 나올때마다 인덱스 1증가
            count[i]++;
        }

        recursion(count, 0, 0);
        return result;
    }

    void recursion(vector<int> count, int number, int threeDigits)
    {
        //threeDigits가 3이면 각 자리수를 모두 채운거임
        if (threeDigits == 3)
        {
            //만약 짝수면 result에 push
            if (number % 2 == 0)
            {
                result.push_back(number);
            }
            //재귀 종료
            return;
        }
        for (int i = 0; i < 10; i++)
        {
            //만약 digits에 없는 숫자면 넘김
            if (count[i] == 0) continue;
            //만약 첫번째 숫자가 0이면 넘김
            if (threeDigits == 0 && i == 0) continue;
            //i숫자를 사용하면 -1
            count[i]--;
            recursion(count, number * 10 + i, threeDigits + 1);
            //여기까지 오면 조합을 모두 끝낸것이므로 숫자 반환
            count[i]++;
        }
    }

    vector<int> result = {};
};