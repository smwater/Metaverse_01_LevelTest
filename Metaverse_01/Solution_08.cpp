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
/// <param name="array">배열의 주소</param>
/// <param name="size">배열의 크기</param>
/// <param name="num">시작 값</param>
/// <param name="num">값을 넣을 첫 위치</param>
void snailArray(int** array, int size, int num, int start)
{
	if (size == 1)
	{
		if (array[start][start] == 0)
		{
			array[start][start] = num;
		}
		return;
	}
	
	for (int i = start; i < size; i++)
	{
		array[start][i] = num;
		num++;
	}

	for (int i = start + 1; i < size; i++)
	{
		array[i][size - 1] = num;
		num++;
	}
	
	for (int i = size - 2; i >= start; i--)
	{
		array[size - 1][i] = num;
		num++;
	}

	for (int i = size - 2; i >= start + 1; i--)
	{
		array[i][start] = num;
		num++;
	}

	snailArray(array, size - 1, num, start + 1);
}

void printArray(int** array, int size)
{
	// 저장한 배열 출력
	for (int row = 0; row < size; row++)
	{
		for (int column = 0; column < size; column++)
		{
			cout << left;
			cout << setw(5) << array[row][column];
		}
		cout << endl;
	}
}

int main()
{
	cout << "배열의 크기를 입력하세요 : ";
	
	int N;
	cin >> N;

	if (N != 1)
	{
		int** array = new int* [N];
		for (int i = 0; i < N; i++)
		{
			array[i] = new int[N];
		}

		snailArray(array, N, 1, 0);
		printArray(array, N);

		for (int i = 0; i < N; i++)
		{
			delete[] array[i];
		}
	}
	else { cout << 1 << endl; }

	return 0;
}