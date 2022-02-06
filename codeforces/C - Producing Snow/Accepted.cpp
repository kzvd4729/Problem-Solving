/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/12/2018 00:25                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 124 ms                                          memory_used: 6600 KB                              
*  problem: https://codeforces.com/contest/948/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N = 1e5;
long vl[N + 2], tp[N + 2], qm[N + 2], n, ans[N + 2], lo, hi, md, bit[2 * N], ex;
void upd(long idx, long vl)
{
    for( ; idx <= n; idx += idx & -idx)bit[idx] += vl;
}
long query(long idx)
{
    long sum = 0;
    for( ; idx > 0; idx -= idx & -idx)sum += bit[idx];
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin >> n;
    for(long i = 1; i <= n; i++)cin >> vl[i];
    for(long i = 1; i <= n; i++)cin >> tp[i];
    qm[1] = tp[1];
    for(long i = 2; i <= n; i++)qm[i] = qm[i - 1] + tp[i];
    for(long i = 1; i <= n; i++)
    {
        if(tp[i] >= vl[i])
        {
            ans[i] +=(query(i)*tp[i])+vl[i];
            continue;
        }
        lo=i;
        hi=n;
        while(hi - lo > 3)
        {
            md = (lo + hi) / 2;
            if(qm[md] - qm[i - 1] < vl[i])lo = md;
            else hi = md;
        }
        for(long j = hi; j >= lo; j--)
        {
            if(qm[j] - qm[i - 1] <= vl[i])
            {
                upd(1, 1);
                upd(j + 1, -1);
                ex = vl[i] - (qm[j] - qm[i - 1]);
                ans[j + 1] += ex;
                break;
            }
        }
        ans[i] += tp[i] * query(i);
    }
    for(long i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}