
//647. 回文子串

//解法一 中心扩展法
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < 2 * n - 1; ++i){
            //中心，可能是1个字符或者两个字符
            int l = i / 2, r = i / 2 + i % 2;
            //仍是回文则向两边扩展
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++res;  //s[l] == s[r]则发现了1个新回文
            }
        }
        return res;
    }
};

