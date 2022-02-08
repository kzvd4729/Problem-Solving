/****************************************************************************************
*  @author: kzvd4729                                         created: 06-08-2017 07:33:40                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/AUG17/problems/RAINBOWA
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,arr[110],cnt[50],i,f,vis[110],con[110],n,id,x;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1; i<=n; i++)cin>>arr[i];
        id=1;
        f=0;
        for(i=1; i<=n; i++)
        {
            if(con[id-1]!=arr[i])
            {
                con[id]=arr[i];
                id++;
            }
        }
        ///cout<<id<<endl;
        if(id!=14)f=1;
        for(i=1; i<=7; i++)
        {
            if(i!=con[i])
            {
                f=1;
                //cout<<"here"<<endl;
            }
            ///cout<<con[i]<<endl;
        }
        x=0;
        for(i=8; i<id; i++)
        {
            x=x+2;
            if(con[i]!=i-x)
            {
                f=1;
                ///cout<<"here"<<endl;
            }
            ///cout<<i-x<<endl;
        }
        for(i=1; i<=n; i++)
        {
            if(arr[i]!=arr[n-i+1])f=1;
        }
        if(f==1)
        {
            cout<<"no"<<endl;
            continue;
        }
        cout<<"yes"<<endl;
    }
    return 0;
}