/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/18/2018 19:48                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/159/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long k,n,x,ans,sz[30],q,oc,vis[200005];
string tmp,s;
char ch;
struct segment
{
    long l,r,sum;
} seg[27][1000006];
void insrt(long node,long lo,long hi,long wh,long id,long vl)
{
    if(lo==hi)
    {
        seg[wh][node].sum+=vl;
        return ;
    }
    long mid=(lo+hi)/2;
    if(id<=mid)
    {
        if(!seg[wh][node].l)seg[wh][node].l=++sz[wh];
        insrt(seg[wh][node].l,lo,mid,wh,id,vl);
    }
    else
    {
        if(!seg[wh][node].r)seg[wh][node].r=++sz[wh];
        insrt(seg[wh][node].r,mid+1,hi,wh,id,vl);
    }
    seg[wh][node].sum=seg[wh][seg[wh][node].l].sum+seg[wh][seg[wh][node].r].sum;
}
void query(long wh,long node,long lo,long hi,long kk)
{
    if(lo==hi)
    {
        ans=lo;
        return ;
    }
    long mid=(lo+hi)/2;
    long x=seg[wh][seg[wh][node].l].sum;
    if(x>=kk)
    {
        query(wh,seg[wh][node].l,lo,mid,kk);
    }
    else
    {
        kk-=x;
        query(wh,seg[wh][node].r,mid+1,hi,kk);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>k>>tmp;
    while(k--)s+=tmp;
    s.push_back('#');
    n=s.size()-1;
    for(long i=n; i>0; i--)s[i]=s[i-1];
    ///cout<<s<<endl;
    memset(sz,1,sizeof(sz));
    for(long i=1; i<=n; i++)insrt(1,1,n,s[i]-'a',i,1);
    cin>>q;
    while(q--)
    {
        cin>>oc>>ch;
        x=ch-'a';
        query(x,1,1,n,oc);
        insrt(1,1,n,x,ans,-1);
        vis[ans]=1;
    }
    for(long i=1;i<=n;i++)if(!vis[i])cout<<s[i];
    cout<<endl;
    return 0;
}