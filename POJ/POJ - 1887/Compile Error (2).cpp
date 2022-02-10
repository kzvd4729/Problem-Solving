/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-03 21:13:49                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-1887
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define inf 999999;
int main()
{
    int n,x,s,ar[100001],i,arr[100001],t[100001],r[100001],lo,hi,mid,len,tc=1,flag;
    while(1)
    {
        x=0;
        flag=0;
        while(cin>>n)
        {
            if(n==-1)
            {
                if(x==0)
                {
                    flag=1;
                }
                break;
            }
            //if(x==0)cout<<endl;
            ar[++x]=n;
        }
        if(flag==1)break;
        else
        {
            if(tc>1)cout<<endl;
        s=x;
        for(i=1;i<=s;i++)
        {
            arr[i]=ar[x];
            //cout<<arr[i]<<endl;
            x--;
        }

        t[0]=-inf;

        for(i=1;i<=s+2;i++)
        {
            t[i]=inf;
        }

        len=0;

        for(i=1;i<=s;i++)
        {
            lo=0;
            hi=len;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                if(t[mid]<arr[i])
                {
                    lo=mid+1;
                }
                else hi=mid-1;

            }

            t[lo]=arr[i];
            if(lo>len)len=lo;
        }

        cout<<"Test #"<<tc<<":"<<endl;
        cout<<"  maximum possible interceptions: "<<len<<endl;
        tc++;
        }


    }

    return 0;
}