/****************************************************************************************
*  @author: kzvd4729                                         created: 01/28/2022 20:25                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 0 ms                                            memory_used: 5.9 MB                               
*  problem: https://leetcode.com/problems/minimum-moves-to-reach-target-score
****************************************************************************************/
class Solution {
public:
    int minMoves(int target, int maxDoubles) 
    {
        int cnt=0;
        while(true)
        {
            if(maxDoubles==0)break;
            if(target==1)break;
                        if(target%2)cnt++,target--;
            else cnt++,target/=2,maxDoubles--;
        }
        cnt+=(target-1);
        return cnt;
    }
};