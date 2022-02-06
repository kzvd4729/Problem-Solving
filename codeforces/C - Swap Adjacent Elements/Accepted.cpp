/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2018 21:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/920/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int arr[200005],mxx[200005],mx,n;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    mx=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mx=max(mx,arr[i]);
        mxx[i]=mx;
    }
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            if(mxx[i]>(i+1))
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}