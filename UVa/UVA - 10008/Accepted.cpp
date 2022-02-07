/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-07-25 12:18:08                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10008
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e18;
const int N=1e5;
int n,fr[1004];
string s;
vector<char>v;
void bubble_sort(void)
{
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<v.size()-i;j++)
    {
      if(fr[(int)v[j]]<fr[(int)v[j+1]])
        swap(v[j],v[j+1]);
    }
  }
}
int main()
{
  while(cin>>n)
  {
    getchar();
    memset(fr,0,sizeof(fr));
    for(int i=1;i<=n;i++)
    {
      getline(cin,s);
      //cout<<s<<endl;
      for(auto x:s)
      {
        if(x>='a'&&x<='z')
          x=x-'a'+'A';
        if(x>='A'&&x<='Z')fr[(int)x]++;
      }
    }
    v.clear();
    for(char i='A';i<='Z';i++)
      if(fr[(int)i])v.push_back(i);

    bubble_sort();

    for(auto x:v)
      cout<<x<<" "<<fr[(int)x]<<endl;

  }
  return 0;
}