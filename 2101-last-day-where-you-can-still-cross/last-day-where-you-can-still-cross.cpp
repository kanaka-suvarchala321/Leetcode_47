

class Solution {
    int R, C;
    vector<int> dx{1,-1,0,0}, dy{0,0,1,-1};

    bool canCross(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(R, vector<int>(C, 0));
        for (int i = 0; i < day; i++)
            grid[cells[i][0]-1][cells[i][1]-1] = 1;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(R, vector<int>(C, 0));

        for (int j = 0; j < C; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == R-1) return true;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
                    !vis[nx][ny] && grid[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        R = row; C = col;
        int lo = 1, hi = cells.size(), ans = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canCross(mid, cells)) {
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return ans;
    }
};