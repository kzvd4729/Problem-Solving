/****************************************************************************************
*  @author: kzvd4729                                         created: 06/08/2021 22:13                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/make-array-strictly-increasing
****************************************************************************************/
class Solution 
{
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_set<int>st;
        for(auto x:arr1)st.insert(x);        
        for(auto x:arr2)st.insert(x);
                return (int)st.size()>=(int)arr1.size();
    }
};