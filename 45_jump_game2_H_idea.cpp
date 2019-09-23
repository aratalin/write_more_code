class Solution {
public:
    int jump(vector<int>& nums) {
        int nowStep = 0, nowPos = 0, farPos = 0, nextFarPos = 0;
        while(nowPos < nums.size()){
            if(farPos + 1>= nums.size()) break;
            nextFarPos = max(nextFarPos, nowPos + nums[nowPos]);
            if(farPos == nowPos){
                nowStep ++;
                farPos = nextFarPos;
            }
            
            nowPos ++;
        }
        return nowStep;
    }
};