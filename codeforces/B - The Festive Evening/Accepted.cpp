/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/30/2017 21:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 4800 KB                              
*  problem: https://codeforces.com/contest/834/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,last[30],vis[30],i;
int main()
{
    cin>>n>>k;
    cin>>s;
    for(i=0;i<n;i++)
    {
        last[(int)(s[i]-'A')]=i;
    }
    int cnt=0;
    for(i=0;i<n;i++)
    {
        if(vis[(int)(s[i]-'A')]==0)
        {
            cnt++;
            vis[(int)(s[i]-'A')]=1;
            if(cnt>k)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
        if(last[(int)(s[i]-'A')]==i)cnt--;
    }
    cout<<"NO"<<endl;
     return 0;
}