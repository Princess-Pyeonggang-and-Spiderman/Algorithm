#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

pair<char, char> p[26];

//ABDCEFG
void frontprint(int i)
{
    cout << (char)(i + 'A');
    if(p[i].first != '\0')
        frontprint(p[i].first - 'A');
    
    if(p[i].second != '\0')
        frontprint(p[i].second - 'A');
    
    return;
}

void middleprint(int i)
{
    if(p[i].first != '\0')
        middleprint(p[i].first - 'A');
    
    cout << (char)(i + 'A');
    
    if(p[i].second != '\0')
        middleprint(p[i].second - 'A');
    
    return;
}

//DBEGFCA
void backprint(int i)
{
    if(p[i].first != '\0')
        backprint(p[i].first - 'A');
    
    if(p[i].second != '\0')
        backprint(p[i].second - 'A');
    
    cout << (char)(i + 'A');
    return;
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    char tempPchar, tempCchar;
    
    for(int i = 0; i < N; i ++)
    {
        cin >> tempPchar;
        
        cin >> tempCchar;
        if(tempCchar != '.')
            p[tempPchar - 'A'].first = tempCchar;
        
        cin >> tempCchar;
        if(tempCchar != '.')
            p[tempPchar - 'A'].second = tempCchar;
    }
    
    
    frontprint(0);
    cout << "\n";
    
    middleprint(0);
    cout << "\n";
    
    backprint(0);
    cout << "\n";
    
    return 0;
}


