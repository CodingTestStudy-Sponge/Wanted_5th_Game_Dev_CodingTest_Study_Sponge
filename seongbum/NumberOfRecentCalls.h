#pragma once
#include <queue>
//#933. Number of Recent Calls
//https://leetcode.com/problems/number-of-recent-calls/description/

//
//RecentCounter특정 기간 내 최근 요청 횟수를 계산하는 클래스가 있습니다 .
//
//해당 RecentCounter클래스를 구현하세요 :
//
//RecentCounter()최근 요청 수를 0으로 초기화합니다.
//int ping(int t)특정 시점(밀리초 단위의 시간)에 새로운 요청을 추가하고 t, t지난 밀리초 동안 발생한 요청 수 3000(새로운 요청 포함)를 반환합니다.구체적으로, 특정 범위(초) 내에 발생한 요청 수를 반환합니다[t - 3000, t].
//모든 호출에서 사용되는 값은 이전 호출에서 사용된 값보다 엄격하게 더 크다는 것이 보장 됩니다.pingt
//
//
//
//예시 1:
//
//입력
//["RecentCounter", "ping", "ping", "ping", "ping"]
//[[], [1], [100], [3001], [3002]] 출력
//[null, 1, 2, 3, 3] 설명
//RecentCounter recentCounter = new RecentCounter();
//recentCounter.ping(1); // 요청 = [ 1 ], 범위는 [-2999,1], 반환값 1 
//recentCounter.ping(100); // 요청 = [ 1 , 100 ], 범위는 [-2900,100], 반환값 2 
//recentCounter.ping(3001); // 요청 = [ 1 , 100 , 3001 ], 범위는 [1,3001], 반환값 3 
//recentCounter.ping(3002); // 요청 수 = [1, 100 , 3001 , 3002 ], 범위는 [2, 3002]이므로 3을 반환합니다.
//
//
//
//
//
//제약 조건 :
//
//1 <= t <= 109
//각 테스트 케이스는 엄격하게 증가하는 값 ping으로 호출됩니다.t
//대부분의 경우 전화는 로 걸려올 것입니다 .104ping


class RecentCounter {
public:
    RecentCounter() {
        //요청 수 초기화
        que = {};
    }

    int ping(int t) {
        //ping 호출 시 새로운 요청 큐에 추가
        que.push(t);
        //큐에서 [t-3000, t] 사이의 요청 개수를 반환, 어차피 t는 ping 호출한 시점에서 자기 자신이 들어가므로 우리는 큐에서 t-3000 이하인 것만 pop 해주면 된다. 
        while (!que.empty() && que.front() < t - 3000)
        {
            que.pop();
        }
        //큐의 size는 [t-3000, t] 사이의 요청 개수가 된다.
        return que.size();
    }

    std::queue<int> que;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */