/****************************************************************************************
*  @author: kzvd4729                                         created: 07/18/2021 16:17                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 20 ms                                           memory_used: 13.8 MB                              
*  problem: https://leetcode.com/problems/course-schedule-ii
****************************************************************************************/
class Solution {
public:
        vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        vector<int>child(n,0);
        vector<int>par[n];
                for(auto x:pre)
        {
            child[x[0]]++;
            par[x[1]].push_back(x[0]);
        }
                queue<int>q;
                for(int i=0;i<n;i++)
        {
            if(child[i]==0)q.push(i);
        }
                vector<int>ord;
        while(q.size())
        {
            int u=q.front();q.pop();
                        if(child[u]!=0)break;
                        ord.push_back(u);
                        for(auto x:par[u])
            {
                child[x]--;
                if(child[x]==0)q.push(x);
            }
        }
                if(ord.size()!=n)ord.clear();
        return ord;
    }
};