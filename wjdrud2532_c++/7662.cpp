#include <iostream>
#include <set>

using namespace std;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T, k, TempNum;
    char TempChar;
    
    
    cin >> T;
    for(int i = 0; i < T; i ++)
    {
        cin >> k;
        multiset<int> m;
        
        for(int j = 0; j < k; j ++)
        {
            cin >> TempChar >> TempNum;
            
            if(TempChar == 'I')
                m.insert(TempNum);
            else
            {
                if(m.empty())
                    continue;
                
                if (TempNum == 1)
                {
                    //auto iter = m.end();
                    //iter --;
                    //m.erase(iter);
                    m.erase(--m.end());
                }
                else
                    m.erase(m.begin());
            }
        }
        
        if(m.empty())
            cout << "EMPTY\n";
        else
        {
            //auto iter = m.end();
            //iter --;
            //cout << *iter << " " << *m.begin() << "\n";
            cout << *(--m.end()) << " " << *m.begin() << "\n";
        }
    }
    
    return 0;
}

