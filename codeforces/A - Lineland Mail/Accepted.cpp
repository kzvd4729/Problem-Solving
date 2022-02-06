/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/22/2017 15:10                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 530 ms                                          memory_used: 41200 KB                             
*  problem: https://codeforces.com/contest/567/problem/A
****************************************************************************************/
#include<iostream>
#include<cmath>
using namespace std;
long long int arr[5000005];
int main()
{
    long long int n,i,mx,mn;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<n;i++)
        {
            mx=max(abs(arr[n-1]-arr[i]),abs(arr[i]-arr[0]));
            if(i==0)
            {
                mn=abs(arr[i+1]-arr[i]);
            }
            else if(i==n-1)
            {
                mn=arr[n-1]-arr[n-2];
            }
            else
            {
                if(abs(arr[i]-arr[i-1])>=abs(arr[i+1]-arr[i]))
                {
                    mn=abs(arr[i+1]-arr[i]);
                }
                else mn=abs(arr[i]-arr[i-1]);
            }
            cout<<mn<<" "<<mx<<endl;
        }
    }
      return 0;
}