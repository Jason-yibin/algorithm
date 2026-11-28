class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left=0,len=0;
        int n=nums.size();
        int right=0;
        int sum=0;
        for(auto& v:nums){
            sum+=v;
        }
        if(sum==x)
            return n;
        int target=sum-x;
        int ret=0;
        while(right<n){
            ret+=nums[right++];
            while(left<right&&ret>=target){
                if(ret==target){
                    len=max(right-left,len);
                }
                ret-=nums[left++];
            }
        }
        return len==0 ? -1: n-len;
    }
};