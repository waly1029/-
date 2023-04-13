class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;

        // 当前覆盖范围
        int cur = 0;
        // 下一部覆盖范围
        int next = 0;
        int result = 0;

        // 最少的步数增加最大覆盖范围
        for(int i=0; i<nums.size(); ++i) {
            next = max(i+nums[i], next);
            if(i==cur) {
                if(cur!=nums.size()-1) {
                    result++;
                    cur = next;
                    if(cur>=nums.size()-1)
                        break;
                } else break;
            }
        }
        return result;
    }
};
