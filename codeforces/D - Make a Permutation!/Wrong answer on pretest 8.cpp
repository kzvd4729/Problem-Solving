/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/25/2017 18:12                        
*  solution_verdict: Wrong answer on pretest 8               language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 8100 KB                              
*  problem: https://codeforces.com/contest/864/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[200004],fre[200004],ans[200005];
queue<long>q;
vector<long>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
        fre[arr[i]]++;
    }
    for(long i=1; i<=n; i++)
    {
        if(fre[i]==0)q.push(i);
    }
    cout<<q.size()<<endl;
    for(long i=1; i<=n; i++)
    {
        if(fre[arr[i]]>1)
        {
            long x=q.front();
            if(x<arr[i])
            {
                fre[arr[i]]--;
                arr[i]=x;
                fre[arr[i]]++;
                q.pop();
            }
        }
    }
    while(q.size())
    {
        long x=q.front();
        v.push_back(x);
        q.pop();
    }
    if(v.size()>=1)
    {
        for(long i=v.size()-1; i>=0; i--)
        {
            q.push(v[i]);
        }
    }
    for(long i=n; i>=1; i--)
    {
        if(fre[arr[i]]>1)
        {
            long x=q.front();
            fre[arr[i]]--;
            arr[i]=x;
            fre[arr[i]]++;
            q.pop();
        }
    }
    for(long i=1; i<=n; i++)
    {
        cout<<arr[i];
        if(i==n)cout<<endl;
        else cout<<" ";
    }
     return 0;
}