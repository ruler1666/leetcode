class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int count=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(s[i]);
                i++;
            }else{
                if(st.empty()){
                     if(i + 1 < s.size() &&s[i+1]==')'){
                        count++;
                        i+=2;
                     }else{
                        count+=2;
                        i++;
                    }
                }else{
                     if(i + 1 < s.size() &&s[i+1]==')'){
                       st.pop();
                       i+=2;
                     }else{
                        st.pop();
                        count++;
                        i++;
                    }
                }
               
            }
        }
        count += st.size() * 2;

        return count;
    }
};