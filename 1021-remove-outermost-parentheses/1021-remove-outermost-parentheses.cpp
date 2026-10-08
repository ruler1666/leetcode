class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        unordered_set<int>se;
        string ans;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(st.empty())se.insert(i);  
                st.push(s[i]);
            }else{
                if(st.size()==1)se.insert(i);
                if(!st.empty()){
                    st.pop();
                }
            }
        }

        for(int i=0;i<s.size();i++){
            if(se.find(i)!=se.end()){
                continue;
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};