/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2017 17:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/766/problem/B
****************************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long int n,a[100000],i,x,y,z;
    while(cin>>n)
    {
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int f=0;
        for(i = 2; i < n; i++)
        {
            if(a[i] < a[i - 1] + a[i - 2])
            {
                cout << "YES" << endl;
                f=1;
                break;
            }
        }
        if(f!=1)cout << "NO" << endl;
      }
       return 0;
}