/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-29 14:12:51                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-CPCRC1C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c,dp[30][5][100];
vector<int>vec;
long dfs(int id,int ck,int sm)
{
    if(id==c-1&&ck==2)return 0;
    if(id>=c)return 0;
    if(dp[id][ck][sm]!=-1)return dp[id][ck][sm];
    int i=0;
    if(id==0)i=1;
    long sum=0;
    for( ;i<=9;i++)
    {
        if(ck==0)sum=sum+i+sm+dfs(id+1,0,sm+i);
        else if(ck==1)
        {
            if(i<vec[id])sum=sum+i+sm+dfs(id+1,0,sm+i);
            else if(i==vec[id])sum=sum+i+sm+dfs(id+1,1,sm+i);
            else if(id!=c-1)sum=sum+i+sm+dfs(id+1,2,sm+i);
        }
        else sum=sum+i+sm+dfs(id+1,2,sm+i);
    }
    return dp[id][ck][sm]=sum;
}
int main()
{
    while(cin>>a>>b)
    {
        if(a==-1&&b==-1)break;
        c=0;
        vec.clear();
        while(b)
        {
            vec.push_back(b%10);
            b/=10;
            c++;
        }
        reverse(vec.begin(),vec.end());
        memset(dp,-1,sizeof(dp));
        long ans1=dfs(0,1,0);
        c=0;
        vec.clear();
        a--;
        while(a)
        {
            vec.push_back(a%10);
            a/=10;
            c++;
        }
        reverse(vec.begin(),vec.end());
        memset(dp,-1,sizeof(dp));
        long ans2=dfs(0,1,0);
        cout<<ans1-ans2<<endl;
    }
    return 0;
}