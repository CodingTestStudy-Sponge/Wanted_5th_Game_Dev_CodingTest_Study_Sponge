// 268. Missing Number
// https://leetcode.com/problems/missing-number/description/

//[0 , n]의 범위로 nums 배열이 주어지고, 해당 범위 내에 있는 숫자 중 유일하게 없는 숫자를 반환하는 문제
//n이 4면 배열에 0,1,2,3,4가 있어야 한다는 의미
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //비어있는 숫자 없이 온전한 배열 sum1의 합을 계산하고
        int sum1 = nums.size() * (nums.size() + 1) / 2;
        int sum2 = 0;
        //비어있는 숫자 하나가 있는 배열 sum2의 합을 계산해서
        for(int i = 0; i < nums.size(); ++i)
        {
            sum2 += nums[i];
        }
        //서로 빼면 없는 숫자가 나온다.
        return sum1 - sum2;
    }
};