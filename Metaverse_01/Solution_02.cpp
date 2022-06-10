// 1000 미만의 3의 승수를 출력해야한다.
// 반복문을 돌리면서 3의 승수라면 출력하기로 한다.
#include <iostream>
using namespace std;

int main()
{
	int multiplier3 = 3;	// 3의 승수를 저장할 수 있는 변수

	for (int i = 1; i < 1000; i++)
	{
		if (i % multiplier3 == 0)	// i가 multiplier3의 배수라면
		{
			cout << i << endl;		// 출력하고
			multiplier3 *= 3;		// 그 다음 3의 승수를 찾기 위해 3을 곱함
		}
	}

	return 0;
}