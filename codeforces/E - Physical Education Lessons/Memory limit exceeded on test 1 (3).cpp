/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2018 17:30                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++17                               
*  run_time: 0 ms                                            memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/915/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,ty,sz=1;
struct segment
{
    int sum,lft,rgt,lazy;
}seg[17000005];
void upd(int node,int lo,int hi,int l,int r,int ty)
{
    if(!seg[node].lft)seg[node].lft=++sz;
    if(!seg[node].rgt)seg[node].rgt=++sz;
    int mid=(lo+hi)/2;
    if(seg[node].lazy==1)
    {
        seg[node].sum=hi-lo+1;
        if(lo!=hi)
        {
            seg[seg[node].lft].sum=mid-lo+1;
            seg[seg[node].lft].lazy=1;
            seg[seg[node].rgt].sum=hi-mid;
            seg[seg[node].rgt].lazy=1;
        }
    }
    if(seg[node].lazy==2)
    {
        seg[node].sum=0;
        if(lo!=hi)
        {
            seg[seg[node].lft].sum=0;
            seg[seg[node].lft].lazy=2;
            seg[seg[node].rgt].sum=0;
            seg[seg[node].rgt].lazy=2;
        }
    }
    seg[node].lazy=0;
     if(lo>r||hi<l)return ;
     if(lo>=l&&hi<=r)
    {
        if(ty==1)
        {
            seg[node].sum=hi-lo+1;
            if(lo!=hi)
            {
                seg[seg[node].lft].sum=mid-lo+1;
                seg[seg[node].lft].lazy=1;
                seg[seg[node].rgt].sum=hi-mid;
                seg[seg[node].rgt].lazy=1;
            }
        }
        if(ty==2)
        {
            seg[node].sum=0;
            if(lo!=hi)
            {
                seg[seg[node].lft].sum=0;
                seg[seg[node].lft].lazy=2;
                seg[seg[node].rgt].sum=0;
                seg[seg[node].rgt].lazy=2;
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