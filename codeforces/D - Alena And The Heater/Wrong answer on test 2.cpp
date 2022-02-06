/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2018 20:21                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 5800 KB                              
*  problem: https://codeforces.com/contest/940/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[500005],l=-1e9,r=1e9;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=0;i<n;i++)cin>>arr[i];
    cin>>s;
    for(long i=4;i<n;i++)
    {
        if(s[i]=='1'&&s[i-1]=='0')
        {
            l=max(l,arr[i]+arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4]+1);
        }
        if(s[i]=='0'&&s[i-1]=='1')
        {
            r=min(r,arr[i]+arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4]-1);
        }
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}