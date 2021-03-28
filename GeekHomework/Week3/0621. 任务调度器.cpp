
//621. 任务调度器

//当正在调度的任务处于待命状态时，查找其他数量最多的任务执行
//填桶法
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> tasknum(26, 0);
        //统计各类型任务数量
        for(char c : tasks) {
            ++tasknum[c - 'A'];
        }
        //获取总数最大的任务 的总数
        int maxnum = 0;
        for(int num : tasknum) {
            maxnum = max(num, maxnum);
        }
        //统计总数为最大的任务 有几种
        int maxcnt = 0;
        for(int num : tasknum){
            if(num == maxnum){
                ++maxcnt;
            }
        }
        return max(len, (maxnum - 1)*(n + 1) + maxcnt);
    }
};

