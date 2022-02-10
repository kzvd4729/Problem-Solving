/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 18.18 points                            language: C++                                     
*  run_time: 1088 ms                                         memory_used: 4332 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int a[9],b[9],n,c,s,ans=1e9;
void dfs(int msk,int t,int ck,int inc)
{
    //cout<<msk<<" "<<t<<" "<<ck<<endl;getchar();
    if(ck>=c)
    {   
        ans=min(ans,t);return ;
    }
    for(int i=0;i<(1<<n);i++)
    {
        if((msk&i))continue;
        int cs=0,nc=0;
        for(int j=0;j<n;j++)
        {
            bool bl=(i&(1<<j));
            if(bl)cs+=a[j],nc+=b[j];
        }
        if(cs<=ck)dfs((msk|i),t+1,ck-cs+inc+nc,inc+nc);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>c>>s;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    dfs(0,0,0,s);cout<<ans<<endl;
    return 0;
}