class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> hash1;
        unordered_map<string,int> hash2;
        int newnike=0;
        for(auto& e:words){
            hash2[e]++;
            newnike++;
        }
        int left=0,right=0;
        int count=0;
        int n=s.size();
        vector<int> result;
        int len=words[0].size();
        for(int i=0;i<len;i++){
            left=right=i;
            count=0;
            hash1.clear();
            while(n-right>=len &&right<s.size()){
                if(hash1[string(s.begin()+right,s.begin()+right+len)]++<hash2[string(s.begin()+right,s.begin()+right+len)])
                    count++;
                while(count==newnike){
                    if(right-left+len==words.size()*len)
                        result.push_back(left);
                    if(hash1[string(s.begin()+left,s.begin()+left+len)]==hash2[string(s.begin()+left,s.begin()+left+len)]){
                        count--;
                    }
                    hash1[string(s.begin()+left,s.begin()+left+len)]--;
                    left+=len;
                }
                right+=len;
            }
        }
        return result;
    }
};