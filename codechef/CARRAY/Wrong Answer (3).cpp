/****************************************************************************************
*  @author: kzvd4729                                         created: 18-02-2018 23:11:12                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 16.4M                                
*  problem: https://www.codechef.com/COOK91/problems/CARRAY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e9;
long t,n,k,b,tmp[100005],len,x,lo,hi,mid,arr[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ///cout<<inf<<endl;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>b;
        for(long i=1;i<=n;i++)tmp[i]=inf;
        tmp[0]=-inf;
        len=0;
        for(long i=1;i<=n;i++)cin>>arr[i];
        sort(arr+1,arr+n+1);
        for(long i=1;i<=n;i++)
        {
            x=arr[i];
            lo=0;
            hi=len;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                ///if(i==2)cout<<lo<<" "<<hi<<" "<<mid<<endl;
                if(x>=(tmp[mid]*k+b))lo=mid+1;
                else hi=mid-1;
                ///cout<<lo<<" "<<hi<<endl;
            }
            if(x<tmp[lo])tmp[lo]=x;
            if(len<lo)len=lo;
//            for(long i=0;i<n;i++)cout<<tmp[i]<<" ";
//            cout<<endl;
        }
        cout<<len<<endl;
    }
    return 0;
}