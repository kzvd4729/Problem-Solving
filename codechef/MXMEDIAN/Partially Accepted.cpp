/****************************************************************************************
*  @author: kzvd4729                                         created: 17-05-2017 15:44:46                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 4M                                   
*  problem: https://www.codechef.com/MAY17/problems/MXMEDIAN
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,n,arr[100005],i,md;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=2*n;i++)
        {
            cin>>arr[i];
        }
        sort(arr+1,arr+2*n+1);
        md=arr[n+((n+1)/2)];
        swap(arr[n+1],arr[n+((n+1)/2)]);
        cout<<md<<endl;
        for(i=1;i<=2*n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
            }
    return 0;
}