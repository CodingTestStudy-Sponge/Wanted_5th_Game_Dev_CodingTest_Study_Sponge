#include <queue>

using namespace std;
/*
LeetCode 2073. Time Needed to Buy Tickets
Input: tickets [2,3,2] k = 2 / Output: 6
Input: tickets = [5,1,1,1], k = 0 / Output: 8
티켓을 사기 위해 줄을 서 있는 n명의 사람들이 있고,
0번째 사람은 줄의 맨 앞에, (n - 1)번째 사람은 줄의 맨 뒤에 있습니다.
길이가 n인 0부터 인덱스가 매겨진 정수 배열 tickets가 주어지며,
여기서 i번째 사람이 구매하고자 하는 티켓 수는 tickets[i]입니다.
각 사람은 티켓을 사는 데 정확히 1초가 걸립니다. 사람은 한 번에 티켓을 한 장만 살 수 있고,
더 많은 티켓을 사려면 줄의 맨 뒤로 돌아가야 합니다(이 과정은 즉시 일어납니다).
누군가가 더 살 티켓이 전혀 없으면, 그 사람은 줄을 떠날 것이다.
처음에 k 위치(0부터 시작)에 있던 사람이 티켓 구매를 완료하는 데 걸린 시간을 반환하세요.
*/

class Solution
{
public:
    int timeRequiredToBuy(vector<int>& tickets, int k)
    {
        // 티켓 큐
        queue<int>Ticket;

        // 사람 인덱스 큐
        queue<int>People;

        for (int ix = 0; ix < tickets.size(); ++ix)
        {
            Ticket.push(tickets[ix]);
            People.push(ix);
        }

        // 걸린 시간 카운트
        int takingTimeCount = 0;

        while (!Ticket.empty())
        {
            // 티켓 한장 구매 반영
            int temp = Ticket.front() - 1;

            // 인덱스 
            int index = People.front();

            // 티켓 저장 후 제거
            Ticket.pop();

            // 인덱스 저장 후 제거
            People.pop();

            // 걸린 시간 추가
            takingTimeCount++;

            // 종료 조건 현재 사람이 k 이고, 티켓을 다 샀으면
            if (index == k)
            {
                if (temp == 0)
                {
                    break;
                }
            }

            // 티켓이 아직 남아 있으면
            if (temp > 0)
            {
                // 저장한 티켓 수 푸쉬
                Ticket.push(temp);

                // 인덱스도 푸쉬
                People.push(index);
            }
        }
        // 걸린 시간 반환
        return takingTimeCount;
    }
};
