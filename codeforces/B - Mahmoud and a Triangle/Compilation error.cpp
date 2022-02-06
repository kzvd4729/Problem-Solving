/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2017 17:05                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/766/problem/B
****************************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long int n,arr[100000],i,x,y,z,f;
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
f=0;
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
for(i=0;i<n;i++)
{
         if(x==0||y==0||z==0||x<0||y<0||z<0)
{
f=1;
cout<<"NO"<<endl;
break;
}
 }
if(f!=1){
        else if(y+z<=x)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;}
       }
       return 0;
}