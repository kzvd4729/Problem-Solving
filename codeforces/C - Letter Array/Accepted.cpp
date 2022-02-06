/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/31/2017 22:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 72600 KB                             
*  problem: https://codeforces.com/gym/100482/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,l,r,i,q,ii,len;
string s,c;
struct segment
{
    int fr[30];
}seg[600005];
void build(int node,int lo,int hi)
{
    if(lo==hi)
    {
        for(int k=0;k<26;k++)seg[node].fr[k]=0;
        seg[node].fr[(int)(s[lo]-'A')]++;
        return ;
    }
    int mid=(lo+hi)/2;
    build(node*2,lo,mid);
    build(node*2+1,mid+1,hi);
    for(i=0;i<26;i++)
    {
        seg[node].fr[i]=seg[node*2].fr[i]+seg[node*2+1].fr[i];
    }
 }
void updm(int node,int lo,int hi,int id,char ch)
{
    if(lo==hi)
    {
        seg[node].fr[(int)(ch-'A')]--;
        return ;
    }
    int mid=(lo+hi)/2;
    if(id<=mid)
    {
        updm(node*2,lo,mid,id,ch);
    }
    else updm(node*2+1,mid+1,hi,id,ch);
    for(i=0;i<26;i++)
    {
        seg[node].fr[i]=seg[node*2].fr[i]+seg[node*2+1].fr[i];
    }
 }
void updp(int node,int lo,int hi,int id,char ch)
{
    if(lo==hi)
    {
        seg[node].fr[(int)(ch-'A')]++;
        return ;
    }
    int mid=(lo+hi)/2;
    if(id<=mid)
    {
        updp(node*2,lo,mid,id,ch);
    }
    else updp(node*2+1,mid+1,hi,id,ch);
    for(i=0;i<26;i++)
    {
        seg[node].fr[i]=seg[node*2].fr[i]+seg[node*2+1].fr[i];
    }
 }
segment query(int node,int lo,int hi,int l,int r)
{
    if(lo>r||hi<l)
    {
        segment tmp;
        for(i=0;i<26;i++)
        {
            tmp.fr[i]=0;
        }
        return tmp;
    }
    if(lo>=l&&hi<=r)return seg[node];
    int mid=(lo+hi)/2;
    segment p1=query(node*2,lo,mid,l,r);
    segment p2=query(node*2+1,mid+1,hi,l,r);
    segment p;
    for(i=0;i<26;i++)
    {
        p.fr[i]=p1.fr[i]+p2.fr[i];
    }
    return p;
 }
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    int tc=0;
    while(t--)
    {
        for(i=0;i<500005;i++)
        {
            for(int j=0;j<26;j++)
            {
                seg[i].fr[j]=0;
            }
        }
        cin>>s;
        len=s.size();
        build(1,0,len-1);
        cin>>q;
        cout<<"Case #"<<++tc<<":"<<endl;
        while(q--)
        {
            cin>>c>>l>>r;
            if(c=="s")
            {
                for(ii=l;ii<=r;ii++)
                {
                    updm(1,0,len-1,ii,s[ii]);
                }
                sort(s.begin()+l,s.begin()+r+1);
                for(ii=l;ii<=r;ii++)
                {
                    updp(1,0,len-1,ii,s[ii]);
                }
            }
            else
            {
                segment ans=query(1,0,len-1,l,r);
                for(ii=0;ii<26;ii++)
                {
                    cout<<ans.fr[ii];
                    if(ii!=25)cout<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
 