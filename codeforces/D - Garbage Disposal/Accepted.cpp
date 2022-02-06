/****************************************************************************************
*  @author: JU_Troubleshooer: tariqiitju, the0dd1out, kzvd4729 created: Oct/20/2018 15:07                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 78 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/1070/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ara[200005];
int main()
{
    int n;
    ll k, baki;
    while(scanf("%d %lld", &n, &k)==2)
    {
        for(int i=0; i<n; i++)
            scanf("%lld", &ara[i]);
        ll ans= 0;
        baki= ara[0];
        for(int i=1; i<n; i++)
        {
            ll need= (baki/k);
            if(need*k<baki)
                need++;
            ans+= need;
            need= need*k - baki;
            baki= max(ara[i]-need, 0ll);
        }ans+= (baki/k + ((baki%k) !=0));
        cout<<ans<<endl;
    }
     return 0;
}