class Solution {
public:
    typedef pair<int , pair<int , int>> PP;
    vector<vector<int>> dirs = {{0 , -1} , {0 , 1} , {-1 , 0} , {1 , 0}};
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP , vector<PP> , greater<>> boundaryCells;
        vector<vector<bool>> vis(m , vector<bool>(n , false));

        for (int row = 0; row < m; row++) {
            for (int col : {0 , n - 1}) {
                boundaryCells.push({heightMap[row][col] , {row , col}});
                vis[row][col] = true;
            }
        }

        for (int col = 0; col < n; col++) {
            for (int row : {0 , m - 1}) {
                boundaryCells.push({heightMap[row][col] , {row , col}});
                vis[row][col] = true;
            }
        }

        int totalWater = 0;
        while(!boundaryCells.empty()) {
            PP p = boundaryCells.top();
            boundaryCells.pop();

            int ht = p.first;
            int i = p.second.first;
            int j = p.second.second;

            for (vector<int>& dir : dirs) {
                int di = i + dir[0];
                int dj = j + dir[1];

                if (di >= 0 && di < m && dj >= 0 && dj < n && !vis[di][dj]) {
                    totalWater += max(ht - heightMap[di][dj] , 0);

                    boundaryCells.push({max(ht , heightMap[di][dj]) , {di , dj}});
                    vis[di][dj] = true;
                }
            }
        }
        return totalWater;
    }
};