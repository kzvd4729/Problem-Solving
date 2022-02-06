/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2017 11:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/525/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int arr[100],ans;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(i%2==0)
        {
            arr[s[i]-'a']++;
        }
        else
        {
            if(arr[s[i]-'A']>0)arr[s[i]-'A']--;
            else ans++;
        }
    }
    cout<<ans<<endl;
     return 0;
}