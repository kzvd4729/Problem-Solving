/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-07-25 12:50:42                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11462
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e8;
const int N=2e6;
int n,x;
vector<int>v;
int partition(int low, int high)
{
  int pivot = v[high];
  int i = (low - 1);
  for (int j = low; j <= high- 1; j++)
  {
    if (v[j] <= pivot)
    {
      i++;
      swap(v[i], v[j]);
    }
  }
  swap(v[i + 1], v[high]);
  return (i + 1);
}
void quickSort(int low, int high)
{
  if (low < high)
  {
    int pi = partition(low, high);
    quickSort(low, pi - 1);
    quickSort(pi + 1, high);
  }
}
int main()
{
  while(cin>>n)
  {
    if(n==0)break;
    v.clear();
    while(n--)
    {
      scanf("%d",&x);
      v.push_back(x);
    }
    random_shuffle(v.begin(),v.end());
    random_shuffle(v.begin(),v.end());
    quickSort(0,v.size()-1);
    for(int i=0;i<v.size();i++)
    {
      if(i)printf(" ");
      printf("%d",v[i]);
    }
    printf("\n");
  }
  return 0;
}