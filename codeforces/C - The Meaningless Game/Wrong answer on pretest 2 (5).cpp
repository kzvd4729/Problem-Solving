/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/30/2017 22:29                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/834/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,a,b,z,x,q,i,l;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cin>>n;
    while(n--)
    {
        cin>>a>>b;
         int f=0;
         for(i=2; i<=32000; i++)
        {
            while(a%(i*i)==0&&b%i==0)
            {
                a=a/(i*i);
                b=b/i;
            }
            while(b%(i*i)==0&&a%i==0)
            {
                b=b/(i*i);
                a=a/i;
            }
            if(a==1&&b==1)
            {
                f=1;
                break;
            }
        }
         if(f==0)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
 