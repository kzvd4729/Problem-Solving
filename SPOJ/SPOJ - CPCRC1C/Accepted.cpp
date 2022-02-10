/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-29 14:47:09                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-CPCRC1C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,l,dp[30][5][102];
vector<int>vec;
long dfs(int id,int ck,int sm)
{
    if(id==l&&ck==2)return 0;
    if(id>l)return 0;
    if(dp[id][ck][sm]!=-1)return dp[id][ck][sm];
    int i=0;
    if(id==1)i=1;
    long sum=0;
    for( ; i<=9; i++)
    {
        if(ck==0)sum+=sm+i+dfs(id+1,0,i+sm);
        else if(ck==1)
        {
            if(i<vec[id])sum+=sm+i+dfs(id+1,0,i+sm);
            else if(i==vec[id])sum+=sm+i+dfs(id+1,1,i+sm);
            else if(id!=l)sum+=sm+i+dfs(id+1,2,i+sm);
        }
        else sum+=sm+i+dfs(id+1,2,i+sm);
    }
    return dp[id][ck][sm]=sum;
}
int main()
{
    while(cin>>a>>b)
    {
        if(a==-1&&b==-1)break;
        vec.clear();
        l=0;
        while(b)
        {
            vec.push_back(b%10);
            b/=10;
            l++;
        }
        vec.push_back(0);
        reverse(vec.begin(),vec.end());
        memset(dp,-1,sizeof(dp));
        long ans=dfs(1,1,0);
        vec.clear();
        l=0;
        a--;
        while(a)
        {
            vec.push_back(a%10);
            a/=10;
            l++;
        }
        vec.push_back(0);
        reverse(vec.begin(),vec.end());
        memset(dp,-1,sizeof(dp));
        cout<<ans-dfs(1,1,0)<<endl;
    }
    return 0;
}