class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<pair<int,int>> arr,int lvl,int n){
        if(arr.empty())return -1;
        vector<pair<int,int>>next;

        for(int i=0;i<arr.size();i++){
            int x=arr[i].first;
            int y=arr[i].second;

            if(x==n-1 && y==n-1)return lvl;

            for(int dx=-1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){

                    if(dx==0 && dy==0)continue;
                    int nx=x+dx;
                    int ny=y+dy;

                    if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]==0){
                        grid[nx][ny]=1;
                        next.push_back({nx,ny});

                    }
                }
            }
        }
        return bfs(grid,next,lvl+1,n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<pair<int,int>> arr;
        arr.push_back({0,0});

        grid[0][0] = 1;

        return bfs(grid, arr, 1, n);

    }
};