/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-12 22:16:15                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10041
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,av,arr[4004];
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum=sum+arr[i];
        }
        int x=sum/n;
        int z=0;
        for(int i=0;i<n;i++)
        {
            z=z+abs(arr[i]-x);
        }

        int zz=0;
        x++;
        for(int i=0;i<n;i++)
        {
            zz=zz+abs(arr[i]-x);
        }

        cout<<min(z,zz)<<endl;
    }

    return 0;
}