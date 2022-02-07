/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-05 23:45:29                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10474
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int main()
{
    int n,q,tc=0;
    while(cin>>n>>q)
    {
        if(n==0&&q==0)break;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }

        sort(arr+1,arr+n+1);

        int lo,mid,hi,mx=99999;

        for(int i=0;i<q;i++)
        {
            int qu;
            cin>>qu;
            lo=1;
            hi=n;
            int flag=0;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                if(arr[mid]>=qu)
                {
                    if(arr[mid]==qu)
                    {
                        flag=1;
                        if(mid<mx)mx=mid;
                    }
                    hi=mid-1;
                }
                else
                {
                    lo=mid+1;
                }

            }
            if(i==0)cout<<"CASE# "<<++tc<<":"<<endl;
            if(flag==0)cout<<qu<<" not found"<<endl;
            else cout<<qu<<" found at "<<mx<<endl;
        }


    }


    return 0;
}