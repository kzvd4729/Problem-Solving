/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-28 22:09:51                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12032
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,arr[100005],i,c,mx,x,tc,n;
    while(cin>>t)
    {
        for(tc=1;tc<=t;tc++)
        {
            cin>>n;
            for(i=0;i<n;i++)
            {
                cin>>arr[i];

            }
            mx=0;
            for(i=1;i<n;i++)
            {
                x=arr[i]-arr[i-1];
                if(x>mx)mx=x;
            }
            c=mx;
            for(i=1;i<n;i++)
            {
                x=arr[i]-arr[i-1];
                if(x==mx)mx--;
                else if(x>mx)
                {
                    c++;
                    break;
                }
                //cout<<x<<" "<<mx<<endl;
            }
            cout<<"Case "<<tc<<": "<<c<<endl;
        }

    }


    return 0;
}