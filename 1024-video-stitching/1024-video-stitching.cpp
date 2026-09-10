class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int current=0;
        int farthest=0;
        int count=0;

        for(int i=0;i<clips.size();i++){
            int j=i;
            while(j<clips.size() && clips[j][0]<=current){
                farthest=max(farthest , clips[j][1]);
                j++;
            }
            if(farthest==current)
                return -1;

            current=farthest;
            count++;
            if(current >=time)return count;

            i=j-1;
        }
        return -1;
    }
};