
//50. Pow(x, n)

//解法一：递归（DFS）
class Solution {
public:
    double quickMul(double x, long n){
        if (0 == n) {
            return 1.0;
        }
        double tmp = quickMul(x , n / 2);
        return (0 == n % 2) ? tmp * tmp : x * tmp * tmp;
    }

    double myPow(double x, int n) {
        //使用int保存不了求反结果
        long N = n;
        return (N > 0) ? quickMul(x, N) :  1 / quickMul(x, -N);
    }
};

/////////////////////////////////////////////////////////////////////////////




