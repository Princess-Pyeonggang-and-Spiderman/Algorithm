#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxPeople = 0;
int maxPrice = 0;
int salePersent[4] = {10, 20, 30, 40};

vector<int> dfsV;


void dfs(vector<vector<int>> users, vector<int> emoticons)
{
    if(dfsV.size() == emoticons.size())
    {
        int currentPeople = 0;
        int currentPrice = 0;
        
        for(int i = 0; i < users.size(); i ++)
        {
            // 할인된 가격으로 구매한 이모티콘의 총 가격 
            int saleTotalPrice = 0;

            for(int j = 0; j < dfsV.size(); j ++)
            {
                if(users[i][0] <= dfsV[j]) // 할인율이 유저의 기준보다 높으면 이모티콘 구매
                {
                    saleTotalPrice += emoticons[j] * (100 - dfsV[j]) / 100;     // 할인율 적용한 가격
                }
            }
            
            if(saleTotalPrice >= users[i][1])
                currentPeople ++;
            else
                currentPrice += saleTotalPrice;
        }
        
        if(currentPeople > maxPeople)
        {
            maxPeople = currentPeople;
            maxPrice = currentPrice;   
        }
        else if(currentPeople == maxPeople)
        {
            if(currentPrice > maxPrice)
            {
                maxPrice = currentPrice;
            }
        }
        
        return ;
    }
    
    
    for(int i = 0; i < 4; i ++)
    {
        dfsV.push_back(salePersent[i]);
        dfs(users, emoticons);
        dfsV.pop_back();
    }
    
    return ;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    dfs(users, emoticons);
    
    answer.push_back(maxPeople);
    answer.push_back(maxPrice);
    
    return answer;
}