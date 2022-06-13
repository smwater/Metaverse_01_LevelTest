// N * N ������ �迭 �˰����� �����ϴ� ���α׷�

// ������ �迭 ũ�⸦ ������ N�� ������ �Է¹޴´�.
// -> ������ �Է� �޴´�
// -> 2���� �迭�� �����Ѵ�
// ������ �迭 �˰����� ����Ѵ�.
// -> ������ �迭�� 0,0���� �����ؼ� ���������� ���ڰ� 1�� �����ϴ� �迭
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>

using namespace std;

/// <summary>
/// ũ�⸦ �Է� �޾Ƽ� ������ �迭�� ����� ����Ѵ�
/// </summary>
/// <param name="array">�迭�� �ּ�</param>
/// <param name="size">�迭�� ũ��</param>
/// <param name="num">���� ��</param>
/// <param name="num">���� ���� ù ��ġ</param>
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
	// ������ �迭 ���
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
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	
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