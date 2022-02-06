/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/26/2017 18:26                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/779/problem/B
****************************************************************************************/
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    int k,i,cnt,o,n,l;
    string s;
    cin>>s;
     cin>>k;
    cnt=0;
    o=0;
    n=0;
    l=s.size();
    for(i=0;i<l;i++)
    {
        if(s[i]=='0')cnt++;
    }
     if(cnt<k)
    {
        cout<<l-1<<endl;
    }
    else
    {
        for(i=l-1;i>=0;i--)
        {
            if(s[i]=='0')o++;
            else n++;
             if(o==k)break;
         }
         cout<<n<<endl;
     }
     return 0;
}