/****************************************************************************************
*  @author: kzvd4729                                         created: 05-09-2017 22:10:51                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 15.6M                                
*  problem: https://www.codechef.com/SEPT17/problems/MINPERM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
long arr[N],t,n;
void pre(void)
{
    for(long i=1;i<=100000;i++)
    {
        if(i%2==1)arr[i]=i+1;
        else arr[i]=i-1;
    }
}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre();
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2==0)
        {
            for(long i=1;i<=n;i++)
            {
                cout<<arr[i];
                if(i!=n)cout<<" ";
                else cout<<endl;
            }
        }
        else
        {
            long a=n-2;
            long b=n-1;
            long c=n;
            n=n-3;
            for(long i=1;i<=n;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<b<<" "<<c<<" "<<a<<endl;
        }
    }
    return 0;
}