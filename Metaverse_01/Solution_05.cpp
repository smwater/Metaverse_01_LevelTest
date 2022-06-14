// �ִ밪�� ���� ������ �Է��ϸ� �ߺ����� �ʴ� ���ڸ� n�� ����ϴ� ���α׷�
// �ִ밪�� ���� �������� ����ؾ��Ѵ�.
// -> rand()%(�ִ밪) + 1
// ������ ������ŭ ���
// -> �ݺ��� ���
// �׷��� �ߺ����� �ʴ� ���ڷ�
// -> ���ڸ� �ε����� �޴� bool �迭�� ����� ���� false�϶��� ����Ѵ�
#include <iostream>

using namespace std;

// Lotto Ÿ��
// Make() : �ζ� ��ȣ�� �����Ѵ�. �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
// Print() : �ζ� ��ȣ�� ����Ѵ�. ���࿡ ������ ��ȣ�� ���ٸ� �ƹ��͵� ������� �ʴ´�.

/// <summary>
/// �ζ� ��ȣ�� �����.
/// </summary>
/// <param name="maxNum">�ִ� ��ȣ��</param>
/// <param name="count">���� ���� ����</param>
/// <returns>�ζ� ��ȣ�� (���� �Ҵ��)</returns>
int* MakeLotto(int maxNum, int count);

int main()
{
	// �Է� �޴´�.
	cout << "�ִ밪 : ";
	int maxNum;
	cin >> maxNum;
	cout << "������ ���� : ";
	int count;
	cin >> count;

	int* lotto = MakeLotto(maxNum, count);

	for (int i = 0; i < count; i++)
	{
		cout << lotto[i] << " ";			// ���
	}

	delete[] lotto;
	
	return 0;
}

int* MakeLotto(int maxNum, int count)
{
	int* lotto = new int[count];
	bool* existNum = new bool[maxNum + 1];	// �ߺ����� �˻��ϴ� �迭
	*existNum = { false };

	srand(time(NULL));	// �Ź� �ٸ� ���� ����ϱ� ���� seed�� �߰�

	for (int i = 0; i < count; i++)			// count��ŭ �ݺ�
	{
		int num = rand() % maxNum + 1;		// 1~�ִ밪 ������ �� ����
		while (existNum[num] == true)		// �ߺ��̸�
		{
			num = rand() % maxNum + 1;		// �ٽ� ����
		}

		lotto[i] = num;						// �ߺ��� �ƴϸ� �迭�� ����
		existNum[num] = true;				// �ߺ����� üũ�ϴ� �迭�� ����
	}
	
	return lotto;

	delete[] lotto;
	delete[] existNum;
}