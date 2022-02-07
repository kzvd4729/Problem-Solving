/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-07 20:21:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 110                                             memory_used:                                      
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
        mx=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i==0)
            {
                if(arr[0]<0)arr[0]=0;
                if(arr[0]>mx)mx=arr[0];
            }
            else
            {
                arr[i]=arr[i-1]+arr[i];
                if(arr[i]>mx)mx=arr[i];
                if(arr[i]<0)arr[i]=0;

            }
        }

        if(mx==0)cout<<"Losing streak."<<endl;
        else cout<<"The maximum winning streak is "<<mx<<"."<<endl;

    }

    return 0;
}