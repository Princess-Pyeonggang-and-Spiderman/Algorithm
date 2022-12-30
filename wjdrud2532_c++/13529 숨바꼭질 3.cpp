#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, K;
//int meetSecond = 0;
bool isVisit[100001] = {0,};

//struct compare_pq
//{
//    bool operator()(pair<int, int> p1, pair<int, int> p2)
//    {
//        return p1.second > p2.second;
//    }
//};

int BFS()
{
    // N의 값, 걸린시간(cost)                                 내림차순 정렬(작은 시간순으로 탐색)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    //priority_queue<pair<int, int>, vector<pair<int, int>>, compare_pq> q;

    q.push({0, N});
    isVisit[N] = true;

    int tempN;
    int tempSecond;
    while (!q.empty())
    {
        tempSecond = q.top().first;
        tempN = q.top().second;

        q.pop();

        //cout << tempN << " ";

        if (tempN == K)
        {
            return tempSecond;
        }

        if (tempN * 2 <= 100001 && !isVisit[tempN * 2])
        {
            //q.push({tempN * 2, tempSecond});
            q.push({tempSecond, tempN * 2});
            isVisit[tempN * 2] = true;
        }

        if (tempN + 1 <= 100001 && !isVisit[tempN + 1])
        {
            //q.push({tempN + 1, tempSecond + 1});
            q.push({tempSecond + 1, tempN + 1});
            isVisit[tempN + 1] = true;
        }

        if (tempN - 1 >= 0 && !isVisit[tempN - 1])
        {
            //q.push({tempN - 1, tempSecond + 1});
            q.push({tempSecond + 1, tempN - 1});
            isVisit[tempN - 1] = true;
        }
        //meetSecond++;
    }
    return 0;
}

int main()
{
    cin >> N >> K;

    int tempnum = BFS();

    cout << tempnum << "\n";
    //cout << meetSecond << "\n";

    return 0;
}
