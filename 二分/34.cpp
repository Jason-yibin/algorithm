class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        vector<int> ret;
        if(nums.size()==0){
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        //找左
        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        if(target==nums[left]){
            ret.push_back(left);
        }
        //找右
        left=0;
        right=nums.size()-1;
        while(left<right){
            int mid=(left+right+1)/2;
            if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid;
            }
        }
        if(nums[left]==target){
            ret.push_back(left);
        }
        if(ret.size()==0){
            ret.push_back(-1);
            ret.push_back(-1);
        }
        return ret;
    }
};
精简版：class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        const int last = static_cast<int>(nums.size()) - 1;
        int left = 0, right = last;

        // 找第一个 target
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if (nums[left] != target) return {-1, -1};
        const int first = left;

        // 从 first 开始找最后一个 target
        right = last;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return {first, left};
    }
};