/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-03 19:41:39                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 30                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-481
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define inf 999999;
int main()
{
    long int n,x,i,arr[99999],t[99999],len,lo,hi,mid,r[99999],ans[99999],j;
    /*for(i=0;i<=7;i++)
    {
        cin>>arr[i];
        x=7;
    }*/
    x=-1;
    while(cin>>n)
    {
        arr[++x]=n;

        //if(x==7)break;
    }
    //cout<<x<<endl;

    t[0]=-inf;
    for(i=1;i<=x+2;i++)
    {
        t[i]=inf;
    }

    len=0;

    for(i=0;i<=x;i++)
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
        //cout<<lo<<endl;

        t[lo]=arr[i];

        r[i]=lo;

        if(len<lo)len=lo;


    }

    cout<<len<<endl;
    /*for(i=1;i<=len;i++)
    {
        cout<<t[i]<<endl;
    }*/

    /*for(i=0;i<=x;i++)
    {
        cout<<r[i]<<" ";
    }
    cout<<endl;*/

    cout<<"-"<<endl;


    j=-1;

    for(i=x;i>=0;i--)
    {
        if(r[i]==len)
        {
            ans[++j]=arr[i];

            len--;

        }
    }


    for(i=j;i>=0;i--)
    {
        cout<<ans[i]<<endl;
    }




    return 0;
}