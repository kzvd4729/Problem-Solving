/****************************************************************************************
*  @author: kzvd4729                                         created: 12/20/2019 22:38                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 0 ms                                            memory_used: 8.5 MB                               
*  problem: https://leetcode.com/problems/sequential-digits
****************************************************************************************/
class Solution {
public:
    vector<int>sequentialDigits(int low,int high) 
{
  vector<int>v;
  for(int i=1;i<=9;i++)
  {
    int x=i;v.push_back(i);
    for(int j=i+1;j<=9;j++)
    {
      x=x*10+j;v.push_back(x);
    }
  }
  sort(v.begin(),v.end());
  // for(auto x:v)
  //   cout<<x<<" ";
  // cout<<endl;
  vector<int>ret;
  for(auto x:v)if(x>=low&&x<=high)ret.push_back(x);
  return ret;
}
};