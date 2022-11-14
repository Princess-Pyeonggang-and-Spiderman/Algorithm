#include <iostream>
#include <string>
#include <climits>

using namespace std;
string arr[10000][4] = { {0,}, };
bool IsVisit[10000][4] = { {false,}, };
string StrFinal;
int MinLength = INT_MAX;

int D(int num)
{
	num = num << 1;
	return (num > 9999) ? num % 10000 : num;
}

int S(int num)
{
	int temp = num - 1;
	return (temp == 0) ? 9999 : temp;
}

int L(int num)
{
	int temp = (num % 1000) * 10;
	num = num / 1000;
	
	//1 + 2340
	return num + temp;	
}

int R(int num)
{
	int temp = (num % 10) * 1000;	
	num = num / 10;			
	
	//123 + 4000
	return num + temp;
}

string addS(string str)
{
	return str + "S";
}

string addL(string str)
{
	return str + "L";
}

string addR(string str)
{
	return str + "R";
}

string addD(string str)
{
	return str + "D";
}

int UseDSLR(int value, int num)
{
	switch (num)
	{
	case 0:
		value = D(value);
		break;

	case 1:
		value = S(value);
		break;

	case 2:
		value = L(value);
		break;

	case 3:
		value = R(value);
		break;
	}

	return value;
}

string AddDSLRStr(string str, int num)
{
	switch (num)
	{
	case 0:
		str = addD(str);
		break;

	case 1:
		str = addS(str);
		break;

	case 2:
		str = addL(str);
		break;

	case 3:
		str = addR(str);
		break;
	}

	return str;
}


void dfs(int start, int dst, string CurrentStr, int D1, int D2)
{
	if (start == dst)
	{
		if(CurrentStr.length() < MinLength)
		{
			StrFinal = CurrentStr;
			return;
		}
	}

	int temp = start;

	for (int i = 0; i < 4; i++)
	{
		int temp = 0;
		string tempstr = "";

		IsVisit[D1][i] = true;
				
		//DSLR 중 하나의 과정을 진행해야함
		temp = UseDSLR(start, i);
		tempstr = AddDSLRStr("ddd", 1);

		IsVisit[D1][i] = false;

	}


	return;
}


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	int start, dst;
	cin >> T;

	for(int i = 0; i < T; i ++)
	{
		cin >> start >> dst;

		StrFinal = "";

		//0, 0 부터 시작
		dfs(start, dst, "", 0, 0);

		cout << StrFinal << "\n";
	}

	return 0;
}