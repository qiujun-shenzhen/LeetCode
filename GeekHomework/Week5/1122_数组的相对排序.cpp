
//1122. 数组的相对排序

//1.将arr1元素统计到哈希表中
//2.按arr2顺序从哈希表取数据到res
//3.取出剩余数据，排序，放入res
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> hash;
        for(int num : arr1){
            ++hash[num];
        }
        vector<int> res;
        for(int num : arr2){
            while(hash.find(num) != hash.end()){
                res.push_back(num);
                --hash[num];
                if(0 == hash[num]){
                    hash.erase(num);
                }
            }
        }
        vector<int> remain;
        while(hash.begin() != hash.end()){
            remain.push_back(hash.begin()->first);
            --hash.begin()->second;
            if(0 == hash.begin()->second){
                hash.erase(hash.begin()->first);
            }
        }
        sort(remain.begin(), remain.end());
        for(int num : remain){
            res.push_back(num);
        }
        return res;
    }
};
