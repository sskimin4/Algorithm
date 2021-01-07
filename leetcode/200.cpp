class Solution
{
public:
    int visit[300][300];
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    vector<vector<char>> island;
    void dfs(int x, int y)
    {
        if (visit[x][y])
            return;
        visit[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m)
                continue;
            if (visit[dx][dy] || island[dx][dy] == '0')
                continue;
            dfs(dx, dy);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int answer = 0;
        island = grid;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (visit[i][j] || grid[i][j] == '0')
                    continue;
                dfs(i, j);
                answer++;
            }
        }
        return answer;
    }
};