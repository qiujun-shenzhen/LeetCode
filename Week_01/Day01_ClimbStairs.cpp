
class Solution {
public:
    int climbStairs(int n) {
        int c1 = 0, c2 = 0, sum = 1;
        //斐波拉契数列：f(x)=f(x-1)+f(x-2)
        for(int i = 1; i <= n; ++i){
            c2 = c1;      //f(x-2)
            c1 = sum;     //f(x-1)
            sum = c1 + c2;
        }
        return sum;
    }
};

