#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    // 오늘 날짜, 유효기간, 개인정보, 
    vector<int> answer;
    
    int today_year;
    int today_month;
    int today_date;
    
    
    vector<string> today_num(3);
    int today_cnt = 0;
    for(int i = 0; i < today.size(); i ++)
    {
        if(today[i] == '.')
            today_cnt ++;
        else
            today_num[today_cnt] += today[i];
    }
    
    
    for(int i = 0; i < privacies.size(); i ++)
    {
        //privacies
        vector<string> terms_num(3);
        int terms_cnt = 0;
        
        // 날짜 추출
        for(int j = 0; j < privacies[i].size() - 2; j ++)
        {
            if(privacies[i][j] == '.')
                terms_cnt ++;
            else
                terms_num[terms_cnt] += privacies[i][j];
        }
        cout << "terms_num : " << terms_num[0] << " " << terms_num[1] << " " << terms_num[2] << "  ";
        
        char client = privacies[i][11];
        cout << client << "\n";
        
        // answer에 넣을 값 찾음
        for(int j = 0; j < terms.size(); j ++)
        {
            char target_alpa = terms[j][0];
            string target_num = terms[j].substr(1);
            
            cout << "target = " << target_alpa << "" << target_num << "\n";
            
            // 비교 후 push 여부 판단
            cout << "target_alpa : " << target_alpa << "\n";
            cout << "client : " << client << "\n";
            if(target_alpa == client)     // 같은 A일 때
            {
                //날짜 계산
                int result_total = 0;
                result_total += stoi(terms_num[0]) * 12;
                result_total += stoi(terms_num[0]) * 12;
                
                int result_year = stoi(terms_num[0]);
                
                int result_month = stoi(terms_num[1]) + stoi(target_num) ;
                if(result_month > 12)
                {
                    if(result_month % 12 == 0)      // 12로 나눠 떨어지는 경우 12를 유지해야함
                    {
                        result_year += result_month / 12 - 1;
                        result_month = 12;
                    }
                    else
                    {
                        result_year += result_month / 12;
                        result_month = result_month % 12;
                    }
                    
                    
                }
                
                int result_date = stoi(terms_num[2]);
                
                if(result_month == 0)
                {
                    result_month = 1;
                }
                
                
                cout << "result = " << result_year << " " << result_month << " " << result_date << "\n";
                    cout << "today_num : " << stoi(today_num[0]) << " " << stoi(today_num[1]) << " " << stoi(today_num[2]) << "\n";

                cout << i << " out \n";
                if(result_year < stoi(today_num[0]))
                {
                    answer.push_back(i + 1);
                }
                
                else if((result_year == stoi(today_num[0])) && result_month < stoi(today_num[1]))
                {
                    answer.push_back(i + 1);
                }
                
                else if( result_year <= stoi(today_num[0]) && result_month == stoi(today_num[1]) && result_date <= stoi(today_num[2]) )
                {
                    answer.push_back(i + 1);
                }
                
                
            }
        }
    }
    
    return answer;
}