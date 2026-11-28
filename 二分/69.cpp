class Solution {
public:
    int mySqrt(int x) {
        if(x<1){
            return 0;
        }
        int left=1;
        int right=x;
        long long ret=0;//不用long long 会溢出
        while(left<right){
            ret=left+(right-left+1)/2;
            if(ret*ret>x){
                right=ret-1;
            }
            else{
                left=ret;
            }
        }
        return left;
    }
};