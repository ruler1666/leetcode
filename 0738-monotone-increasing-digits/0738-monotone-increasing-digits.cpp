class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s= to_string(n);

        for(int i=s.size()-1;i>0;i--){
            if(s[i]<s[i-1]){
                s[i-1]--;

                 for(int j=i;j<s.size();j++){
                s[j]='9';
            }
            }

           
        }
        return stoi(s);
    }
};