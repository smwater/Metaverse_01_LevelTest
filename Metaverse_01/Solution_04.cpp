// �迭�� ���� ������������ �����ؼ� ��ȯ�ؾ��Ѵ�.
// ������ ���� ���ؼ� ���� ���� ����, ū ���� ���������� ��ü�Ѵ�.
// ó������ 0�� 1�� �� ������ 1�� 2�� �� �� ��ü�Ѵ�.
// �׷��� �ڿ������� ���� ū ���� ���������� �и���.
// �� ������ �� ���ڸ��� �����ϰ� �ݺ��Ѵ�.
#include <iostream>

using namespace std;

/// <summary>
/// �迭�� �����Ѵ�.
/// </summary>
/// <param name="arr">�����ϰ��� �ϴ� �迭</param>
/// <param name="n">�迭�� ũ��</param>
void sortArray(int* arr, int n)
{
	int size = n;

	for (int repeat = 0; repeat < n - 1; repeat++)	// ������ ������ 5���̹Ƿ� �����ϴ� ������ 4�� �ؾ��Ѵ�. ������ ���Ҵ� 4��° ���Ҹ� ������ �� ���ĵȴ�.
	{
		for (int element = 0; element < size - 1; element++)	// arr[4]�� arr[5]�� ���ϴ� ���� ������ �ʱ� ���� size - 1
		{
			if (arr[element] > arr[element + 1])	// �پ��ִ� �� ���� ��
			{
				int temp = arr[element];
				arr[element] = arr[element + 1];
				arr[element + 1] = temp;
			}
		}
		size--;	// ó���� 0~4, �� ������ ���ĵ� arr[4]�� �����ϰ� ��ȸ�ϱ� ���� size�� ���ҽ�Ų��.
	}
}

int main()
{
	int arr[5] = { 5, 2, 4, 1, 3 };

	sortArray(arr, 5);

	// ������ �� �ƴ��� ���
	cout << "arr : [ ";
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << arr[4] << " ]" << endl;

	return 0;
}