/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-29 00:11:06                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1088
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,tc,n,q,a,b,i,j,lo,mid,hi,arr[100005],lb,ub,f;
    while(cin>>t)
    {
        for(tc=1;tc<=t;tc++)
        {
            cin>>n>>q;
            for(i=0;i<n;i++)
            {
                cin>>arr[i];
            }
            f=0;
            for(i=0;i<q;i++)
            {
                f=1;
                cin>>a>>b;
                lo=0;
                hi=n-1;
                while(lo<=hi)
                {
                    mid=(lo+hi)/2;
                    if(arr[mid]==a)
                    {
                        lo=mid;
                        break;
                    }
                    else if(arr[mid]<a)lo=mid+1;
                    else hi=mid-1;

                }
                lb=lo;

                lo=0;
                hi=n-1;
                while(lo<=hi)
                {
                    mid=(lo+hi)/2;
                    if(arr[mid]==b)
                    {
                        hi=mid;
                        break;
                    }
                    else if(arr[mid]<b)lo=mid+1;
                    else hi=mid-1;

                }
                ub=hi;
                //cout<<arr[lb]<<" "<<arr[ub]<<endl;
                if(f==0)cout<<"Case "<<tc<<":"<<endl;
                cout<<ub-lb+1<<endl;
                f=1;
            }





        }

    }
    return 0;
}