// �ִ밪�� ���� ������ �Է��ϸ� �ߺ����� �ʴ� ���ڸ� n�� ����ϴ� ���α׷�
// �ִ밪�� ���� �������� ����ؾ��Ѵ�.
// -> rand()%(�ִ밪) + 1
// ������ ������ŭ ���
// -> �ݺ��� ���
// �׷��� �ߺ����� �ʴ� ���ڷ�
// -> ���ڸ� �ε����� �޴� bool �迭�� ����� ���� false�϶��� ����Ѵ�
#include <iostream>
#define size 10000	// bool �迭�� ũ��
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

	bool existNum[size] = { false };	// �ߺ����� ������ �̹� ���� ���ڸ� �����ϴ� �迭
	for (int i = 0; i < count; i++)	// count��ŭ �ݺ�
	{
		int num = rand() % maxNum + 1;	// 1~�ִ밪 ������ �� ����
		while (existNum[num])			// �ߺ��̸�
		{
			num = rand() % maxNum + 1;	// �ٽ� ����
		}

		cout << num << endl;			// ���
		existNum[num] = true;			// �ߺ��� �ƴϸ� �迭�� ����
	}
	
	return 0;
}