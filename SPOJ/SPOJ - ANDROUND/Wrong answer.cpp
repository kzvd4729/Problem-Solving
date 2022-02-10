/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-27 23:35:32                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-ANDROUND
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[20002],t,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(long i=1; i<=n; i++)
        {
            cin>>arr[i];
        }
        long x=min(k,50LL);
        while(x--)
        {

            for(long i=1; i<=n; i++)
            {
                long lft=i-1;
                if(lft==0)lft=n;
                long rgt=i+1;
                if(rgt==n+1)rgt=1;
                arr[i]=((arr[i]&arr[lft])&arr[rgt]);
            }
        }
        for(long i=1; i<=n; i++)
        {
            if(i!=1)cout<<" ";
            cout<<arr[i];
        }
        cout<<endl;
    }

    return 0;
}