// N * N 달팽이 배열 알고리즘을 구현하는 프로그램

// 이차원 배열 크기를 결정할 N을 정수로 입력받는다.
// -> 정수를 입력 받는다
// -> 2차원 배열을 생성한다
// 달팽이 배열 알고리즘을 출력한다.
// -> 달팽이 배열은 0,0에서 시작해서 나선형으로 숫자가 1씩 증가하는 배열
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>

using namespace std;

/// <summary>
/// 크기를 입력 받아서 달팽이 배열을 만들고 출력한다
/// </summary>
/// <param name="size">배열의 크기</param>
void snailArray(int size)
{
	int array[100][100] = {};

	int num = 0;
	// 무슨 규칙을 만들어야할까... 시간이 부족해서 생각하지 못했다
	for (int row = 0; row < size; row++)
	{
		for (int column = 0; column < size; column++)
		{
			array[row][column] = num + 1;
			num++;
		}
	}
	
	// 저장한 배열 출력
	for (int row = 0; row < size; row++)
	{
		for (int column = 0; column < size; column++)
		{
			cout << left;
			cout << setw(4) << array[row][column];
		}
		cout << endl;
	}
}

int main()
{
	cout << "배열의 크기를 입력하세요 : ";
	
	int N;
	cin >> N;

	snailArray(N);
}