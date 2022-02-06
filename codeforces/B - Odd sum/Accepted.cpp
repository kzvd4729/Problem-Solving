/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2017 21:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/797/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long int arr[100005],odd[100005],even[100005],es,os,mpo,mno,pe,po,mpe,ps;
int main()
{
    long int n,i,o,e;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
     o=0;
    e=0;
    pe=0;
    po=0;
    ps=0;
    mpo=99999999;
    mno=-999999999;
    mpe=999999999;
    for(i=0;i<n;i++)
    {
        if(abs(arr[i])%2==1)
        {
            odd[++o]=arr[i];
            if(odd[o]<0)
            {
                if(odd[o]>mno)mno=odd[o];
            }
            if(odd[o]>0)
            {
                po++;
                os=os+odd[o];
                if(odd[o]<mpo)mpo=odd[o];
            }
        }
        else if(abs(arr[i]%2)==0)
        {
            even[++e]=arr[i];
            if(even[e]>0)
            {
                if(even[o]<mpe)mpe=even[o];
                pe++;
                es=es+even[e];
            }
        }
    }
    if(po>=1&&pe>=1)
    {
        if(po%2==1)cout<<es+os<<endl;
        else cout<<max(es+os-mpo,es+os+mno)<<endl;
    }
    else if(pe>=1&&po==0)
    {
        cout<<es+mno<<endl;
    }
    else if(pe==0&&po==0)
    {
        cout<<mno<<endl;
    }
    else if(pe==0&&po>=1)
    {
        if(po%2==1)cout<<os<<endl;
        else cout<<max(os-mpo,os+mno)<<endl;
    }
    return 0;
}