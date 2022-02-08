/****************************************************************************************
*  @author: kzvd4729                                         created: 24-02-2018 21:46:36                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.26 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/LTIME57/problems/BORDER
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,q,t,f,x,nm;
string ss,s;
vector<long>v[505];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(long i=1;i<=n;i++)v[i].clear();
        cin>>ss;
        for(long i=1;i<=n;i++)
        {
            s=ss.substr(0,i);
            for(long j=1;j<=s.size();j++)
            {
                f=0;
                for(long k=0,kk=s.size()-j;k<j;k++,kk++)
                {
                    if(s[k]!=s[kk])f=1;
                }
                if(!f)v[i].push_back(j);
            }
        }
        while(q--)
        {
            cin>>x>>nm;
            if(v[x].size()<nm)cout<<-1<<endl;
            else cout<<v[x][nm-1]<<endl;
        }
    }
    return 0;
}