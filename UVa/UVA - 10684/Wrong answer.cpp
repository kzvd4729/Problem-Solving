/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-07 20:14:19                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10684
****************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
    int arr[100003],i,mx,n;
    while(cin>>n)
    {
        if(n==0)break;
        for(i=0;i<n;i++)
        {
            mx=0;
            cin>>arr[i];
            if(i==0)
            {
                if(arr[i]<0)arr[i]=0;
                if(arr[i]>mx)mx=arr[i];
            }
            else
            {
                arr[i]=arr[i-1]+arr[i];
                if(arr[i]<0)arr[i]=0;
                if(arr[i]>mx)mx=arr[i];

            }
        }

        if(mx==0)cout<<"Losing streak."<<endl;
        else cout<<"The maximum winning streak is "<<mx<<"."<<endl;

    }

    return 0;
}