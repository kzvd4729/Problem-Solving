/****************************************************************************************
*  @author: kzvd4729                                         created: 05/30/2021 19:39                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 0 ms                                            memory_used: 6 MB                                 
*  problem: https://leetcode.com/problems/check-if-word-equals-summation-of-two-words
****************************************************************************************/
int convert(string s)
{
  int ret=0;
  for(auto x:s)
  {
    ret=ret*10+x-'a';
  }
  return ret;
}
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
                return convert(firstWord)+convert(secondWord)==convert(targetWord);
            }
};