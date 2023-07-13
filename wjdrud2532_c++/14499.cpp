#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, x, y, K;

int map[21][21] = {0, };
int order[1001] = {0, };

int dice[7] = {0, };

// 명령이 1~4 일 경우 동, 서, 북, 남
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void moveDice(int orderNum)
{
    int tempnum;
    
    int d1, d2, d3, d4, d5, d6;
    d1 = dice[1], d2 = dice[2], d3 = dice[3];
    d4 = dice[4], d5 = dice[5], d6 = dice[6];
 
    if (orderNum == 1)
    {
        tempnum = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = tempnum;
    }
    else if (orderNum == 2)
    {
        tempnum = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = tempnum;
    }
    else if (orderNum == 3)
    {
        tempnum = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = tempnum;
    }
    else
    {
        tempnum = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = tempnum;
    }
    
    return ;
}
    /*
     2
   4 1 3
     5
     6
   
   남    1
      4 5 3
        6
        2
   
   북    6
      4 2 3
        1
        5
     
     동    2
        1 3 6
          5
          4
     
     서    2
        6 4 1
          5
          3
     
     */

int main()
{
    
    cin >> N >> M >> x >> y >> K;
    
    // 맵의 세로 크기만큼 반복
    // 맵 입력
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < M; j ++)
        {
            cin >> map[i][j];
        }
    }
    
    // 명령 입력
    for(int i = 1; i <= K; i ++)
    {
        cin >> order[i];
    }
    
    for(int i = 1; i <= K; i ++)
    {
        int currentX = x + dx[order[i]];
        int currentY = y + dy[order[i]];
        
        // 범위 안에 들어갈 경우
        // 명령이 1~4 일 경우 동(x+1), 서(x-1), 남(y+1), 북(y-1)
        if(0 <= currentX && currentX < N && 0 <= currentY && currentY < M)
        {
            // 주사위 이동
            moveDice(order[i]);
            
            if (map[currentX][currentY] == 0)
                map[currentX][currentY] = dice[6];
            else
            {
                dice[6] = map[currentX][currentY];
                map[currentX][currentY] = 0;
            }
            
            cout << dice[1] << "\n";
            
            x = currentX;
            y = currentY;
        }
    }

    return 0;
}

/*
 
 3 5 1 2 9
 6 7 3 1 4
 4 8 0 5 8
 1 2 9 6 2
 3 4 1 2 2 2 1 4 3
 
 */
