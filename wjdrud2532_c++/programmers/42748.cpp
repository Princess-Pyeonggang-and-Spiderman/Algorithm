#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    //   전체 횟수
    for(int i = 0; i < commands.size(); i ++)
    {
        vector<int> tempv;
        for(int j = commands[i][0] - 1; j < commands[i][1]; j ++)
        {
            tempv.push_back(array[j]);
            cout << array[j] << " ";
        }
        cout << "\n";
        
        sort(tempv.begin(), tempv.end());
        
        answer.push_back(tempv[commands[i][2] - 1]);
        // cout << tempv[1];
        //commands[i][2] 번째의 값을 answer에 push
    }
    
    return answer;
}







