/****************************************************************************************
*  @author: kzvd4729                                         created: 06/08/2021 22:47                         
*  solution_verdict: Time Limit Exceeded                     language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/make-array-strictly-increasing
****************************************************************************************/
const int inf=1e9;
int dfs(vector<int>&a, vector<int>&b,int i,int j,int f)
{
    if(i==(int)a.size())return 0;
        int ret=inf;
    if(f==0)
    {
        if(j<(int)b.size())ret=min(ret,dfs(a,b,i,j+1,0));
        if(a[i]>a[i-1])ret=min(ret,dfs(a,b,i+1,j,0));
        if(j<(int)b.size() && b[j]>a[i-1])ret=min(ret,1+dfs(a,b,i+1,j+1,1));
    }
    else
    {
        if(j<(int)b.size())ret=min(ret,1+dfs(a,b,i+1,j+1,1));
        if(a[i]>b[j-1])ret=min(ret,dfs(a,b,i+1,j,0));
    }
    return ret;
}
class Solution 
{
public:
    int makeArrayIncreasing(vector<int>&a, vector<int>&b) 
    {
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        //for(auto x:b)cout<<x<<" ";cout<<endl;
                int ans=min(dfs(a,b,1,0,0),1+dfs(a,b,1,1,1));
        if(ans==inf)ans=-1;
                return ans;
    }
};