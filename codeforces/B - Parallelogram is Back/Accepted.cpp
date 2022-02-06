/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2017 20:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/749/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
struct point
{
    long x;
    long y;
}arr[5];
void print(point a,point b,point c)
{
    point ab={b.x-a.x,b.y-a.y};
    point ac={c.x-a.x,c.y-a.y};
    cout<<ab.x+ac.x+a.x<<" "<<ab.y+ac.y+a.y<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     for(long i=1;i<=3;i++)
    {
        cin>>arr[i].x>>arr[i].y;
    }
    cout<<3<<endl;
    print(arr[1],arr[2],arr[3]);
    print(arr[2],arr[3],arr[1]);
    print(arr[3],arr[2],arr[1]);
     return 0;
}