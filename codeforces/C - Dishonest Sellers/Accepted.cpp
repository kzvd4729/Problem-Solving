/****************************************************************************************
*  @author: kzvd4729#                                        created: May/04/2017 10:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 2400 KB                              
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
    if(A.d!=B.d)return A.d<B.d;
    else return A.a<B.a;
}
int main()
{
    int n,k,i,sum,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i].a);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i].b);
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
    printf("%d\n",sum);
    return 0;
}