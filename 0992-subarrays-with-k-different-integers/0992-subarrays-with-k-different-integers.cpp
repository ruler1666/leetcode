class Solution {
public:
    int find(vector<int>& nums,int k){
         if(k == 0) return 0;
        int low=0,high=0;
        unordered_map<int,int>mp;
        int count=0;

        while(high<nums.size()){
            mp[nums[high]]++;

            while(mp.size()>k){
                mp[nums[low]]--;
                if(mp[nums[low]]==0){
                    mp.erase(nums[low]);
                }
                low++;
            }

            count +=high-low+1;
            high++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return find(nums, k)-find(nums,k-1);
    }
};