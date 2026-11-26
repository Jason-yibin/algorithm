class Solution {
public:
    string minWindow(string s, string t) {
        int count=0;
        int n=s.size();
        int hash1[128]={0};
        int hash2[128]={0};
        int newnike=0;
        for(auto& e:t){
            hash2[e]++;
            if(hash2[e]==1)
                newnike++;

        }
        string result;
        int left=0,right=0,len=100000000;
        while(right<n){
            if(++hash1[s[right]]==hash2[s[right]])
                count++;
            right++;
                while(count==newnike){
                     if(right-left<len){
                    result=string(s.begin()+left,s.begin()+right);
                    len=right-left;
                }
                    if(hash1[s[left]]==hash2[s[left]]){
                        count--;
                    }
                    hash1[s[left]]--;
                    left++;
                }
            }
        return result;
    }
};