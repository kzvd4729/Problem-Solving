/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/30/2017 13:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 2700 KB                              
*  problem: https://codeforces.com/contest/789/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int b1,q,l,n,arr[100005],cnt,mark,ans,i,x,lo,mid,hi,f,ff,ll;
long long int bs(long long int x)
{
    lo=0;
    hi=n;
    mark=0;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(x==arr[mid])
        {
            mark=1;
            break;
        }
        else if(x>arr[mid])lo=mid+1;
        else hi=mid-1;
    }
    return mark;
 }
int main()
{
    while(cin>>b1>>q>>l>>n)
    {
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
         arr[n]=999999999999;
         cnt=0;
        ll=0;
        for(i=b1; abs(i)<=l; i=i*q)
        {
            x=i;
            f=bs(x);
            if(f==0)cnt++;
            ll++;
            if(ll>1000)break;
         }
        if(cnt>400)cout<<"inf"<<endl;
        else cout<<cnt<<endl;
     }
     return 0;
}