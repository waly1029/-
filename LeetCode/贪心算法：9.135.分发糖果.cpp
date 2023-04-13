class Solution {
public:
    int candy(vector<int>& ratings) {
        // 先确定一边在确定另一边
        // 1. 右边小孩比左边大
        // 2. 左孩子比有孩子大 从后向前
        int sum = 0;
        vector<int> c(ratings.size(), 1);

        // 从左向右，右边比左边大的情况
        for(int i=1; i<ratings.size(); ++i) {
            if(ratings[i]>ratings[i-1]) {
                c[i] = c[i-1] + 1;
            }
        }
        for(int x: c) cout << x << ' ';

        // 从右向左，左边比右边大的情况
        for(int i=ratings.size()-2; i>=0; --i) {
            if(ratings[i]>ratings[i+1]) {
                c[i] = max(c[i], c[i+1]+1);
            }
        }
        for(int x: c) sum += x;
        return sum;
    }
};
