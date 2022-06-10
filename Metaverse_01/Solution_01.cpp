// �������� ������ ����� �� *�� �ٿ�����Ѵ�.
// reference�� & ���� �״�� ����ص� �ȴ�.
// �� ���� ��ü���־���ϴ� �߰��� ���� �������� ������ �ϳ� �����Ѵ�.
#include <iostream>
using namespace std;

// A
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// B
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10, b = 20;

	swap(&a, &b);
	cout << a << " " << b << endl;
	swap(a, b);
	cout << a << " " << b << endl;

	return 0;
}