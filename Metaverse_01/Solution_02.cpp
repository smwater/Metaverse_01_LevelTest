// 1000 �̸��� 3�� �¼��� ����ؾ��Ѵ�.
// �ݺ����� �����鼭 3�� �¼���� ����ϱ�� �Ѵ�.
#include <iostream>
using namespace std;

int main()
{
	int multiplier3 = 3;	// 3�� �¼��� ������ �� �ִ� ����

	for (int i = 1; i < 1000; i++)
	{
		if (i % multiplier3 == 0)	// i�� multiplier3�� ������
		{
			cout << i << endl;		// ����ϰ�
			multiplier3 *= 3;		// �� ���� 3�� �¼��� ã�� ���� 3�� ����
		}
	}

	return 0;
}