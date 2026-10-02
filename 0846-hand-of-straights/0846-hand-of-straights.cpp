class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0)return false;

        // sort(hand.begin(),hand.end());
        map<int ,int>mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        
        while(!mp.empty()){
            int k = mp.begin()->first;

            for(int i=0;i<groupSize;i++){
                int card = k + i;

                if(mp[card] == 0)
                    return false;

                mp[card]--;

                if(mp[card] == 0)
                    mp.erase(card);
            }
        }
        return true;
    }
};