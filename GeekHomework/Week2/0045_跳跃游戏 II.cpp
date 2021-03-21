
//解法一
//贪心策略：跳到 能使本次和下次跳跃总和最大 的位置
//*选取本次和下次跳跃最大的组合
class Solution {
public:
	static int jump(vector<int>& nums) {
		int tar = nums.size()-1;
        int step = 0, sum = 0, jump = 0;
        //到达tar即可
		for (int pos = 0; pos < tar; pos += jump) {
			sum = jump = 0;
			for (int first = 0; first <= nums[pos]; ++first) {
				//寻找最大组合 得到最佳first
				if (pos + first < tar) {
					//first:第1步;      nums[i + j]:第2步
					if (first + nums[pos + first] > sum) {
						sum = first + nums[pos + first];
						jump = first;
					}
				}
				else {
					jump = first;
					break;
				}
			}
			++step;
		}
		return step;
	}
};

