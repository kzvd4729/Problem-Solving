/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-10 21:16:39                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 500                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11462
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int arr[2000002],i,j,n,x;
int main()
{
    while(cin>>n)
    {
        if(n==0)break;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(i=0;i<n;i++)
        {
            cout<<arr[i];
            if(i!=n-1)cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}