#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int H, W;
    bool block[500][500] = {false, };
    int resultSum = 0;
    
    cin >> H >> W;
    
    int tempnum;
    
    //블럭 생성
    for(int i = 0; i < W; i ++)
    {
        cin >> tempnum;

        for(int j = 0; j < tempnum; j ++)
            block[j][i] = true;
    }
    
    int left;
    int right;
    
    //가장 왼쪽 블럭, 오른쪽 블럭을 찾음
    for(int i = 0; i < H; i ++)
    {
        left = right = 0;
        
        for(int j = 0; j < W; j ++)
            if(block[i][j])
            {
                left = j;
                break;
            }
        
        for(int j = W - 1; j >= 0; j --)
            if(block[i][j])
            {
                right = j;
                break;
            }
        
        //빗물을 받을 수 있는 경우
        //범위 안에 블럭이 아닌 빈칸의 개수를 센다
        if(left != right)
            for(int j = left; j < right; j ++)
            {
                if(block[i][j] == 0)
                    resultSum ++;
            }
    }
    
    cout << resultSum << "\n";
    
    return 0;
}
