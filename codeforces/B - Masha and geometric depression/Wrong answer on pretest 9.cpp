/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/29/2017 22:53                        
*  solution_verdict: Wrong answer on pretest 9               language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/789/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int b1,q,l,n,arr[100005],cnt,f,ans,i,x,lo,mid,hi;
    while(cin>>b1>>q>>l>>n)
    {
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        if(b1==0||q==0)
        {
            lo=0;
            hi=n;
            f=0;
            x=b1*q;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                if(x==arr[mid])
                {
                    f=1;
                    break;
                }
                else if(x>arr[mid])lo=mid+1;
                else hi=mid-1;
            }
            if(f==1)cout<<0<<endl;
            else cout<<"inf"<<endl;
        }
        else if(b1==1||q==1||b1==-1||q==-1)
        {
            x=b1*q;
            lo=0;
            hi=n;
            f=0;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                if(x==arr[mid])
                {
                    f=1;
                    break;
                }
                else if(x>arr[mid])lo=mid+1;
                else hi=mid-1;
            }
            if(f==1)cout<<0<<endl;
            else cout<<"inf"<<endl;
         }
        else
        {
            cnt=0;
            for(i=b1; abs(i)<=l; i=i*q)
            {
                x=i;
                lo=0;
                hi=n;
                f=0;
                while(lo<=hi)
                {
                    mid=(lo+hi)/2;
                    if(x==arr[mid])
                    {
                        f=1;
                        break;
                    }
                    else if(x>arr[mid])lo=mid+1;
                    else hi=mid-1;
                }
                if(f==0)cnt++;
             }
            cout<<cnt<<endl;
         }
      }
     return 0;
}