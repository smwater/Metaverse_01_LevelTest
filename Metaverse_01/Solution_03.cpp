// 별을 찍어야 한다.
// 별은 첫 줄에 하나부터 시작해서 매 줄마다 둘씩 늘어난다.
// -> row * 2 - 1
// 별 이전에 공백을 집어넣어야한다.
// 공백은 4칸부터 시작해서 하나씩 줄어들어 네번째 줄에서 없어진다.
// -> row--
// 주어진 줄 수는 5줄이다.
#include <iostream>

using namespace std;

int main()
{
	for (int row = 1; row <= 5; row++)	// 줄 수는 한 줄씩 증가
	{
		for (int blank = 4; blank >= row; blank--)	// 빈칸은 줄이 증가할때마다 하나씩 감소
		{
			cout << ' ';
		}
		for (int star = 1; star <= row * 2 - 1; star++)	// 별은 줄이 증가할 때마다 2배 - 1만큼 증가
		{
			cout << '*';
		}
		cout << endl;
	}

	return 0;
}