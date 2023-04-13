class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 两次贪心选择
        // 1. 优先负数取反
        // 2. 都是正数之后找最小
        int result = 0;
        sort(nums.begin(), nums.end(), cmp);

        // 第一次贪心
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i]<0 && k>0) {
                k--;
                nums[i] = -nums[i];
            }
        }

        // 第二次贪心
        if(k%2==1) nums[nums.size()-1] *= -1;

        for(int x: nums)
            result += x;

        return result;
    }

    // 由于成员函数需要一个对象实例才能被调用，因此编译器无法确定如何调用它。解决这个问题的方法是将成员函数转换为静态函数，或使用lambda表达式替代成员函数。
    static bool cmp(int x, int y) {
        return abs(x) > abs(y);
    }
};
