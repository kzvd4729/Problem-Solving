/****************************************************************************************
*  @author: kzvd4729#                                        created: May/04/2017 09:56                        
*  solution_verdict: Runtime error on test 8                 language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/779/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
struct price
{
    int a;
    int b;
    int d;
}arr[200005];
bool cmp(price A,price B)
{
    return A.d<=B.d;
}
int main()
{
    int n,k,i,sum,j;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>arr[i].a;
    }
    for(i=0;i<n;i++)
    {
        cin>>arr[i].b;
    }
    for(i=0;i<n;i++)
    {
        arr[i].d=arr[i].a-arr[i].b;
    }
    sort(arr,arr+n,cmp);
    sum=0;
    for(i=0;(i<k||arr[i].d<=0)&&i<n;i++)
    {
        sum=sum+arr[i].a;
    }
    for(j=i;j<n;j++)
    {
        sum=sum+arr[j].b;
    }
    cout<<sum<<endl;
    return 0;
}