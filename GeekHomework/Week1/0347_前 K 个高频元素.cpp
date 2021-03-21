
//347. 前 K 个高频元素

//解法一：unordered_map + priority_queue
class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计
        unordered_map<int,int> hash;
        for(auto& v:nums){
            ++ hash[v];
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> heap(cmp);
        for(auto& [num,cnt]:hash){
            //堆的size已经达到要求的k；
            if(k==heap.size()){
                //堆顶cnt比hash中cnt小
                if(heap.top().second < cnt){
                    //弹出堆中cnt最小元素，加入hash元素
                    heap.pop();
                    heap.emplace(num,cnt);
                }
            }else{
                heap.emplace(num,cnt);
            }
        }
        vector<int> res;
        while(!heap.empty()){
            res.emplace_back(heap.top().first);
            heap.pop();
        }
        return res;
    }
};

////////////////////////////////////////////////////////////////////////////


