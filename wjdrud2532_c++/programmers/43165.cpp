#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v;
int tnum;
bool isVisit[21] = {0, };
int answer = 0;

void dfs(int depth, int sum)
{
    if(v.size() == depth)
    {
        if(tnum == sum)
            answer ++;
        
        //cout << sum << " ";

        return ;
    }
    
    // for(int i = depth; i < v.size(); i ++)
    // {
    //     if(isVisit[i] == false)
    //     {
            // isVisit[i] = true;
            
            dfs(depth + 1, sum + v[depth]);
            dfs(depth + 1, sum - v[depth]);
            
    //         isVisit[i] = false;
    //     }
    // }
    
    return;
}

int solution(vector<int> numbers, int target) {
    
    for(int i = 0; i < numbers.size(); i ++)
        v.push_back(numbers[i]);
    
    tnum = target;
    
    dfs(0, 0);
    
    return answer;
}