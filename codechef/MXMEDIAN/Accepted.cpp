/****************************************************************************************
*  @author: kzvd4729                                         created: 17-05-2017 15:59:30                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.29 sec                                        memory_used: 4.1M                                 
*  problem: https://www.codechef.com/MAY17/problems/MXMEDIAN
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,n,arr[100005],i,md,id;
vector<long>f;
vector<long>s;
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
        for(i=1;i<=n;i++)
        {
            f.push_back(arr[i]);
        }
        for(i=n+1;i<=2*n;i++)
        {
            s.push_back(arr[i]);
        }
        md=arr[n+((n+1)/2)];
        id=0;
        for(i=0;i<n;i++)
        {
            arr[++id]=f[i];
            arr[++id]=s[i];
        }
        cout<<md<<endl;
        for(i=1;i<=2*n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        f.clear();
        s.clear();
            }
    return 0;
}