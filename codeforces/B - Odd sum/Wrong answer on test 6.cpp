/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2017 21:08                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/797/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long int arr[100005],odd[100005],even[100005],es,os,mo;
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
    es=0;
    os=0;
    mo=9999999999;
    for(i=0;i<n;i++)
    {
        if(arr[i]>0&&arr[i]%2==1)
        {
            odd[++o]=arr[i];
            if(odd[o]<mo)mo=odd[o];
            os=os+odd[o];
        }
        else if(arr[i]>0&&arr[i]%2==0)
        {
            even[++e]=arr[i];
            es=es+even[e];
        }
    }
    if(o==0)cout<<-1<<endl;
    else if(o%2==1)cout<<os+es<<endl;
    else cout<<es+os-mo<<endl;
    return 0;
}