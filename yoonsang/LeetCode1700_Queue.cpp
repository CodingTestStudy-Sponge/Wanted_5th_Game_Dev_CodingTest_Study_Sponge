#include <queue>

using namespace std;
/*
https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=problem-list-v2&envId=queue
LeetCode 1700. Number of Students Unable to Eat Lunch
Input: students = [1,1,0,0], sandwiches = [0,1,0,1] / Output: 0
Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1] / Output: 3
학교 식당에서는 점심시간에 원형 샌드위치와 사각형 샌드위치를 제공하며, 각각 0번과 1번으로 불립니다.
모든 학생들은 줄을 서서 서 있다. 각 학생은 정사각형 샌드위치나 원형 샌드위치 중 하나를 선호합니다.
식당에 있는 샌드위치의 수는 학생 수와 같습니다. 샌드위치들은 쌓여 있다. 각 단계에서:
줄 맨 앞에 있는 학생이 쌓여 있는 샌드위치 중 맨 위에 있는 것을 선호한다면, 그 학생은 그것을 가져가고 줄을 떠날 것입니다.
그렇지 않으면, 그들은 그것을 남겨두고 대기열의 끝으로 갈 것입니다.
이 과정은 줄 선 학생들 중 누구도 맨 위 샌드위치를 먹고 싶어 하지 않아 결국 먹지 못할 때까지 계속됩니다.
두 개의 정수 배열 students와 sandwiches가 주어집니다.
sandwiches[i]는 스택에서 i번째 샌드위치의 종류이고(i=0은 스택의 맨 위를 의미),
students[j]는 초기 큐에서 j번째 학생의 선호 순서입니다(j=0은 큐의 맨 앞을 의미).
식사를 할 수 없는 학생의 수를 반환하세요.
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        // 학생들의 샌드위치 큐
        queue<int> Student;

        for (int ix = 0; ix < students.size(); ++ix)
        {
            // 큐에 먹고 싶은 샌드위치 넣기
            Student.push(students[ix]);
        }
        // 탈출 조건
        int CountPeople = 0;
        // 순회를 위한 인덱스
        int index = 0;
        while (!Student.empty())
        {
            // 샌드위치 값 
            int indexSandwiche = sandwiches[index];

            // 푸쉬를 위한 저장
            int tempStudent = Student.front();

            // 내가 먹고싶은 샌드위치면
            if (tempStudent == indexSandwiche)
            {
                // 가지고 가
                Student.pop();
                // 다음 사람
                index++;
                // 탈출 조건 초기화
                CountPeople = 0;
            }

            // 먹기 싫은 샌드위치면
            else
            {
                // 줄 다시 서기 위해 나가기
                Student.pop();
                // 줄 다시 서기
                Student.push(tempStudent);
                // 탈출 조건 증가
                CountPeople++;
                
                // 탈출 조건과 못 먹은 사람이 같아지면 탈출
                if (CountPeople == Student.size())
                {
                    break;
                }
            }
        }
        // 못 먹은 사람의 수 반환
        return Student.size();
    }
};
