class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 两个维度分别考虑

        // 先进行对身高从大到小，以及人数从小到大的排序
        sort(people.begin(), people.end(), cmp);
        // for(auto x: people)
        //         cout << x[0] << x[1] << ' ';
        // cout << endl;
        vector<vector<int>> result;
        for(int i=0; i<people.size(); ++i) {
            // 在根据人数排序
            int position = people[i][1];
            result.insert(result.begin()+position, people[i]);
            // for(auto x: result)
            //     cout << x[0] << x[1] << ' ';
            // cout << endl;
        }

        return result;
    }

    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[0]>v2[0] || (v1[0]==v2[0] && v1[1]<v2[1]);
    }
};
