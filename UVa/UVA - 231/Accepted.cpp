/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-07 17:29:22                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-231
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define inf 9999999;
int main()
{
    long int n,x,f,ar[100003],arr[100003],j,k,temp,t[100003],l,lo,hi,mid,i,tc=0;
    while(1)
    {
        x=0;
        f=0;
        while(cin>>n)
        {
            ar[++x]=n;
            if(ar[1]==-1)
            {
                f=1;
                break;
            }
            if(tc!=0&&x==1)cout<<endl;
            if(n==-1)break;

        }
        if(f==1)break;
        temp=x-1;

        for(i=1;i<x;i++)
        {
            arr[i]=ar[temp];
            temp--;

        }
        l=0;
        t[0]=-inf;
        for(i=1;i<=x+2;i++)
        {
            t[i]=inf;
        }
        for(i=1;i<x;i++)
        {
            lo=0;
            hi=l;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                if(t[mid]<arr[i])
                {
                    lo=mid+1;
                }
                else
                {
                    hi=mid-1;
                }
            }

            t[lo]=arr[i];
            if(l<lo)l=lo;

        }
        cout<<"Test #"<<++tc<<":"<<endl;
        cout<<"  maximum possible interceptions: "<<l<<endl;


    }


    return 0;
}