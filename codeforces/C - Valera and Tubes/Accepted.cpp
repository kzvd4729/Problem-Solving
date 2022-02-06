/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2017 23:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/441/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long n,m,k;
    cin>>n>>m>>k;
    long left=1;
    long right=1;
    for(long i=1; i<k; i++)
    {
        cout<<2<<" ";
        cout<<left<<" "<<right<<" ";
        if(left%2==1)
        {
            right++;
            if(right>m)
            {
                left++;
                right=m;
            }
        }
        else
        {
            right--;
            if(right<1)
            {
                left++;
                right=1;
            }
        }
        cout<<left<<" "<<right<<endl;
        if(left%2==1)
        {
            right++;
            if(right>m)
            {
                left++;
                right=m;
            }
        }
        else
        {
            right--;
            if(right<1)
            {
                left++;
                right=1;
            }
        }
     }
    cout<<n*m-2*k+2<<" ";
    while(true)
    {
        cout<<left<<" "<<right<<" ";
        if(left%2==1)
        {
            right++;
            if(right>m)
            {
                left++;
                right=m;
            }
        }
        else
        {
            right--;
            if(right<1)
            {
                left++;
                right=1;
            }
        }
        if(left>n)break;
    }
    cout<<endl;
    return 0;
}