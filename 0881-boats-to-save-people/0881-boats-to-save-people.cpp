class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int low=0;
        int count=0;
        int  high=people.size()-1;
 
        while(low<=high){
            if(people[low]+people[high]<=limit){
                low++;
            }
            high--;
            count++;
        }
        return count;
    }
};