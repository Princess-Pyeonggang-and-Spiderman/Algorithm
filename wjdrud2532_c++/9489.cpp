#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        int N, K;

        cin >> N >> K;

        if(N == 0 && K == 0)
            break;

        int arr[1001] = {0, };
        vector<vector<pair<int, int> > > v(1001);

        // 최상단 노드 언제나 1개
        int CurrentCnt = 1, NextCnt = 1, depth = 0;

        //  목표값의 깊이         목표값의 부모       부모값        부모값 설정을 위해
        int TargetDepth = 0, TargetParent = 0, parent = 0, parentCnt = 0;;

        cin >> arr[0];

        // 최상단 노드의 부모 0으로 설정
        v[depth].push_back({arr[0], 0});
        parent = arr[0];

        for(int i = 1; i < N; i ++)
        {
            cin >> arr[i];

            //이어지지 않는 경우(다른 형제로 넘어가는 경우)
            if(arr[i] - 1 != arr[i - 1])
            {
                // 형제 카운트 --
                CurrentCnt --;

                // 형제가 바뀌었으므로 다른 부모 값을 설정하기 위해 ++
                parentCnt ++;

                // 더 이상 형제가 없을 경우 depth가 깊어진다
                if(CurrentCnt == 0)
                {
                    depth ++;                       // 깊이 추가
                    CurrentCnt = NextCnt;           // 이전 층의 형제 수 기록
                    parentCnt = i - CurrentCnt;     // 이전 층의 첫 번째 형제 index 기록
                    NextCnt = 0;                    // 새로운 층의 형제 개수 초기화
                }

                parent = arr[parentCnt];            // 부모 값 설정
            }

            // 목표값을 찾았을 경우 목표값의 깊이와 부모를 저장
            if(arr[i] == K)
            {
                TargetDepth = depth;
                TargetParent = parent;
            }

            v[depth].push_back({arr[i], parent});
            NextCnt ++;
        }

//        for(int i = 0; i <= depth; i ++)
//        {
//            cout << i << " : ";
//            for(int j = 0; j < v[i].size(); j ++)
//            {
//                cout << v[i][j].first << "(" << v[i][j].second << ") ";
//            }
//            cout << "\n";
//        }

        // 사촌의 부모의 list
        vector<int> parentlist;

        // target의 부모 depth에서 부모의 부모가 같은 것들을 찾는다.
        // 부모의 형제를 앞으로 한번, 뒤로 한번 찾는다
        for(int i = 0; i < v[TargetDepth - 1].size(); i ++)
        {
            // 목표값을 찾은 경우
            if(v[TargetDepth - 1][i].first == TargetParent)
            {
                // 현재 위치로부터
                int tempcnt = i;
                int tempnum = TargetParent;

                // 뒤로 가면서 현재와 (이전값 - 1)이 같은지 확인(형제인지 확인)
                while(1)
                {
                    if(v[TargetDepth - 1][tempcnt - 1].first == tempnum - 1)
                    {
                        parentlist.push_back(tempnum - 1);
                        tempcnt --;
                        tempnum --;
                    }
                    else
                        break;
                }

                // 앞으로 가면서 마찬가지로 진행
                tempcnt = i;
                tempnum = TargetParent;
                while(1)
                {
                    if(v[TargetDepth - 1][tempcnt + 1].first == tempnum + 1)
                    {
                        parentlist.push_back(tempnum + 1);
                        tempcnt ++;
                        tempnum ++;
                    }
                    else
                        break;
                }
                // 사촌의 수만 찾으면 되므로 자기 자신은 포함하지 않는다.
                break;
            }
        }

        int result = 0;

        // parentlist 에 들어있는 부모를 가진 값을 TargetDepth에서 찾는다
        for(int i = 0; i < parentlist.size(); i ++)
            for(int j = 0; j < v[TargetDepth].size(); j ++)
                if(v[TargetDepth][j].second == parentlist[i])
                    result ++;
        cout << result << "\n";
    }
}