class Solution {
public:
    const int inf = 0x3f3f3f3f;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int>::size_type item_count = nums1.size() + nums2.size();
        std::vector<int>::size_type mid_count = item_count >> 1;
        double ans = 0;
        
        std::vector<int>::size_type l = 0, r = min(nums1.size() + 1, mid_count + 1);
        while(l <= r){
            std::vector<int>::size_type mid = (l + r) >> 1;
            std::vector<int>::size_type nums2_left_bound = mid_count - mid;
            if (nums2_left_bound > nums2.size()) {
                l = mid + 1;
                continue;
            }
            int left_max = -inf;
            if (mid != 0){
                left_max = nums1[mid-1];
            }
            if (nums2_left_bound != 0){
                left_max = max(left_max, nums2[nums2_left_bound-1]);
            }
            
            int right_min = inf;
            if (mid < nums1.size()){
                right_min = nums1[mid];
            }
            if(nums2_left_bound < nums2.size()){
                right_min = min(right_min, nums2[nums2_left_bound]);
            }
            
            if(right_min >= left_max){
                if (item_count & 1){
                    ans = right_min;
                }else{
                    ans = (right_min + left_max) / 2.0;
                }
                return ans;
            }else if (mid != 0 && nums2_left_bound != nums2.size() && nums1[mid-1] > nums2[nums2_left_bound]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
    return ans;
    }
};