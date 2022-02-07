/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-11 23:20:47                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 30                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11057
****************************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,lo,mid,hi,arr[10009],f,s,ii,midd,diff,dif;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        cin>>s;

        sort(arr,arr+n);

        f=0;
        diff=999999;

        for(i=0;i<n;i++)
        {
            lo=i+1;
            hi=n-1;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                if(arr[i]+arr[mid]==s)
                {
                    f=1;
                    break;
                }
                else if(arr[i]+arr[mid]<s)
                {
                    lo=mid+1;
                }
                else hi=mid-1;
            }

            if(f==1)dif=abs(arr[mid]-arr[i]);
            if(f==1)
            {
                if(dif<=diff)
                {
                    ii=i;
                    midd=mid;
                    f=0;
                }
                
            }


        }
        cout<<"Peter should buy books whose prices are "<<arr[ii]<<" and "<<arr[midd]<<"."<<endl<<endl;


    }
    return 0;
}