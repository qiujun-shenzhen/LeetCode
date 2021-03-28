
//91. 解码方法

//解法 DP
//0-9
//1-26
//每个字符：单独使用，与前1字符组合
// s[i]=='0';s[i-1]=='1'||s[i-1]=='2'   dp[i] = dp[i-2] else dp[i] = 0
// s[i-1]=='1';                         dp[i] = dp[i-1] + dp[i-2]
// s[i-1]=='2';  s[i]=='1'-'6'          dp[i] = dp[i-1] + dp[i-2]
class Solution {
public:
    int numDecodings(string s) {
        if('0' == s[0]) return 0;
        int pre = 1, cur = 1;
        for(int i = 1; i < s.size(); ++i){
            int tmp = cur;
            if(s[i] == '0') {
                if(s[i-1] == '1' || s[i-1] == '2'){
                    cur = pre;
                }else{
                    return 0;
                }
            }else if( s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6') ){
                cur += pre;
            }
            pre = tmp;
        }
        return cur;
    }
};