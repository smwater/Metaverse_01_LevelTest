// �ִ밪�� ���� ������ �Է��ϸ� �ߺ����� �ʴ� ���ڸ� n�� ����ϴ� ���α׷�
// �ִ밪�� ���� �������� ����ؾ��Ѵ�.
// -> rand()%(�ִ밪) + 1
// ������ ������ŭ ���
// -> �ݺ��� ���
// �׷��� �ߺ����� �ʴ� ���ڷ�
// -> ���ڸ� �ε����� �޴� bool �迭�� ����� ���� false�϶��� ����Ѵ�
#include <iostream>

using namespace std;

int main()
{
	int maxNum, count;
	srand(time(NULL));	// �Ź� �ٸ� ���� ����ϱ� ���� seed�� �߰�

	// �Է� �޴´�.
	cout << "�ִ밪 : ";
	cin >> maxNum;
	cout << "������ ���� : ";
	cin >> count;

	int* lotto = new int[count];
	bool* existNum = new bool[maxNum + 1];	// �ߺ����� �˻��ϴ� �迭
	*existNum = { false };

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

	for (int i = 0; i < count; i++)
	{
		cout << lotto[i] << endl;			// ���
	}

	delete[] lotto;
	delete[] existNum;
	
	return 0;
}