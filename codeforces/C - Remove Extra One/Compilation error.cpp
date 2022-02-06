/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/16/2017 08:54                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/900/problem/C
****************************************************************************************/
 #include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100005],l,r,l1,l2,l3,r1,r2,r3;
deque<pair<long,long> >dq;
int main()
{
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    l=1;
    r=2;
    arr[n+1]=0;
    while(true)
    {
        if(arr[r]<arr[l])
        {
            dq.push_back({l,r-1});
            l=r;
            r++;
        }
        else r++;
        if(r>n+1)break;
    }
    long mx=0,ans=999999999;
     while(dq.size()>2)
    {
        l1=dq.front().first;
        r1=dq.front().second;
        dq.pop_front();
                l2=dq.front().first;
        r2=dq.front().second;
        dq.pop_front();
                l3=dq.front().first;
        r3=dq.front().second;
                dq.push_front({})
            }
    return 0;
}