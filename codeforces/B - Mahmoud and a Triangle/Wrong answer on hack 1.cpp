/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2017 00:48                        
*  solution_verdict: Wrong answer on hack 1                  language: GNU C++11                               
*  run_time: 249 ms                                          memory_used: 2800 KB                              
*  problem: https://codeforces.com/contest/766/problem/B
****************************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long int n,arr[100000],i,x,y,z;
    while(cin>>n)
    {
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        x=0;
        y=0;
        z=0;
        sort(arr,arr+n);
        for(i=n-1; i>=0; i--)
        {
            if(arr[i]>0&&x==0)
            {
                x=arr[i];
                arr[i]=0;
                //cout<<x<<endl;
            }
            if(arr[i]>0&&y==0&&x!=0)
            {
                y=arr[i];
                arr[i]=0;
                //cout<<y<<endl;
             }
            if(arr[i]>0&&z==0&&x!=0&&y!=0)
            {
                z=arr[i];
                arr[i]=0;
                //cout<<z<<endl;
             }
         }
        if(x==0||y==0||z==0||x<0||y<0||z<0)cout<<"NO"<<endl;
        else if(y+z<=x)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
       }
       return 0;
}