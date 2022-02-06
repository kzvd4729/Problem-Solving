/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/11/2017 00:06                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/686/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,arr[110],i,j;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(arr[j]>arr[j+1])
            {
                cout<<j<<" "<<j+1<<endl;
                swap(arr[j],arr[j+1]);
            }
            else
            {
                cout<<j<<" "<<j+1<<endl;
                cout<<j<<" "<<j+1<<endl;
            }
        }
    }
    return 0;
}