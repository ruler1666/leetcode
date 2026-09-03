class Solution {
public:
    int balancedStringSplit(string s) {
        unordered_map<char,int>mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        if(mp['R']!=mp['L'])return 0;
        int count=0;

        for(int i=0;i<s.size();i++){
            if(mp['R']==mp['L'])count++;
            mp[s[i]]--;
        }
        return count;
    }
};