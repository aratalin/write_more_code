class Solution {
public:
    bool over_flow(string test_string, string standard_string){
        if(test_string.length() < standard_string.length()) return false;
        return test_string > standard_string;
    }
    int reverse(int x) {
        string max_string = "2147483647", min_string = "2147483648";
        char tmp[12] = {'\0'};
        int ans = 0;
        int signal = x > 0 ? 1 : -1;
        int now = 0, length = 0;
        while(x){
            tmp[now] = '0' + abs(x % 10);
            x /= 10;
            now ++;
        }
        if(over_flow(string(tmp), signal > 0 ? max_string : min_string)) return 0;
        for(int i = 0; i < now; i++){
            ans = ans * 10 + (tmp[i] - '0'); 
        }
        return ans * signal;
    }
};