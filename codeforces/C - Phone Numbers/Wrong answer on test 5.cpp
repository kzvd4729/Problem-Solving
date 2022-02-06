/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/16/2017 22:28                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/898/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
map<string,vector<string> >mp;
map<string,long>vis;
long n,x;
string s,ss;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    while(n--)
    {
        cin>>s;
        vis.clear();
        vector<string>v=mp[s];
        for(auto z:v)
        {
            long l=z.size();
            for(long i=0; i<l; i++)
            {
                vis[z.substr(i,l-i)]=1;
            }
        }
        cin>>x;
        while(x--)
        {
            cin>>ss;
            if(vis[ss]==0)
            {
                mp[s].push_back(ss);
                long l=ss.size();
                for(long i=0; i<l; i++)
                {
                    vis[ss.substr(i,l-i)]=1;
                }
            }
        }
    }
    cout<<mp.size()<<endl;
    for(map<string,vector<string> >::iterator it=mp.begin(); it!=mp.end(); it++)
    {
        cout<<it->first<<" ";
        vector<string>v=it->second;
        cout<<v.size()<<" ";
        for(auto z:v)
        {
            cout<<z<<" ";
        }
        cout<<endl;
    }
    return 0;
}