/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/18/2018 19:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 257500 KB                            
*  problem: https://codeforces.com/contest/159/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int k,n,x,ans,sz[30],q,oc,vis[400005];
string tmp,s;
char ch;
struct segment
{
    int l,r,sum;
}seg[27][800005];
void insrt(int node,int lo,int hi,int wh,int id,int vl)
{
    if(lo==hi)
    {
        seg[wh][node].sum+=vl;
        return ;
    }
    int mid=(lo+hi)/2;
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
void query(int wh,int node,int lo,int hi,int kk)
{
    if(lo==hi)
    {
        ans=lo;
        return ;
    }
    int mid=(lo+hi)/2;
    int x=seg[wh][seg[wh][node].l].sum;
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
    for(int i=n; i>0; i--)s[i]=s[i-1];
    ///cout<<s<<endl;
    ///memset(sz,1,sizeof(sz));
    for(long i=0;i<30;i++)sz[i]=1;
    for(int i=1; i<=n; i++)insrt(1,1,n,s[i]-'a',i,1);
    cin>>q;
    while(q--)
    {
        cin>>oc>>ch;
        x=ch-'a';
        if(oc>seg[x][1].sum)continue;
        query(x,1,1,n,oc);
        insrt(1,1,n,x,ans,-1);
        vis[ans]=1;
    }
    for(int i=1;i<=n;i++)if(!vis[i])cout<<s[i];
    cout<<endl;
//    for(long i=0;i<26;i++)cout<<sz[i]<<" ";
//    cout<<endl;
    return 0;
}