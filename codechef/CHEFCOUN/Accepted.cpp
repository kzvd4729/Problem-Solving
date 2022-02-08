/****************************************************************************************
*  @author: kzvd4729                                         created: 06-10-2017 17:34:56                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 16.5M                                
*  problem: https://www.codechef.com/OCT17/problems/CHEFCOUN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[100005];
long num=4294967296LL,t,n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        arr[1]=100000;
        long d=(num-200000LL)/(n-2);
        for(long i=3;i<=n;i++)
        {
            arr[i]=d;
        }
        arr[2]=num-200000LL-(n-2)*d;
        for(long i=1;i<=n;i++)
        {
            cout<<arr[i];
            if(i==n)cout<<endl;
            else cout<<" ";
        }
    }
    return 0;
}