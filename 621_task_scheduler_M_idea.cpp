class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26, 0);
        for(auto t: tasks){
            f[t - 'A'] ++;
        }
        int m = 0, mct = 0;
        for(auto i : f){
            if(i > m){
                m = i;
                mct = 0;
            }
            if(i == m){
                mct ++;
            }
        }
        int ans = (m - 1)*(n + 1) + mct;
        return max(ans, int(tasks.size()));
    }
};