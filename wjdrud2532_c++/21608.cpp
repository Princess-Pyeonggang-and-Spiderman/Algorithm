// 21608 상어 초등학교

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int arr[401][5] = {0,};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int maxFavoriteNum = 0;
int maxEmptyNum = 0;
int minRowNum = 21;
int minColNum = 21;

queue<pair<int, int>> q;
queue<pair<int, int>> q2;

int set[21][21] = {0, };

int score = 0;

/*
queue에 maxNum = 0으로 해두고 
이것보다 크다면 이전 queue값을 모두 삭제 후 새로운 값 넣는다
이것과	같다면 queue에 값 추가
-> 좋아하는 학생이 가장 크고 같은 것들만 queue에 추가됨 

-> queue의 크기가 1이라면 그것을 set에 추가
	크기가 2 이상이라면 queue에 저장된 좌표들을 대상으로 비어있는 칸 계산 -> maxNum을 사용하여 가장 큰 것들만 queue에 추가

	-> queue의 크기가 1이라면 그것을 set에 추가
		2 이상이라면 행,열 비교 후 가장 작은 것을 추가 
*/

void findFavoriteSpot(int index)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)	// 전체 탐색
        {
            int currentY = i;
            int currentX = j;

            if (set[currentY][currentX] != 0)
                continue;

            int currentFavoriteNum = 0;

            for (int k = 0; k < 4; k++)		// 상하좌우 탐색
            {
                int nextY = currentY + dy[k];
                int nextX = currentX + dx[k];

                if (nextX < 1 || nextY < 1 || nextX > n || nextY > n)	// 범위 벗어나는 경우 건너뜀
                    continue;

                for (int l = 1; l < 5; l++)	// 범위 안에 속하면서
                {
                    if (set[nextY][nextX] == arr[index][l])	// 좋아하는 친구가 있을 경우
                    {
                        currentFavoriteNum++;					// 친구 카운트 ++
                    }
                }
            }

            if (currentFavoriteNum > maxFavoriteNum)	// 가장 큰 것이 새로 발견된 경우
            {
                q = queue<pair<int, int>>();	// 기존 queue 값 초기화

                maxFavoriteNum = currentFavoriteNum;	// max 값 업데이트
                q.push({ currentY, currentX });	// 현재 좌표 추가
            }
            else if (currentFavoriteNum == maxFavoriteNum)
            {
                q.push({ currentY, currentX });
            }
            else // 현재 인근 친구의 수가 최대보다 작다면 건너뜀
            {

            }
        }
    }

    return;
}

void findEmptySpot()
{
    while (!q.empty())
    {
        int currentY = q.front().first;
        int currentX = q.front().second;
        q.pop();

        if (set[currentY][currentX] != 0)
            continue;

        int currentEmptyNum = 0;

        for (int i = 0; i < 4; i++)
        {
            int nextY = currentY + dy[i];
            int nextX = currentX + dx[i];

            if (nextX < 1 || nextY < 1 || nextX > n || nextY > n)	// 범위 벗어나는 경우 건너뜀
                continue;

            if (set[nextY][nextX] == 0)
            {
                currentEmptyNum++;
            }
        }

        if (currentEmptyNum > maxEmptyNum)	// 가장 큰 것이 새로 발견된 경우
        {
            q2 = queue<pair<int, int>>();	// 기존 queue 값 초기화

            maxEmptyNum = currentEmptyNum;	// max 값 업데이트
            q2.push({ currentY, currentX });	// 현재 좌표 추가
        }
        else if (currentEmptyNum == maxEmptyNum)
        {
            q2.push({ currentY, currentX });
        }
        else
        {

        }
    }

    return;
}

void findRowAndCol()
{
    while (!q2.empty())
    {
        int currentY = q2.front().first;
        int currentX = q2.front().second;
        q2.pop();

        if (currentX < minColNum)
        {
            minColNum = currentX;
            minRowNum = currentY;
        }
        else if (currentX == minColNum)
        {
            if (currentY < minRowNum)
            {
                minColNum = currentX;
                minRowNum = currentY;
            }
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n * n; i++)
    {
        int tempindex = 0;
        cin >> tempindex;

        arr[tempindex][0] = tempindex;

        for (int j = 1; j < 5; j++)
        {
            cin >> arr[tempindex][j];
        }

        findFavoriteSpot(tempindex);	// 인근의 좋아하는 친구가 가장 많은 자리를 찾는다.

        if (q.size() > 1)	// 만족하는 칸이 둘 이상인 경우
        {
            findEmptySpot();	// 비어있는 칸이 가장 많은 자리를 찾는다.

            if (q2.size() > 1)	// 비어있는 칸의 개수도 둘 이상인 경우, 행-열이 가장 작은 것을 찾는다.
            {
                findRowAndCol();
                set[minRowNum][minColNum] = arr[tempindex][0];
            }
            else
            {
                set[q2.front().first][q2.front().second] = arr[tempindex][0];
            }
        }
        else
        {
            set[q.front().first][q.front().second] = arr[tempindex][0];
        }

        q = queue<pair<int, int>>();
        q2 = queue<pair<int, int>>();
        maxFavoriteNum = 0;
        maxEmptyNum = 0;
        minRowNum = 21;
        minColNum = 21;
    }

    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << set[i][j] << " ";
        }
        cout << "\n";
    }
    */

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int currentY = i;
            int currentX = j;

            int tempFriendCnt = 0;

            for (int k = 0; k < 4; k++)
            {
                int nextY = currentY + dy[k];
                int nextX = currentX + dx[k];

                if (nextX < 1 || nextY < 1 || nextX > n || nextY > n)	// 범위 벗어나는 경우 건너뜀
                    continue;

                for (int l = 1; l < 5; l++)	// 범위 안에 속하면서
                {
                    if (set[nextY][nextX] == arr[set[currentY][currentX]][l])	// 좋아하는 친구가 있을 경우
                    {
                        tempFriendCnt++;					// 친구 카운트 ++
                    }
                }
            }

            if (tempFriendCnt == 1)
                score += 1;
            else if (tempFriendCnt == 2)
                score += 10;
            else if (tempFriendCnt == 3)
                score += 100;
            else if (tempFriendCnt == 4)
                score += 1000;
        }
    }

    cout << score << "\n";

    return 0;
}