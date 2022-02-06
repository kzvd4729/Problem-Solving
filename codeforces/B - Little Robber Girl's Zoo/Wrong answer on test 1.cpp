/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/11/2017 00:15                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/686/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,arr[110],i,j;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=n;j>i;j--)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
                cout<<j<<" "<<j-1<<endl;
            }
            else
            {
                cout<<j<<" "<<j-1<<endl;
                cout<<j<<" "<<j-1<<endl;
            }
        }
    }
    ///for(i=1;i<=n;i++)cout<<arr[i]<<" ";
    ///cout<<endl;
    return 0;
}