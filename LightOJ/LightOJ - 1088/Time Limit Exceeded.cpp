/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-12-08 01:23:02                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1088
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,n,q,arr[100005],l,r;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(long i=1;i<=n;i++)cin>>arr[i];
        sort(arr+1,arr+n+1);
        cout<<"Case "<<++tc<<":"<<endl;
        while(q--)
        {
            cin>>l>>r;
            cout<<upper_bound(arr+1,arr+n+1,r)-lower_bound(arr+1,arr+n+1,l)<<endl;
        }
    }
    return 0;
}