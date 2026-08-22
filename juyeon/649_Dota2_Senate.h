#pragma once

#include <string>
#include <queue>

using namespace std;

// 649. Dota2 Senate(Medium)
class Solution
{
public:
	string predictPartyVictory(string senate)
	{
		//0 == 'R', 1 == 'D'
		queue<int> partyQueue[2];

		/* 문자별로 팀의 큐에 집어 넣음 */
		const int length = static_cast<int>(senate.length());
		for (int i = 0; i < length; ++i)
		{
			partyQueue[senate[i] == 'R' ? 0 : 1].push(i);
		}

		/* 상대 팀을 밴하고 현재 파티인원의 순서 조정 람다식 */
		auto anotherTeamBan = [&partyQueue, length](const int currentTeam, 
													const int anotherTeam,
													const int currentOrder)
			{
				/* 상대 파티 인원 밴 */
				partyQueue[anotherTeam].pop();

				/* 현재 파티 인원은 다시 뒤로 돌아가서 순번 대기*/
				partyQueue[currentTeam].pop();
				partyQueue[currentTeam].push(currentOrder + length);
			};

		//두 파티인원이 모두 존재하는 동안 반복
		while (!partyQueue[0].empty() && !partyQueue[1].empty())
		{
			const int radiantOrder = partyQueue[0].front();
			const int direOrder = partyQueue[1].front();

			/* R 파티 인원의 순서가 D 파티 인원의 순서보다 앞일 때 */
			if (radiantOrder < direOrder)
			{
				/* D 파티 인원을 밴하고 R 파티 인원은 뒤에서 순번 대기 */
				anotherTeamBan(0, 1, radiantOrder);
			}
			else
			{
				/* R 파티 인원을 밴하고 D 파티 인원은 뒤에서 순번 대기 */
				anotherTeamBan(1, 0, direOrder);
			}
		}

		/* R 파티의 큐가 비어있으면 D파티의 승리, 그게 아니면 R 파티의 승리 */
		return partyQueue[0].empty() ? "Dire" : "Radiant";
	}
};

