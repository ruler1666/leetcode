class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n= tokens.size();
        priority_queue<int>maxi;
        priority_queue<int , vector<int>,greater<int>>mini;

        for(int i=0;i<n;i++){
            maxi.push(tokens[i]);
            mini.push(tokens[i]);
        }
        int count=0;
        int ans=0;

        while(!mini.empty()){
            int x = maxi.top();
            int y = mini.top();

            if(y<=power){
                power-=y;
                count++;
                mini.pop();
                ans=max(ans,count);

            }else if(count>=1){
                    power+=x;
                    count--;
                    maxi.pop();
            }else{
                break;
            }
        }

        return ans;
    }
};