/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/16/2017 22:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/898/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x;
string s,ss;
map<string,vector<string> >mp,ans;
map<string,long>vis;
bool cmp(string a,string b)
{
    return a.size()>b.size();
}
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>s;
        cin>>x;
        while(x--)
        {
            cin>>ss;
            mp[s].push_back(ss);
        }
    }
    for(map<string,vector<string> >::iterator it=mp.begin();it!=mp.end();it++)
    {
        vector<string>v=it->second;
        mp[it->first].clear();
        sort(v.begin(),v.end(),cmp);
        vis.clear();
        for(auto z:v)
        {
            if(vis[z]==0)
            {
                mp[it->first].push_back(z);
                long l=z.size();
                for(long i=0;i<l;i++)
                {
                    vis[z.substr(i,l-i)]=1;
                }
            }
        }
    }
    cout<<mp.size()<<endl;
    for(map<string,vector<string> >::iterator it=mp.begin();it!=mp.end();it++)
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