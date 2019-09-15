class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        for(auto x: nums){
            if(!f.count(x)) f[x] = 0;
            f[x] += 1;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp>pq;
        for(auto x : f){
            if(pq.size() < k){
                pq.push(make_pair(x.first, x.second));
            }else{
                if(pq.top().second < x.second) {
                    pq.pop();
                    pq.push(make_pair(x.first, x.second));
                }
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            auto x = pq.top(); pq.pop();
            ans.push_back(x.first);

        }
        return ans;
    }
};