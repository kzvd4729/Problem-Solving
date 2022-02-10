/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-11 09:58:42                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1932                                       memory_used (MB): 9.6                             
*  problem: https://vjudge.net/problem/LightOJ-1045
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
double arr[1000003];
void logarithm(void)
{
    int i;
    arr[0]=0;
    for(i=1;i<=1000000;i++)
    {
        arr[i]=log(i);
        arr[i]=arr[i]+arr[i-1];
    }
}
int main()
{
    logarithm();
    double ans;
    long long int c,t,n,tc=0,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>b;
        ans=arr[n]/log(b);
        c=(floor(ans)+1);
        cout<<"Case "<<++tc<<": "<<c<<endl;
    }
    return 0;
}