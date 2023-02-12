#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    stack<string> s;

    cin >> str;

    for(int i = 0; i < str.length(); i ++)
    {
        if(str[i] == ')')
        {
            int tempnum = 0;
            while(s.top() != "(")   // 괄호 안의 모든 자리수를 tempnum에 합한다
            {
                tempnum += stoi(s.top());
                s.pop();
            }
            s.pop(); // ( 제거

            tempnum *= stoi(s.top());   // string 형에서 int 형으로 형변환 뒤 자리수 계산
            s.pop();                        // 사용한 값 삭제

            s.push(to_string(tempnum));
        }
        else if(str[i + 1] == '(')
        {
            s.push(to_string(str[i] - '0'));    //자리수가 아닌 곱셈에 필요한 값인 경우 그대로 저장한다
            s.push("(");
            i ++;
        }
        else    //  이외의 것들은 자리수의 개념으로 1로 저장
        {
            s.push("1");
        }
    }

    int result = 0;
    while (!s.empty())
    {
        result += stoi(s.top());
        s.pop();
    }

    cout << result << "\n";

    return 0;
}

/*
 * K(Q) 에서 Q의 값을 곱해야 하는 K는 string형 stack에 그대로 push 한다
 * 이외의 것들은 모두 1로 push 한다
 * ) 를 확인한 경우 ( 가 나올 때 까지 stack에 있는 값들을 형변환을 통해 int 형으로 tempnum에 저장한다
 * 각 stack 마다 자리수의 개수를 string 형으로 저장했으므로 긴 자리수에 영향을 받지 않는다
 *  -> 괄호가 이중이 아니라면 자리수가 모두 1로 저장되고 여러 개의 괄호로 쌓여있다면 계산된 자리수가 stack에 저장된다
 * 결과적으로 아래와 같은 계산 결과를 통해 stack에 정보가 저장되고
 * 마지막에 모든 값을 int 형변환을 통해 result에 합한다
 *
 * 계산 과정
 * 1 5(2) 1 3(1 2(4) 1 2(3))
 * 1 10 1 3( 1 8 1 6 )
 * 1 10 1 48
 * 60
 *
 */