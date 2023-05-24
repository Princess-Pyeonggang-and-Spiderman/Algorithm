#include <iostream>
#include <map>
#include <tuple>

using namespace std;

int T, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T --)
    {
        cin >> N;

        // key           3개의 트리     부모 key
        map<int, tuple<int, int, int, int>> M;

        // tree 생성
        for (int i = 0; i < N - 1; i ++)
        {
            int parent, child;
            cin >> parent >> child;

            auto it = M.find(parent);

            // parent값을 가진 map이 없는 경우 새로 생성
            if (it == M.end())
            {
                M.insert({parent, make_tuple(child, 0, 0, 0)});

                // child 값을 가진 map이 없는 경우 새로 생성
                if (it == M.find(child))                //      부모 key 값 설정
                    M.insert({child, make_tuple(0, 0, 0, parent)});
            }
            else    // parent값을 가진 map이 있는 경우
            {
                //  parent map에 연결된 child 값 설정
                if (get<0>(M[parent]) == 0)          // 하위 노드가 전혀 없을 경우
                    get<0>(M[parent]) = child;
                else if (get<1>(M[parent]) == 0)    // 두 번째가 빈 경우
                    get<1>(M[parent]) = child;
                else                                   // 세 번째가 빈 경우
                    get<2>(M[parent]) = child;

                // child 의 4번째 value를 parent로 설정 (부모 값 저장)
                get<3>(M[child]) = parent;

                // child 값을 가진 map이 없는 경우 새로 생성
                it = M.find((child));
                if (it == M.end())      //                       parent 값을 알 수 있으므로 설정
                    M.insert({child, make_tuple(0, 0, 0, parent)});
            }
        }

        // 두 값의 최소 공통 조상

        // 찾고자 하는 값을 저장하는 tempP, 부모 key 개수 저장을 위한 tempCnt
        pair<int, int> tempP, tempCnt;
        cin >> tempP.first >> tempP.second;
        tempCnt.first = tempCnt.second = 1;

        // 두 값의 부모 key 저장을 위한 배열
        int arr1[10000], arr2[10000];

        // 자기 자신 저장
        arr1[0] = tempP.first;
        while (get<3>(M[tempP.first]) != 0)  // 가장 상위 노드에 닿을 때까지 반복
        {
            arr1[tempCnt.first ++] = get<3>(M[tempP.first]);
            tempP.first = get<3>(M[tempP.first]);   // 부모 key 값을 현재 값으로 설정
        }

        arr2[0] = tempP.first;
        while (get<3>(M[tempP.second]) != 0)
        {
            arr2[tempCnt.second ++] = get<3>(M[tempP.second]);
            tempP.second = get<3>(M[tempP.second]);
        }

        bool stop = false;

        // 두 배열을 완전탐색
        for (int i = 0; i < tempCnt.first; i ++)
        {
            for (int j = 0; j < tempCnt.second; j ++)
            {
                if (arr1[i] == arr2[j])
                {
                    cout << arr1[i] << "\n";
                    stop = true;
                    break;
                }
            }
            if (stop)
                break;
        }

        // tree 출력
//        for (auto tempit = M.begin(); tempit != M.end(); tempit ++)
//            cout << tempit->first << " " << get<0>(tempit->second) << " " << get<1>(tempit->second) << " " << get<2>(tempit->second) << " " << get<3>(tempit->second) << "\n";
    }
    return 0;
}

/*

#include<iostream>
#include<algorithm>

using namespace std;

int parent[10001];
bool visit[10001];
int T, N, A, B, u, v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> N;

		// 초기화
		for (int i = 1; i <= N; i++)
		{
			visit[i] = false;
			parent[i] = i;
		}

		// 간선정보 입력
		for (int i = 0; i < N - 1; i++)
		{
			cin >> A >> B;
			parent[B] = A;
		}

		// LCA 찾기
		cin >> u >> v;
		visit[u] = true;

		while (u != parent[u])
		{
			u = parent[u];
			visit[u] = true;
		}
		while (true)
		{
			if (visit[v])
			{
				cout << v << '\n';
				break;
			}
			v = parent[v];
		}

	}
}
 */