class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int count=0;

        for(auto c:s){
            mp[c]++;
        }
        int odds=0;
        int evens=0;

        for(auto s :mp){
            if(s.second%2==0){
                count+=s.second;
                evens++;
            }else{
                count+=s.second-1;
                odds++;
            }
        }

        if(odds>=1)return count+1;

        return count;
    }
};