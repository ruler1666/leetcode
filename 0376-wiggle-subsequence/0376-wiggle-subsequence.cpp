class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>arr;

        for(int i=0;i<nums.size()-1;i++){
           arr.push_back(nums[i]-nums[i+1]);
        }

        int maxi=0;
        int count=1;
        int low=0;
        int high=1;

        while(high<arr.size()&& low<arr.size()){
            if(arr[low]==0){low++;continue;}
            if(arr[high]==0){ high++ ;continue;}
            while(  high <arr.size() && ((arr[low]<0 && arr[high]>0) || (arr[low]>0&&arr[high]<0))){
               count++;
                low=high;
                high++;
                while(high<arr.size() && arr[high]==0)
                    high++;
            }

            maxi=max(maxi,count);
            if(high<arr.size()){
                low=high;
            high++;
            }
            
        }
       for(int x : arr){
            if(x != 0)
                return max(maxi,count) + 1;
        }

        return 1;
    }
};