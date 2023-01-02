#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M, a, b;
bool include;
int parent[1000001];

//부모 노드를 찾는다
int find(int x)
{
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}


void merge(int a, int b)
{
    //서로의 부모 노드를 찾은 뒤
    a = find(a);
    b = find(b);

    if(a == b)
        return;

    //입력이 크기에 상관없이 들어오므로 비교를 통해 더 큰쪽에 붙힌다
    if(b > a)
        parent[b] = a;
    else
        parent[a] = b;

    return;
}

bool isUnion(int a, int b)
{
    //부모 노드를 찾은 뒤
    a = find(a);
    b = find(b);

    //부모 노드가 갖다면 true 반환
    if(a == b)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    //배열 초기화, 각자는 자신을 부모 노드로 삼는다
    for(int i = 1; i <= N; i ++)
        parent[i] = i;

    for(int i = 0; i < M; i ++)
    {
        cin >> include >> a >> b;

        if(!include)
            merge(a, b);
        else
        {
            if (isUnion(a, b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}