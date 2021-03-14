
//189. 旋转数组

//解法一：deque
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //cache
        deque<int> res;
        int i=0,tmp=0,size = nums.size();
        for(i=0;i<size;++i){
            res.push_back(nums[i]);
        }
        //rotate
        for(i=0;i<k;++i){
            tmp = res.back();
            res.pop_back();
            res.push_front(tmp);
        }
        nums.clear();
        nums.insert(nums.begin(),res.begin(),res.end());
    }
};


