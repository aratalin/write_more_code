class Solution {
public:
    string longestPalindrome(string s) {
        string ref_string(s.size() * 2 + 2, '#'); // 交叉放入#，避免奇偶性检查。
        ref_string[0] = '$';
        for(int i = 0; i < s.size(); i++){
            ref_string[(i << 1) + 2] = s[i];
        }
        vector<int> p = vector<int>(ref_string.size());
        int max_pos = 0, id = 0;
        int ans_id = 1;
        for(int i = 1; i < ref_string.size(); i++){
            p[i] = 1;
            if (i < max_pos){  
                // i 与 id*2-i对称，画一下。
                p[i] = min(p[id * 2 - i], max_pos - i + 1);
            } // 尝试延展p[i]，写的时候要模拟一下
            while(i + p[i] < ref_string.size() && i - p[i] > 0 && ref_string[i+p[i]] == ref_string[i-p[i]]){
                
                p[i] ++;
            }
            if (i + p[i] - 1 > max_pos){
                max_pos = i + p[i] - 1;
                id = i;
            }
            if(p[i] > p[ans_id]){
                ans_id = i;
            }
        }
        // 结果的长度是p[ans_id]-1，画一下
        // 推导起始的非#的点，模拟一下
        int start_pos = max(0, (ans_id - p[ans_id]  + 1 + 1 - 2) >> 1);
        
        return s.substr(start_pos, p[ans_id] - 1);
    }
};