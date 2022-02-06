/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/18/2018 22:20                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 19100 KB                             
*  problem: https://codeforces.com/contest/86/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,q,arr[200002],fr[1000006],ans[200005];
struct data
{
    long l,r,id,sg;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>q;
    for(long i=1; i<=n; i++)
        cin>>arr[i];
    long sq=sqrt(n);
    for(long i=1; i<=q; i++)
    {
        cin>>qr[i].l>>qr[i].r;
        qr[i].id=i;
        qr[i].sg=qr[i].l/sq;
    }
    sort(qr+1,qr+q+1,cmp);
    long pl,pr,nl,nr;
    pl=qr[1].l;
    pr=qr[1].r;
    long sum=0;
    for(long k=pl; k<=pr; k++)
    {
        sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
        fr[arr[k]]++;
        sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
    }
    ans[qr[1].id]=sum;
    for(long i=2; i<=q; i++)
    {
        nl=qr[i].l;
        nr=qr[i].r;
        for(long k=nl; k<pl; k++)
        {
            sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
            fr[arr[k]]++;
            sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
        }
        for(long k=pl; k<nl; k++)
        {
            sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
            fr[arr[k]]--;
            sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
        }
        for(long k=pr+1; k<=nr; k++)
        {
            sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
            fr[arr[k]]++;
            sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
        }
        for(long k=nr+1; k<=pr; k++)
        {
            sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
            fr[arr[k]]--;
            sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
        }
        ans[qr[i].id]=sum;
        nl=pl;
        nr=pr;
    }
    for(long i=1; i<=q; i++)
        cout<<ans[i]<<endl;
    return 0;
}