
//547. 省份数量
//1.DFS
class Solution {
public:
    void dfs(vector<vector<int>>& isconnected, vector<int> &visited, const int provinces, int i) {
        //j变化-->遍历每一列
        for (int j = 0; j < provinces; ++j) {
            if (isconnected[i][j] == 1 && !visited[j]) {
                visited[j] = 1;
                //i变化-->遍历每一行
                dfs(isconnected, visited, provinces, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = isConnected.size();
        vector<int> visited(provinces, 0);
        int circles = 0;
        //纵向遍历
        for (int i = 0; i < provinces; ++i) {
            if (!visited[i]) {
                visited[i] = 1;
                dfs(isConnected, visited, provinces, i);
                ++circles;
            }
        }
        return circles;
    }
};
