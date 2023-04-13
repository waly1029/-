class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        int result = 1;
        // 先根据左边界进行排序
        sort(points.begin(), points.end(), cmp);
        // for(auto x: points)
        //     cout << x[0] << x[1] << "->";

        for(int i=1; i<points.size(); ++i) {
            // 当前位置的左边界大于前位置的右边界必须++
            if(points[i][0]>points[i-1][1])
                result++;
            // 当前位置和前位置有重叠情况下，更新当前位置的右边界
            // 更新的右边界供下次循环时判断使用
            else{
                points[i][1] = min(points[i-1][1], points[i][1]);
            }
        }


        return result;
    }

    static bool cmp(vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0];
    }
};
