class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();

            int diff =it.first;
            int r= it.second.first;
            int c =it.second.second;

            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};

            if(r==m-1 && c==n-1) return diff;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 &&nc>=0&& nr<m && nc<n){
                   int newdist = max(abs(heights[r][c]-heights[nr][nc]),diff);
                    if(newdist < dist[nr][nc]){
                        dist[nr][nc]=newdist;
                        pq.push({newdist,{nr,nc}});
                    }
                }
            }

        }
        return 0;
    }
};