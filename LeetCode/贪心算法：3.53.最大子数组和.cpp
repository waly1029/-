class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int countSum = 0;

        for(int i=0; i<nums.size(); ++i) {
            countSum += nums[i];
            if(countSum>result) result = countSum;
            if(countSum<0) countSum = 0;
        }
        return result;
    }
};
