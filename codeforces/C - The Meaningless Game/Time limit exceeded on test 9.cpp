/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/31/2017 00:05                        
*  solution_verdict: Time limit exceeded on test 9           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/834/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,a,b,z,x,lo,hi,mid,ch;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        if(a==1&&b==1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        z=a*b;
        int f=0;
        lo=1;
        hi=1000000;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            if(mid*mid*mid==z)
            {
                ch=mid;
                f=1;
                break;
            }
            else if(mid*mid*mid<z)lo=mid+1;
            else hi=mid-1;
        }
        if(f==1)
        {
            if(a%ch==0&&b%ch==0)cout<<"Yes"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}