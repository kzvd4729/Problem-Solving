/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/31/2018 19:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 5800 KB                              
*  problem: https://codeforces.com/contest/919/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,k,cnt,ans;
string s;
char mat[2002][2002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            mat[i][j]=s[j-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        for(int j=1;j<=m;j++)
        {
            if(mat[i][j]=='.')cnt++;
            else cnt=0;
            if(cnt>=k)ans++;
        }
    }
    if(k==1)
    {
        cout<<ans<<endl;
        return 0;
    }
    for(int j=1;j<=m;j++)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(mat[i][j]=='.')cnt++;
            else cnt=0;
            if(cnt>=k)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}