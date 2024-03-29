class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int ans = 0;
        while(z){
            ans ++;
            z -= (z & -z);
        }
        return ans;
    }
};