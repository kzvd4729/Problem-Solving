/****************************************************************************************
*  @author: kzvd4729                                         created: 07/18/2021 15:50                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 24 ms                                           memory_used: 15 MB                                
*  problem: https://leetcode.com/problems/course-schedule-ii
****************************************************************************************/
class Solution {
public:
        vector<vector<int> >adj;
    vector<int>vs,tp;
        int f=1;
        void dfs(int nd)
    {
        if(vs[nd]==2)return ;
        if(vs[nd]==1){f=0;return ;}
                vs[nd]=1;
                for(auto x:adj[nd])dfs(x);
                vs[nd]=2;
        tp.push_back(nd);
            }
        vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        adj.resize(n);vs.resize(n,0);
                for(auto x:pre)
        {
            adj[x[0]].push_back(x[1]);
        }
                for(int i=0;i<n;i++)dfs(i);
                if(f==0)tp.clear();
                return tp;
            }
};