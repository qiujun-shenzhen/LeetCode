
//56. 合并区间

//按照左边界从小到大排序
//合并
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 0) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n; ++i) {
            //无重叠 merged为空 或 （最后的右边界小于原区间左边界）
            if (0 == res.size() || intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            } 
            //重叠 判断右边界
            else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            //无重叠 merged为空 或 （最后的右边界小于原区间左边界）
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            //重叠 判断右边界
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
*/

/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= res[res.size()-1][1] && intervals[i][1] > res[res.size()-1][1]) {
                res[res.size()-1][1] = intervals[i][1];
            } else if (intervals[i][0] > res[res.size()-1][1]){
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
*/
