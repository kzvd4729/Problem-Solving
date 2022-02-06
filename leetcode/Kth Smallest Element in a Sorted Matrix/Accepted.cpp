/****************************************************************************************
*  @author: kzvd4729                                         created: 07/07/2021 14:42                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 80 ms                                           memory_used: 13.3 MB                              
*  problem: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix
****************************************************************************************/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) 
    {
        int n=a.size();
        vector<int>pt(n,0);
                priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >p;
                for(int i=0;i<n;i++)p.push({a[i][pt[i]],i});
                while(k>1)
        {   
            int row=p.top().second;p.pop();
                        pt[row]++;
                        if(pt[row]<n)
            {
                p.push({a[row][pt[row]],row});
            }
                        k--;
        }
        return p.top().first;
    }
};