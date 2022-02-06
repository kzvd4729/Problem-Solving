/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/26/2017 18:20                        
*  solution_verdict: Time limit exceeded on test 1           language: GNU C++11                               
*  run_time: 1000 ms                                         memory_used: 129600 KB                            
*  problem: https://codeforces.com/contest/779/problem/B
****************************************************************************************/
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    int k,i,cnt,o,n;
    string s;
    cin>>s;
     cin>>k;
    cnt=0;
    o=0;
    n=0;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='0')cnt++;
    }
     if(cnt<k)
    {
        cout<<s.size()-1<<endl;
    }
    else
    {
        for(i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='0')o++;
            else n++;
             if(o==k)break;
         }
         cout<<n<<endl;
     }
     main();
      return 0;
}