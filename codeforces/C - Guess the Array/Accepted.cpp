/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/26/2018 11:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/727/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int n,ab,bc,ac,x,arr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
   cout<<"? "<<1<<" "<<2<<endl;
  fflush(stdout);
  cin>>ab;
   cout<<"? "<<2<<" "<<3<<endl;
  fflush(stdout);
  cin>>bc;
   cout<<"? "<<1<<" "<<3<<endl;
  fflush(stdout);
  cin>>ac;
   arr[1]=(ab+ac-bc)/2;
   arr[2]=ab-arr[1];
  arr[3]=ac-arr[1];
   for(int i=4;i<=n;i++)
  {
    cout<<"? "<<1<<" "<<i<<endl;
    fflush(stdout);
    cin>>x;
    arr[i]=x-arr[1];
  }
   cout<<"!";
  for(int i=1;i<=n;i++)
    cout<<" "<<arr[i];
  cout<<endl;
   return 0;
}