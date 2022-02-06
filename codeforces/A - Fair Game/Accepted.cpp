/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/25/2017 16:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/864/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,fre[102],cnt;
vector<long>v,v1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>x;
        fre[x]++;
    }
    for(long i=1; i<=100; i++)
    {
        if(fre[i])cnt++;
    }
    if(cnt!=2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(long i=1; i<=100; i++)
    {
        if(fre[i])
        {
            v.push_back(fre[i]);
            v1.push_back(i);
        }
    }
    if(v[0]!=v[1])cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        cout<<v1[0]<<" "<<v1[1]<<endl;
    }
      return 0;
}