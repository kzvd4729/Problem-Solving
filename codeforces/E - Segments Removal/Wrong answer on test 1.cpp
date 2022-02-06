/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2017 18:35                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/899/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[200005],l;
set<pair<long,pair<long,long> > >st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    arr[n+1]=-1;
    l=1;
    for(long i=2;i<=n+1;i++)
    {
        if(arr[i]!=arr[l])
        {
            st.insert({-(i-l),{l,i-1}});
            l=i;
        }
    }
         return 0;
}