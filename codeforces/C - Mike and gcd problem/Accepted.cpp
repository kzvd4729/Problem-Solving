/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2017 14:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/798/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ans,gcd,f,n,x,arr[100005];
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
    for(long i=n;i>=1;i--)
    {
        gcd=__gcd(gcd,arr[i]);
        if(arr[i]%2==1)
        {
            if(f==0)f=1;
            else
            {
                ans++;
                f=0;
            }
        }
        else
        {
            if(f==1)
            {
                ans+=2;
                f=0;
            }
        }
    }
    if(f==1)ans+=2;
    cout<<"YES"<<endl;
    if(gcd>1)cout<<0<<endl;
    else cout<<ans<<endl;
    return 0;
}
 