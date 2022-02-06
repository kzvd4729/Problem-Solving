/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2018 17:29                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/892/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[30];
vector<int>v;
bool check(void)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum1=0,sum2=0;
            if(i==0&&j==n-1)continue;
            for(int k=i;k<=j;k++)
            {
                sum1+=arr[k];
                sum2+=arr[v[k]];
            }
            if(sum1==sum2)return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
     for(int i=0;i<n;i++)v.push_back(i);
 //    for(int i=n-1;i>=n/2;i--)v.push_back(i);
//    for(int i=0;i<n/2;i++)v.push_back(i);
     for(int i=0;i<10000;i++)
    {
        random_shuffle(v.begin(),v.end());
        if(check())
        {
            for(auto x:v)cout<<arr[x]<<" ";
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}