/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2018 18:40                        
*  solution_verdict: Time limit exceeded on test 20          language: GNU C++17                               
*  run_time: 1000 ms                                         memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/915/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,ty,sz=1;
short int lazy[19001100];
struct segment
{
    int sum,lft,rgt;
}seg[19001100];
void upd(int node,int lo,int hi,int l,int r,int ty)
{
    if(lazy[node]==1)seg[node].sum=hi-lo+1;
    if(lazy[node]==2)seg[node].sum=0;
    if(lo>r||hi<l)return ;
    if(!seg[node].lft)seg[node].lft=++sz;
    if(!seg[node].rgt)seg[node].rgt=++sz;
    int mid=(lo+hi)/2;
    if(lazy[node]==1)
    {
        seg[node].sum=hi-lo+1;
        if(lo!=hi)
        {
            seg[seg[node].lft].sum=mid-lo+1;
            lazy[seg[node].lft]=1;
            seg[seg[node].rgt].sum=hi-mid;
            lazy[seg[node].rgt]=1;
        }
    }
    if(lazy[node]==2)
    {
        seg[node].sum=0;
        if(lo!=hi)
        {
            seg[seg[node].lft].sum=0;
            lazy[seg[node].lft]=2;
            seg[seg[node].rgt].sum=0;
            lazy[seg[node].rgt]=2;
        }
    }
    lazy[node]=0;
     if(!seg[node].lft)seg[node].lft=++sz;
    if(!seg[node].rgt)seg[node].rgt=++sz;
    if(lo>=l&&hi<=r)
    {
        if(ty==1)
        {
            seg[node].sum=hi-lo+1;
            if(lo!=hi)
            {
                seg[seg[node].lft].sum=mid-lo+1;
                lazy[seg[node].lft]=1;
                seg[seg[node].rgt].sum=hi-mid;
                lazy[seg[node].rgt]=1;
            }
        }
        if(ty==2)
        {
            seg[node].sum=0;
            if(lo!=hi)
            {
                seg[seg[node].lft].sum=0;
                lazy[seg[node].lft]=2;
                seg[seg[node].rgt].sum=0;
                lazy[seg[node].rgt]=2;
            }
        }
        return ;
    }
    upd(seg[node].lft,lo,mid,l,r,ty);
    upd(seg[node].rgt,mid+1,hi,l,r,ty);
    seg[node].sum=seg[seg[node].lft].sum+seg[seg[node].rgt].sum;
 }
int main()
{
    scanf("%d%d",&n,&q);
    while(q--)
    {
        scanf("%d%d%d",&l,&r,&ty);
        upd(1,1,n,l,r,ty);
        printf("%d\n",n-seg[1].sum);
    }
    return 0;
}