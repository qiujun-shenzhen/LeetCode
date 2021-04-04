
//70. 爬楼梯

//DP
class Solution {
public:
    int climbStairs(int n) {
        int step1 = 1;
        int step2 = 2;
        if(n < 3){
            return 1 == n ? step1 : step2;
        }
        int end = 0;
        for(int i = 3; i <= n; ++i){
            end = step1 + step2;
            step1 = step2;
            step2 = end;
        }
        return end;
    }
};

