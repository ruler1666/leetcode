class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back(abs(nums[i]));
        }
        sort(arr.begin(), arr.end());
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += 1LL * arr[i] * arr[i];
        }

        int n = arr.size();
        int k = n / 2;
        for(int i = 0; i < k; i++) {
            sum -= 1LL * 2*arr[i] * arr[i];
        }
        return sum;
    }
};