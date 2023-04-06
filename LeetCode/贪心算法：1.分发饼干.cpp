class Solution {
public:

// 局部最优：最大的饼干给最大的小孩
// 从而推出全局最优
// 不用严格证明，浪费时间
// 想不出来明显反例即可

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result = 0;
        int index = s.size()-1;
        for(int i=g.size()-1; i>=0; i--) {
            // 注意while中的判断顺序
            while(index>=0 && s[index]>=g[i]) {
                // cout << s[index] << endl;
                // cout << g[i] << endl;
                result++;
                index--;

                // 找到符合的就退出while，而且此时index不重置。
                // 从当前的index开始为下一次的g[i]服务
                break;
            }
        }

        return result;
    }

};
