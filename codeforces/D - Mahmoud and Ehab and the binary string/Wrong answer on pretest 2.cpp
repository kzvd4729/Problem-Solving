/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2017 23:04                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/862/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,hd,lo,hi,hd1,HD;
string s;
void gen(long lo,long hi)
{
    for(long i=0;i<n;i++)
    {
        s[i]='0';
    }
    for(long i=lo-1;i<hi;i++)
    {
        s[i]='1';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=0;i<n;i++)s.push_back('0');
    cout<<"? "<<s<<endl;
    fflush(stdout);
    cin>>hd;
    HD=hd;
      lo=1;
    hi=n/2;
    while(true)
    {
        gen(lo,hi);
        cout<<"? "<<s<<endl;
        fflush(stdout);
        cin>>hd1;
          if(hd1+(hi-lo+1)==hd||hd1-(hi+lo+1)==hd)
        {
            lo=hi+lo;
            swap(lo,hi);
        }
        else
        {
            hi-=(hi/2);
        }
        hd=hd1;
         if(hi-lo+1==2)
        {
            for(long i=0;i<n;i++)
            {
                s[i]='0';
            }
            s[lo]='1';
            cout<<"? "<<s<<endl;
            fflush(stdout);
            cin>>hd1;
            if(hd1==HD)
            {
                cout<<"! "<<lo<<" "<<hi<<endl;
                return 0;
            }
            else
            {
                cout<<"! "<<hi<<" "<<lo<<endl;
                return 0;
            }
         }
    }
     return 0;
}