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
class LimitedLotto
{
	static const int MAX_DIGIT_COUNT = 100;
public:
	LimitedLotto() = default;
	LimitedLotto(const LimitedLotto& other) = delete;
	LimitedLotto& operator=(const LimitedLotto& other) = delete;
	~LimitedLotto()
	{
		Clear();
	}

	/// <summary>
	/// 로또 번호를 생성한다. 이미 생성된 번호가 있다면 지우고 새로 만든다.
	/// </summary>
	/// <param name="maxNum">최대 번호</param>
	/// <param name="count">생성 숫자 개수, 최대 생성 숫자는 100개</param>
	void Make(int maxNum, int count);

	/// <summary>
	/// 데이터를 지운다.
	/// </summary>
	void Clear();

	/// <summary>
	/// 로또 번호를 출력한다. 만약에 생성된 번호가 없다면 아무것도 출력하지 않는다.
	/// </summary>
	void Print();

private:
	int _count = 0;
	int _lotto[100] = {};
};

int main()
{
	// 입력 받는다.
	cout << "최대값 : ";
	int maxNum;
	cin >> maxNum;
	cout << "생성할 갯수 : ";
	int count;
	cin >> count;

	// 처리 : 로또 생성
	LimitedLotto lotto;
	lotto.Make(maxNum, count);

	// 출력 : 로또 번호 출력
	lotto.Print();

	return 0;
}

void LimitedLotto::Make(int maxNum, int count)
{
	// count : [1, 100]
	// 1. count가 최솟값(1) 보다 작을 때
	// 2. count가 최댓값(100) 보다 클 때
	// 3. count가 최솟값과 최댓값 사이에 있을 때
	// Clamp() 는 중간값을 뽑아내는 함수
	count = max(1, min(count, MAX_DIGIT_COUNT));
	
	_count = count;

	// 1. 이미 생성된 번호를 지워준다.
	Clear();

	bool* existNum = new bool[maxNum + 1];	// 중복인지 검사하는 배열
	memset(existNum, 0, (size_t)(maxNum + 1));

	srand(time(NULL));	// 매번 다른 값을 출력하기 위해 seed값 추가

	for (int i = 0; i < count; i++)			// count만큼 반복
	{
		int num = rand() % maxNum + 1;		// 1~최대값 사이의 값 생성
		while (existNum[num] == true)		// 중복이면
		{
			num = rand() % maxNum + 1;		// 다시 생성
		}

		_lotto[i] = num;						// 중복이 아니면 배열에 저장
		existNum[num] = true;				// 중복인지 체크하는 배열도 갱신
	}

	delete[] existNum;
}

/// <summary>
/// 데이터를 지운다.
/// /// </summary>
void LimitedLotto::Clear()
{
	_count = 0;
}

void LimitedLotto::Print()
{
	for (int i = 0; i < _count; i++)
	{
		cout << _lotto[i] << " ";			// 출력
	}
}