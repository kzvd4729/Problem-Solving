/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-12 22:20:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 40                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10041
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,av,arr[4004],i,z,ans,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ans=999999999;
        for(i=0;i<n;i++)
        {
            z=0;
            for(j=0;j<n;j++)
            {
                z=z+abs(arr[i]-arr[j]);
            }
            if(z<ans)ans=z;
        }
        cout<<ans<<endl;

    }

    return 0;
}