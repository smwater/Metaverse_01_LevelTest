// 최대값과 숫자 개수를 입력하면 중복되지 않는 숫자를 n개 출력하는 프로그램
// 최대값에 따라서 랜덤값을 출력해야한다.
// -> rand()%(최대값) + 1
// 정해진 개수만큼 출력
// -> 반복문 사용
// 그런데 중복되지 않는 숫자로
// -> 숫자를 인덱스로 받는 bool 배열을 만들어 값이 false일때만 출력한다
#include <iostream>

using namespace std;

// Lotto 타입
// Make() : 로또 번호를 생성한다. 이미 생성된 번호가 있다면 지우고 새로 만든다.
// Print() : 로또 번호를 출력한다. 만약에 생성된 번호가 없다면 아무것도 출력하지 않는다.

/// <summary>
/// 로또 번호를 만든다.
/// </summary>
/// <param name="maxNum">최대 번호값</param>
/// <param name="count">생성 숫자 개수</param>
/// <returns>로또 번호들 (동적 할당된)</returns>
int* MakeLotto(int maxNum, int count);

int main()
{
	// 입력 받는다.
	cout << "최대값 : ";
	int maxNum;
	cin >> maxNum;
	cout << "생성할 갯수 : ";
	int count;
	cin >> count;

	int* lotto = MakeLotto(maxNum, count);

	for (int i = 0; i < count; i++)
	{
		cout << lotto[i] << " ";			// 출력
	}

	delete[] lotto;
	
	return 0;
}

int* MakeLotto(int maxNum, int count)
{
	int* lotto = new int[count];
	bool* existNum = new bool[maxNum + 1];	// 중복인지 검사하는 배열
	*existNum = { false };

	srand(time(NULL));	// 매번 다른 값을 출력하기 위해 seed값 추가

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
	
	return lotto;

	delete[] lotto;
	delete[] existNum;
}