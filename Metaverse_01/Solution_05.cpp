// 최대값과 숫자 개수를 입력하면 중복되지 않는 숫자를 n개 출력하는 프로그램
// 최대값에 따라서 랜덤값을 출력해야한다.
// -> rand()%(최대값) + 1
// 정해진 개수만큼 출력
// -> 반복문 사용
// 그런데 중복되지 않는 숫자로
// -> 숫자를 인덱스로 받는 bool 배열을 만들어 값이 false일때만 출력한다
#include <iostream>

using namespace std;

int main()
{
	int maxNum, count;
	srand(time(NULL));	// 매번 다른 값을 출력하기 위해 seed값 추가

	// 입력 받는다.
	cout << "최대값 : ";
	cin >> maxNum;
	cout << "생성할 갯수 : ";
	cin >> count;

	int* lotto = new int[count];
	bool* existNum = new bool[maxNum + 1];	// 중복인지 검사하는 배열
	*existNum = { false };

	for (int i = 0; i < count; i++)			// count만큼 반복
	{
		int num = rand() % maxNum + 1;		// 1~최대값 사이의 값 생성
		while (existNum[num] == true)		// 중복이면
		{
			num = rand() % maxNum + 1;		// 다시 생성
		}

		lotto[i] = num;						// 중복이 아니면 배열에 저장
		existNum[num] = true;				// 중복인지 체크하는 배열도 갱신
	}

	for (int i = 0; i < count; i++)
	{
		cout << lotto[i] << endl;			// 출력
	}

	delete[] lotto;
	delete[] existNum;
	
	return 0;
}