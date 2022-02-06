/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/16/2018 13:55                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/586/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,k;
string s;
vector<pair<long,long> >v[5];
pair<long,long>p;
bool dfs(long cnt,pair<long,long>pos)
{
    if(pos.second>n)return true;
    long x=pos.first;
    long y=pos.second;
    for(auto a:v[x])
    {
        if(y>=a.first&&y<=a.second)return false;
        if(y+1>=a.first&&y+1<=a.second)return false;
    }
    for(long i=1;i<=3;i++)
    {
        for(long j=0;j<v[i].size();j++)
        {
            v[i][j].first-=2;
            v[i][j].second-=2;
        }
    }
    return dfs(cnt+1,pos.first,pos.second+1)|dfs(cnt+1,pos.first+1,pos.second+1)|dfs(cnt+1,pos.first-1,pos.second+1)
 }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(long i=1;i<=3;i++)
        {
            cin>>s;
            long st=0;
            for(long j=0;j<s.size();j++)
            {
                if(s[j]=='.'||s[j]=='s')
                {
                    if(s[j]=='s')p={i,j};
                    if(st!=0)v[i].push_back({st,i-1});
                    st=0;
                }
                else
                {
                    if(j==s.size()-1)
                    {
                        v[i].push_back({st,j});
                    }
                    if(st==0)st=j;
                }
            }
        }
        if(dfs(1,p))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}