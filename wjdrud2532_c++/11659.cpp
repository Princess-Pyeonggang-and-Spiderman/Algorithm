#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    vector <int> V;
    
    cin >> N >> M;
    
    int temp1, temp2;
    
    //처음 값을 벡터에 추가
    cin >> temp1;
    V.push_back(0);
    V.push_back(temp1);
    
    for(int i = 2; i <= N; i ++)
    {
        cin >> temp1;
        V.push_back(V.back() + temp1);
    }
    
//    for(int i = 0; i < V.size(); i ++)
//        cout << V[i] << " ";
//
//    cout << "\n";
    for(int i = 0; i < M; i ++)
    {
        cin >> temp1 >> temp2;
        
        cout << V[temp2] - V[temp1 - 1] << "\n";
    }
    
}
