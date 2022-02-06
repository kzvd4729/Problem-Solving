/****************************************************************************************
*  @author: kzvd4729                                         created: 12/02/2019 21:57                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 24 ms                                           memory_used: 9.9 MB                               
*  problem: https://leetcode.com/problems/median-of-two-sorted-arrays
****************************************************************************************/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int a=nums1.size(),b=nums2.size();
      vector<int>c(a+b);
            merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),c.begin());
            if((a+b)%2)return c[(a+b)/2];
      else return (c[(a+b)/2]+c[(a+b)/2-1])/2.0;
            }
};