#include <iostream>
#include <string>
#include <queue>

using namespace std;

//값에 따라 DSLR 연산 수행
int UseDSLR(int value, int num = 0)
{
    int temp;
    
    switch (num)
    {
        case 0: //D
            value = value << 1; //비트연산으로 * 2
            return (value > 9999) ? value % 10000 : value;
            
        case 1: //S
            value = value - 1;
            return (value < 0) ? 9999 : value;
            
        case 2: //L
            temp = ((value % 1000) * 10) + value / 1000;
            return temp;
            
        case 3: //R
            temp = ((value % 10) * 1000) + value / 10;
            return temp;
    }
    return value;
}

//값에 따라 DSLR string 추가
string AddDSLRStr(string str, int num)
{
    switch (num)
    {
        case 0:
            return str + "D";
            
        case 1:
            return str + "S";
            
        case 2:
            return str + "L";
            
        case 3:
            return str + "R";
    }
    return 0;
}

void bfs(int start, int dst)
{
    queue<pair<int, string>> tempQ;
    pair<int, string> tempPair;
    bool IsVisit[10001] = { false, };
    
    tempQ.push(make_pair(start, ""));

    IsVisit[start] = true;
    
    int num = 0;
    string str = "";
    
    while (!tempQ.empty())
    {
        tempPair = tempQ.front();
        tempQ.pop();
        
        num = tempPair.first;
        str = tempPair.second;
        
        if (tempPair.first == dst)
        {
            cout << tempPair.second << "\n";
            return;
        }
        
        for (int i = 0; i < 4; i++)
        {
            //DSLR 연산 수행 수 탐색여부 확인
            tempPair.first = UseDSLR(num, i);
            
            if (!IsVisit[tempPair.first])
            {
                //탐색하지 않았다면 탐색 표시, string값 추가후 queue에 push
                IsVisit[tempPair.first] = true;
                tempPair.second = AddDSLRStr(str, i);
                tempQ.push(tempPair);
            }
        }
    }
    return;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    int start, dst;
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        cin >> start >> dst;
        
        //너비 우선 탐색 시작
        bfs(start, dst);
    }
    return 0;
}
