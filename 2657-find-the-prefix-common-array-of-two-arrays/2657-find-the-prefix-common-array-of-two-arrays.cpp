class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp1,mp2;
        vector<int>ans;
        int n=A.size();
        
        for(int i=0;i<A.size();i++){
            mp1[A[i]]=i;
        }
        for(int i=0;i<B.size();i++){
            mp2[B[i]]=i;
        }
        
        int i=0;
        while(i<n){
            int count=0;
            for(int j=0;j<=i;j++){
                if(mp2.find(A[j])!=mp2.end() &&mp2[A[j]]<=i){
                    count++;
                }
            }
            ans.push_back(count);
            i++;
        }

        return ans;

    }
};