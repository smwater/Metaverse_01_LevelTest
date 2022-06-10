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
/// <param name="size">�迭�� ũ��</param>
void snailArray(int size)
{
	int array[100][100] = {};

	int num = 0;
	// ���� ��Ģ�� �������ұ�... �ð��� �����ؼ� �������� ���ߴ�
	for (int row = 0; row < size; row++)
	{
		for (int column = 0; column < size; column++)
		{
			array[row][column] = num + 1;
			num++;
		}
	}
	
	// ������ �迭 ���
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
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	
	int N;
	cin >> N;

	snailArray(N);
}