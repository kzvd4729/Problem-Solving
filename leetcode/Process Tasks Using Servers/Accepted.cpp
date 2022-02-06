/****************************************************************************************
*  @author: kzvd4729                                         created: 05/30/2021 20:00                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 716 ms                                          memory_used: 211.5 MB                             
*  problem: https://leetcode.com/problems/process-tasks-using-servers
****************************************************************************************/
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) 
    {
      set<pair<int,int> >st,wt;int n=servers.size(),m=tasks.size();
      for(int i=0;i<n;i++)st.insert({servers[i],i});
      vector<int>ans(m);
      int tm=0;
      for(int i=0;i<m;i++)
      {
        tm=max(tm,i);
        if((int)st.size()==0)tm=max(tm,wt.begin()->first);
        while((int)wt.size() && wt.begin()->first<=tm)
        {
          pair<int,int>p=*wt.begin();wt.erase(p);
          st.insert({servers[p.second],p.second});
        }
        pair<int,int>p=*st.begin();st.erase(p);
        ans[i]=p.second;
        wt.insert({tm+tasks[i],p.second});
      }
      return ans;
    }
};