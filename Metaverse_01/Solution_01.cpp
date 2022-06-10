// 포인터형 변수는 사용할 때 *를 붙여줘야한다.
// reference는 & 없이 그대로 사용해도 된다.
// 두 값을 교체해주어야하니 중간에 값을 저장해줄 변수를 하나 선언한다.
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