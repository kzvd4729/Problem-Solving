/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-01 21:10:56                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1135
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,n,lazy[500005],q;
struct segment
{
    int zeros;
    int ones;
    int twos;
}seg[500005];
void mem(void)
{
    for(int i=0;i<500004;i++)
    {
        seg[i].zeros=0;
        seg[i].ones=0;
        seg[i].twos=0;
        lazy[i]=0;
    }
}
void built(int node,int lo,int hi)
{
    if(lo==hi)
    {
        seg[node].zeros=1;
        seg[node].ones=0;
        seg[node].twos=0;
        return ;
    }
    int mid=(lo+hi)/2;
    built(node*2,lo,mid);
    built(node*2+1,mid+1,hi);
    seg[node].zeros=seg[node*2].zeros+seg[node*2+1].zeros;
    seg[node].ones=seg[node*2].ones+seg[node*2+1].ones;
    seg[node].twos=seg[node*2].twos+seg[node*2+1].twos;

}
void upd(int node,int lo,int hi,int l,int r)
{
    if(lazy[node]!=0)
    {
        int t1,t2,t3;
        int tm=lazy[node];
        tm=tm%3;
        t1=seg[node].zeros;
        t2=seg[node].ones;
        t3=seg[node].twos;
        if(tm==1)
        {
            seg[node].zeros=t3;
            seg[node].ones=t1;
            seg[node].twos=t2;
        }
        if(tm==2)
        {
            seg[node].zeros=t2;
            seg[node].ones=t3;
            seg[node].twos=t1;
        }
        if(lo!=hi)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(lo>r||hi<l)return ;
    if(lo>=l&&hi<=r)
    {
        int t1,t2,t3;
        t1=seg[node].zeros;
        t2=seg[node].ones;
        t3=seg[node].twos;
        seg[node].zeros=t3;
        seg[node].ones=t1;
        seg[node].twos=t2;
        if(lo!=hi)
        {
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        return ;

    }
    int mid=(lo+hi)/2;
    upd(node*2,lo,mid,l,r);
    upd(node*2+1,mid+1,hi,l,r);
    seg[node].zeros=seg[node*2].zeros+seg[node*2+1].zeros;
    seg[node].ones=seg[node*2].ones+seg[node*2+1].ones;
    seg[node].twos=seg[node*2].twos+seg[node*2+1].twos;

}
segment query(int node,int lo,int hi,int l,int r)
{
    if(lazy[node]!=0)
    {
        int t1,t2,t3;
        int tm=lazy[node];
        tm=tm%3;
        t1=seg[node].zeros;
        t2=seg[node].ones;
        t3=seg[node].twos;
        if(tm==1)
        {
            seg[node].zeros=t3;
            seg[node].ones=t1;
            seg[node].twos=t2;
        }
        if(tm==2)
        {
            seg[node].zeros=t2;
            seg[node].ones=t3;
            seg[node].twos=t1;
        }
        if(lo!=hi)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(lo>r||hi<l)
    {
        segment tmp;
        tmp.zeros=0;
        tmp.ones=0;
        tmp.twos=0;
        return tmp;
    }
    if(lo>=l&&hi<=r)return seg[node];
    int mid=(lo+hi)/2;
    segment p1=query(node*2,lo,mid,l,r);
    segment p2=query(node*2+1,mid+1,hi,l,r);
    segment p;
    p.zeros=p1.zeros+p2.zeros;
    p.ones=p1.ones+p2.ones;
    p.twos=p1.twos+p2.twos;
    return p;

}
int main()
{
    cin>>t;
    int tc=0;
    while(t--)
    {
        mem();
        cin>>n>>q;
        built(1,0,n-1);
        /*for(int i=0;i<20;i++)
        {
            cout<<seg[i].zeros<<" ";
            cout<<seg[i].ones<<" ";
            cout<<seg[i].twos<<" ";
            cout<<endl;
        }*/
        cout<<"Case "<<++tc<<":"<<endl;
        while(q--)
        {
            int ck,iii,jjj;
            cin>>ck>>iii>>jjj;
            if(ck==0)
            {
                upd(1,0,n-1,iii,jjj);
            }
            /*for(int i=0;i<20;i++)
            {
                cout<<seg[i].zeros<<" ";
                cout<<seg[i].ones<<" ";
                cout<<seg[i].twos<<" ";
                cout<<endl;
            }*/
            else
            {
                segment ans=query(1,0,n-1,iii,jjj);
                cout<<ans.zeros<<endl;
                ///cout<<ans.zeros<<" "<<ans.ones<<" "<<ans.twos<<endl;
            }

        }

    }
    return 0;
}