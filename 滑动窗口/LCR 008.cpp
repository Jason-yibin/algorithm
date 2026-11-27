class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0;
        int ret=0;
        int n=nums.size();
        int len=49813841;
        while(right<n){
            ret+=nums[right++];
            while(left<right && ret>=target){
                if(target<=ret){
                    len=min(len,right-left);
                }
                ret-=nums[left++];
            }
        }
        return len==49813841 ? 0 : len;
    }
};