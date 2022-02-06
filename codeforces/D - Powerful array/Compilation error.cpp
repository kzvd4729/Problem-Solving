/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/18/2018 23:05                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/86/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long ans[200005];
int n,q,arr[200002],fr[1000006];
struct data
{
    l,r,id,sg;
} qr[200002];
bool cmp(data A,data B)
{
    if(A.sg!=B.sg)
        return A.sg<B.sg;
    else
        return A.r<B.r;
}
int main()
{
    scanf("%ld",&n);
    scanf("%ld",&q);
    for(int i=1; i<=n; i++)
        scanf("%ld",&arr[i]);
    int sq=sqrt(n);
    for(int i=1; i<=q; i++)
    {
        scanf("%ld",&qr[i].l);
        scanf("%ld",&qr[i].r);
        qr[i].id=i;
        qr[i].sg=qr[i].l/sq;
    }
    sort(qr+1,qr+q+1,cmp);
    int pl,pr,nl,nr;
    pl=qr[1].l;
    pr=qr[1].r;
    long long sum=0;
    for(int k=pl; k<=pr; k++)
    {
        sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
        fr[arr[k]]++;
        sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
    }
    ans[qr[1].id]=sum;
    for(int i=2; i<=q; i++)
    {
        nl=qr[i].l;
        nr=qr[i].r;
        while(nl<pl)
        {
            sum-=fr[arr[nl]]*fr[arr[nl]]*arr[nl];
            fr[arr[nl]]++;
            sum+=fr[arr[nl]]*fr[arr[nl]]*arr[nl];
            nl++;
        }
        while(pl<nl)
        {
            sum-=fr[arr[pl]]*fr[arr[pl]]*arr[pl];
            fr[arr[pl]]--;
            sum+=fr[arr[pl]]*fr[arr[pl]]*arr[pl];
            pl--;
        }
        while(pr<nr)
        {
            pr++;
            sum-=fr[arr[pr]]*fr[arr[pr]]*arr[pr];
            fr[arr[pr]]++;
            sum+=fr[arr[pr]]*fr[arr[pr]]*arr[pr];
        }
        while(nr<pr)
        {
            nr++;
            sum-=fr[arr[nr]]*fr[arr[nr]]*arr[nr];
            fr[arr[nr]]--;
            sum+=fr[arr[nr]]*fr[arr[nr]]*arr[nr];
        }
        ans[qr[i].id]=sum;
    }
    for(int i=1; i<=q; i++)
        printf("%I64d\n",ans[i]);
    return 0;
}