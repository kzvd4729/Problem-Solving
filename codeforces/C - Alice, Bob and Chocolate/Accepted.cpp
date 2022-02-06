/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2017 00:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/6/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
long arr[N],n,al,bb,cal,cbb,ald,bbd,nn;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    nn=n;
    ald=0;
    bbd=n+1;
    cal=0;
    al=0;
    cbb=0;
    bb=0;
    for(long i=1;i<=n;i++)
    {
        if(nn=0)break;
        if(al==bb)
        {
            if(nn=1)
            {
                cal++;
                al+=arr[++ald];
                nn--;
            }
            else
            {
                cal++;
                al+=arr[++ald];
                nn--;
                cbb++;
                bb+=arr[--bbd];
                nn--;
            }
        }
        else if(al<bb)
        {
            cal++;
            al+=arr[++ald];
            nn--;
        }
        else
        {
            cbb++;
            bb+=arr[--bbd];
            nn--;
        }
     }
    cout<<cal<<" "<<cbb<<endl;
      return 0;
}