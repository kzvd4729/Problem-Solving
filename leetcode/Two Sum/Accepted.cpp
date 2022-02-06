/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 00:29                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 20 ms                                           memory_used: 10.7 MB                              
*  problem: https://leetcode.com/problems/two-sum
****************************************************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> imap;
        for (int i = 0;; ++i) {
        auto it = imap.find(target - nums[i]);
                if (it != imap.end()) 
            return vector<int> {i, it->second};
                    imap[nums[i]] = i;
    }
}
};