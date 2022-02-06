/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2017 16:59                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 32100 KB                             
*  problem: https://codeforces.com/gym/101055/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 999999999999999
using namespace std;
struct data
{
    long allsm,allsz,lftsm,lftsz,rtsm,rtsz,mxsm,mxsz;
 }tree[500005] ;
long ara[100005];
void make_tree(long node,long b, long e)
{
    if(b==e)
    {
        tree[node].allsm=ara[b];
        tree[node].lftsm=ara[b];
        tree[node].rtsm=ara[b];
        tree[node].mxsm=ara[b];
        tree[node].allsz=1;
        tree[node].lftsz=1;
        tree[node].rtsz=1;
        tree[node].mxsz=1;
        return;
    }
    long mid=(b+e)/2;
    make_tree(node*2,b,mid);
    make_tree(node*2+1,mid+1,e);
      tree[node].allsm=tree[node*2].allsm+tree[node*2+1].allsm;
    tree[node].allsz=tree[node*2].allsz+tree[node*2+1].allsz;
      tree[node].lftsm=tree[node*2].lftsm;
    tree[node].lftsz=tree[node*2].lftsz;
    if(tree[node*2].allsm+tree[node*2+1].lftsm>=tree[node].lftsm)
    {
       tree[node].lftsm=tree[node*2].allsm+tree[node*2+1].lftsm;
       tree[node].lftsz=tree[node*2].allsz+tree[node*2+1].lftsz;
    }
     tree[node].rtsm=tree[node*2+1].rtsm;
    tree[node].rtsz=tree[node*2+1].rtsz;
    if(tree[node*2+1].allsm+tree[node*2].rtsm>=tree[node].rtsm)
    {
        tree[node].rtsm=tree[node*2+1].allsm+tree[node*2].rtsm;
        tree[node].rtsz=tree[node*2+1].allsz+tree[node*2].rtsz;
    }
        if(tree[node*2].mxsm>=tree[node*2+1].mxsm)
    {
        tree[node].mxsm=tree[node*2].mxsm;
        tree[node].mxsz=tree[node*2].mxsz;
    }
    else
    {
        tree[node].mxsm=tree[node*2+1].mxsm;
        tree[node].mxsz=tree[node*2+1].mxsz;
    }
     if(tree[node*2].mxsm==tree[node*2+1].mxsm)
    {
        tree[node].mxsz=max(tree[node*2].mxsz,tree[node*2+1].mxsz);
    }
      if(tree[node].mxsm<=tree[node*2].allsm+tree[node*2+1].allsm)
    {
        tree[node].mxsm=tree[node*2].allsm+tree[node*2+1].allsm;
        if(tree[node].mxsm==tree[node*2].allsm+tree[node*2+1].allsm)tree[node].mxsz=max(tree[node].mxsz,tree[node*2].allsz+tree[node*2+1].allsz);
        else tree[node].mxsz=tree[node*2].allsz+tree[node*2+1].allsz;
    }
      if(tree[node].lftsm>=tree[node].mxsm)
    {
        tree[node].mxsm=tree[node].lftsm;
        if(tree[node].lftsm==tree[node].mxsm)tree[node].mxsz=max(tree[node].mxsz,tree[node].lftsz);
        else tree[node].mxsz=tree[node].lftsz;
    }
     if(tree[node].rtsm>=tree[node].mxsm)
    {
        tree[node].mxsm=tree[node].rtsm;
        if(tree[node].rtsm==tree[node].mxsm)tree[node].mxsz=max(tree[node].mxsz,tree[node].rtsz);
        else tree[node].mxsz=tree[node].rtsz;
    }
     if(tree[node*2].rtsm+tree[node*2+1].lftsm>=tree[node].mxsm)
    {
        tree[node].mxsm=tree[node*2].rtsm+tree[node*2+1].lftsm;
        if(tree[node*2].rtsm+tree[node*2+1].lftsm==tree[node].mxsm)tree[node].mxsz=max(tree[node].mxsz,tree[node*2].rtsz+tree[node*2+1].lftsz);
        else tree[node].mxsz=tree[node*2].rtsz+tree[node*2+1].lftsz;
    }
    return;
}
data qry(long node,long b,long e,long l,long r)
{
    if(b>r||e<l)return {-inf,-inf,-inf,-inf,-inf,-inf,-inf,-inf};
    if(b>=l&&e<=r)
    {
        return tree[node];
    }
    long mid=(b+e)/2;
    data p1=qry(node*2,b,mid,l,r);
    data p2=qry(node*2+1,mid+1,e,l,r);
    data p;
      if(p1.allsm==-inf)
    {
        p.allsm=p2.allsm;
        p.lftsm=p2.lftsm;
        p.rtsm=p2.rtsm;
        p.allsz=p2.allsz;
        p.lftsz=p2.lftsz;
        p.rtsz=p2.rtsz;
         p.mxsm=p2.mxsm;
        p.mxsz=p2.mxsz;
        return p;
     }
    if(p2.allsm==-inf)
    {
        p.allsm=p1.allsm;
        p.lftsm=p1.lftsm;
        p.rtsm=p1.rtsm;
        p.allsz=p1.allsz;
        p.lftsz=p1.lftsz;
        p.rtsz=p1.rtsz;
         p.mxsm=p1.mxsm;
        p.mxsz=p1.mxsz;
         return p;
    }
     p.allsm=p1.allsm+p2.allsm;
    p.allsz=p1.allsz+p2.allsz;
      p.lftsm=p1.lftsm;
    p.lftsz=p1.lftsz;
    if(p1.allsm+p2.lftsm>=p.lftsm)
    {
       p.lftsm=p1.allsm+p2.lftsm;
       p.lftsz=p1.allsz+p2.lftsz;
    }
     p.rtsm=p2.rtsm;
    p.rtsz=p2.rtsz;
    if(p2.allsm+p1.rtsm>=p.rtsm)
    {
        p.rtsm=p2.allsm+p1.rtsm;
        p.rtsz=p2.allsz+p1.rtsz;
    }
      if(p1.mxsm>=p2.mxsm)
    {
        p.mxsm=p1.mxsm;
        p.mxsz=p1.mxsz;
    }
    else
    {
        p.mxsm=p2.mxsm;
        p.mxsz=p2.mxsz;
    }
     if(p1.mxsm==p2.mxsm)
    {
        p.mxsz=max(p1.mxsz,p2.mxsz);
    }
      if(p.mxsm<=p1.allsm+p2.allsm)
    {
        p.mxsm=p1.allsm+p2.allsm;
        if(p.mxsm==p1.allsm+p2.allsm)p.mxsz=max(p1.allsz+p2.allsz,p.mxsz);
        else p.mxsz=p1.allsz+p2.allsz;
    }
     if(p.lftsm>=p.mxsm)
    {
        p.mxsm=p.lftsm;
        if(p.lftsm==p.mxsm)p.mxsz=max(p.mxsz,p.lftsz);
        else p.mxsz=p.lftsz;
    }
     if(p.rtsm>=p.mxsm)
    {
        p.mxsm=p.rtsm;
        if(p.rtsm==p.mxsm)p.mxsz=max(p.mxsz,p.rtsz);
        else p.mxsz=p.rtsz;
    }
     if(p1.rtsm+p2.lftsm>=p.mxsm)
    {
        p.mxsm=p1.rtsm+p2.lftsm;
        if(p1.rtsm+p2.lftsm==p.mxsm)p.mxsz=max(p.mxsz,p1.rtsz+p2.lftsz);
        else p.mxsz=p1.rtsz+p2.lftsz;
    }
     return p;
 }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long l,r,t,k,n,i,rslt,q;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ara[i];
    }
    make_tree(1,1,n);
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>l>>r;
        data rslt=qry(1,1,n,l,r);
        ///cout<<endl;
        ///cout<<rslt.lftsm<<" "<<rslt.lftsz<<endl;
        ///cout<<rslt.rtsm<<" "<<rslt.rtsz<<endl;
        ///cout<<rslt.allsm<<" "<<rslt.allsz<<endl;
        cout<<rslt.mxsm<<" "<<rslt.mxsz<<endl;
        ///cout<<endl;
    }
     return 0;
}