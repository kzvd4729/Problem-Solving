/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2017 00:15                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/150/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int q,i,j,cnt,r,g=0,f,fir;
    cin>>q;
    cnt=0;
    fir=0;
    while(1)
    {
        r=sqrt(q)+1;
        f=0;
        for(i=2; i<=r; i++)
        {
            if(q%i==0)
            {
                cnt++;
                q=q/i;
                if(g==0)fir=q;
                g=1;
                f=1;
                break;
            }
        }
        if(f==0||q==2||q==3)break;
    }
    if(cnt%2==0)cout<<1<<endl<<fir<<endl;
    else cout<<2<<endl;
    return 0;
}