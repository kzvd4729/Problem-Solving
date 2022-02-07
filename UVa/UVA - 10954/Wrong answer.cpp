/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-15 00:32:06                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10954
****************************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;
long long int arr[100009];
int main()
{
    long long int n,i,sum,x;
    while(cin>>n)
    {
        if(n==0)break;
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);


        if(n==1)
        {
            cout<<arr[0]<<endl;
        }
        else if(n==2)
        {
            cout<<arr[0]+arr[1]<<endl;
        }
        else
        {
            sum=arr[0]+arr[1];

            for(i=1;i<n;i++)
            {
                arr[i]=arr[i-1]+arr[i];
            }

            for(i=1;i<n;i++)
            {
                arr[i]=arr[i-1]+arr[i];
            }

            cout<<arr[n-1]-arr[0]<<endl;


        }




    }


    return 0;
}