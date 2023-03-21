#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
string order;
pair<int, int> xSort[100001];   // x좌표를 first에
pair<int, int> ySort[100001];   // x좌표를 second에

// pair 배열이 넘어가지 않아 두 함수로 나눔
// pair 이분탐색 알고리즘
int ybinary(pair<int, int> target)
{
    int low = 0, high = N - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(ySort[mid].first == target.first)
        {
            if(ySort[mid].second == target.second)
                return mid;

            if(ySort[mid].second < target.second)
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        {
            if(ySort[mid].first < target.first)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int xbinary(pair<int, int> target)
{
    int low = 0, high = N - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(xSort[mid].first == target.first)
        {
            if(xSort[mid].second == target.second)
                return mid;

            if(xSort[mid].second < target.second)
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        {
            if(xSort[mid].first < target.first)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i ++)
    {
        cin >> xSort[i].first >> xSort[i].second;

        ySort[i].second = xSort[i].first;
        ySort[i].first = xSort[i].second;
    }

    // 이분탐색을 위한 정렬
    sort(xSort, xSort + N);
    sort(ySort, ySort + N);

    cin >> order;

    // 현재 x, y 값
    int currentX = 0;
    int currentY = 0;

    // currentX, Y의 값을 갖는 지점을 가리키는 값
    int xLoc, yLoc;

    pair<int, int> tempP;
    tempP.first = tempP.second = 0;

    // xLoc, yLoc의 초기 위치는 0, 0으로 설정
    xLoc = xbinary(tempP);
    yLoc = ybinary(tempP);

    // 입력받은 문자열 길이만큼 반복
    for(int i = 0; i < order.length(); i ++)
    {
        /*
         *  xSort = (3,1) (3,2) (3,3) (4,1)
         *  ySort = (1,3) (1,4) (2,3) (3,3) 이 되므로
         *  R 일 때, x값은 현재 x에서 한단계 더 큰 값이 되어야 한다.
         *  그러나 x위치를 기준으로 sort 한 경우 뒤에 x가 같은 값이 나오므로 ++, --로 바로 찾을 수 없다
         *  ySort에는 같은 y값을 기준으로 바로 직후(-- ++)에 다음 x좌표가 있으므로
         *
         *  x값 증감을 위해 ySort를 사용, y값 증감을 위해 xSort를 사용한다
         *
         *  이후 서로의 좌표 위치를 같게 하기 위해 이분탐색으로 현재 값을 가진 index를 찾는다
         */
        if(order[i] == 'R') // x 가 + 됨
        {
            yLoc ++;

            currentX = ySort[yLoc].second;
            currentY = ySort[yLoc].first;

            xLoc = xbinary(make_pair(currentX, currentY));
        }
        else if(order[i] == 'L')    // x 가 - 됨
        {
            yLoc --;

            currentX = ySort[yLoc].second;
            currentY = ySort[yLoc].first;

            xLoc = xbinary(make_pair(currentX, currentY));
        }
        else if(order[i] == 'U')    // y가 + 됨
        {
            xLoc ++;

            currentX = xSort[xLoc].first;
            currentY = xSort[xLoc].second;

            yLoc = ybinary(make_pair(currentY, currentX));
        }
        else        // DOWN     y가 - 됨
        {
            xLoc --;

            currentX = xSort[xLoc].first;
            currentY = xSort[xLoc].second;

            yLoc = ybinary(make_pair(currentY, currentX));
        }
    }
    cout << currentX << " " << currentY << "\n";
}