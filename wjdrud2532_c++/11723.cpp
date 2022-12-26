#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v(20);

constexpr unsigned int Hash(const char* str)
{
    return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * Hash(str + 1) : 8603;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //cout << "start\n";

    int N;

    cin >> N;

    int num;

    int BIT = 0;

    for(int i = 0; i < N; i ++)
    {
        char s[10];
        cin >> s;

        switch (Hash(s))
        {
            case Hash("add"):
            {
                cin >> num;
                BIT |= (1 << num);
                break;
            }

            case Hash("remove"):
            {
                cin >> num;
                BIT = BIT & ~(1 << num);
                break;
            }

            case Hash("check"):
            {
                cin >> num;
                if(BIT & (1 << num))
                    cout << "1\n";
                else
                    cout << "0\n";
                break;
            }

            case Hash("toggle"):
            {
                cin >> num;
                BIT ^= (1 << num);
                break;
            }

            case Hash("all"):
            {
                // 10000 - 1 = 1111
                BIT = (1 << 21) - 1;
                break;
            }

            case Hash("empty"):
            {
                BIT = 0;
                break;
            }
        }
    }
/*
 * string s;
 * switch(s)
 *  case:"abc"
 * {
 *
 * }
 *
 */
}


/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v(20);

constexpr unsigned int Hash(const char* str)
{
    return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * Hash(str + 1) : 8603;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //cout << "start\n";

    int N;

    cin >> N;

    int num;

    for(int i = 0; i < N; i ++)
    {
        char s[10];
        cin >> s;

        switch (Hash(s))
        {
            case Hash("add"):
            {
                cin >> num;
                auto it = find(v.begin(), v.end(), num);
                if (it == v.end())  //해당 값이 없다면
                    v.push_back(num);
                break;
            }

            case Hash("remove"):
            {
                cin >> num;
                auto it = find(v.begin(), v.end(), num);
                if (it != v.end()) // 해당 값이 존재한다면
                    v.erase(it);
                break;
            }

            case Hash("check"):
            {
                cin >> num;
                auto it = find(v.begin(), v.end(), num);
                if (it != v.end()) // 해당 값이 존재한다면
                    cout << "1\n";
                else
                    cout << "0\n";
                break;
            }

            case Hash("toggle"):
            {
                cin >> num;
                auto it = find(v.begin(), v.end(), num);
                if (it != v.end()) // 해당 값이 존재한다면
                    v.erase(it);
                else               //해당 값이 없다면
                    v.push_back(num);
                break;
            }

            case Hash("all"):
            {
                v.resize(20);
                v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
                break;
            }

            case Hash("empty"):
            {
                v.clear();
                break;
            }
        }
    }

}
*/