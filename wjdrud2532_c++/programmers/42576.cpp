#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    map<int, int> m;
    
    for(int i = 0; i < nums.size(); i ++)
    {
        if(m.find(nums[i]) == m.end())  //없다면
        {
            m.insert({nums[i], 1});
            answer ++;
            
            if(answer > nums.size() / 2)
                {
                    answer --;
                    break;
                }   
        }
        else        // 있다면
        {
            
        }
    }
    

    
    return answer;
}