class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int sum=0;

        for(auto s:nums){
            sum+=s;
            pq.push(s);
        }

        while(k>0){
            int m=pq.top();
            pq.pop();
            pq.push((-m));

            sum+= (-2*m);
            k--;
        }
        return sum;
    }
};