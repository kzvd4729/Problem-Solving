/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-27 16:30:18                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11450
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int money,shop;
vector<int>v[30];
int dp[30][99999];
int fx(int g,int m)
{
    int x,i;
    if(g==shop)
    {
        return m;
    }
    if(dp[g][m]!=-1)return dp[g][m];
    x=0;
    for(i=0;i<v[g].size();i++)
    {
        if((v[g][i]+m)<=money)
        {
            x=max(x,fx(g+1,m+v[g][i]));
        }

    }
    dp[g][m]=x;
    return x;
}
int main()
{
    int t,i,j,p,k,q;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>money>>shop;
            for(i=0;i<shop;i++)
            {
                cin>>k;
                for(j=0;j<k;j++)
                {
                    cin>>p;
                    v[i].push_back(p);
                }
            }
            memset(dp,-1,sizeof(dp));
            q=fx(0,0);
            if(q==0)cout<<"no solution"<<endl;
            else cout<<q<<endl;

        }
    }
    return 0;
}