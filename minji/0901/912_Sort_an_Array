class Solution {
public:
    void MergeSort(vector<int>& array)
    {
        // 종료 조건: 사이즈 1보다 작으면 종료
        if(array.size() <= 1) return;

        // 중간값 찾아서 반반 재귀 돌리기 ㄱㄱ
        int middle = array.size()/2;
        int leftLength = middle;
        int rightLength = array.size() - middle;
         
        vector<int> leftArray;
        for(int i = 0; i< leftLength; i++)
            leftArray.emplace_back(array[i]);

        vector<int> rightArray;
        for(int i = middle; i< array.size(); i++)
            rightArray.emplace_back(array[i]);

        MergeSort(leftArray);
        MergeSort(rightArray);

        // 나눠진 배열 합치기(left 비교 / right비교)
        int originIndex = 0;
        int leftIndex = 0;
        int rightIndex = 0;
        while(leftIndex < leftLength && rightIndex < rightLength)
        {
            // 왼쪽이 작으면 왼쪽 먼저 ㄱㄱ 하고 인덱스 올리기
            if(rightArray[rightIndex] > leftArray[leftIndex])
            {
                array[originIndex] = leftArray[leftIndex];
                leftIndex++;
            }
            else
            {
                array[originIndex] = rightArray[rightIndex];
                rightIndex++;
            }
            originIndex++;
        }
        // 남은 리스트 정리
        while(leftIndex < leftLength)
        {
            array[originIndex] = leftArray[leftIndex];  
            originIndex++;
            leftIndex++;
        }
        while(rightIndex < rightLength)
        {
            array[originIndex] = rightArray[rightIndex];
            originIndex++;
            rightIndex++;
        }

        
    }
    vector<int> sortArray(vector<int>& nums) {
        // 병합 정렬
        // 중간값 찾기
        MergeSort(nums);

        return nums;
    }
};
