class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int currgas =0;
        int tgas=0;
        
        for(int i=start;i<gas.size();i++){
            currgas += gas[i]-cost[i];
            tgas+= gas[i]-cost[i];

            if(currgas<0){
                start=i+1;
               currgas=0;
            }
        }

        if(tgas<0)return -1;
        return start;
    }
};