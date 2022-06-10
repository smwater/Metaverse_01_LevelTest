// 배열의 값을 오름차순으로 정렬해서 반환해야한다.
// 원소의 값을 비교해서 작은 쪽을 왼쪽, 큰 쪽을 오른쪽으로 교체한다.
// 처음에는 0과 1을 그 다음엔 1과 2를 비교 후 교체한다.
// 그러면 자연스럽게 가장 큰 수가 오른쪽으로 밀린다.
// 그 다음엔 맨 끝자리를 제외하고 반복한다.
#include <iostream>

using namespace std;

/// <summary>
/// 배열을 정렬한다.
/// </summary>
/// <param name="arr">정렬하고자 하는 배열</param>
/// <param name="n">배열의 크기</param>
void sortArray(int* arr, int n)
{
	int size = n;

	for (int repeat = 0; repeat < n - 1; repeat++)	// 원소의 갯수가 5개이므로 정렬하는 과정을 4번 해야한다. 마지막 원소는 4번째 원소를 정렬할 때 정렬된다.
	{
		for (int element = 0; element < size - 1; element++)	// arr[4]와 arr[5]를 비교하는 일을 만들지 않기 위해 size - 1
		{
			if (arr[element] > arr[element + 1])	// 붙어있는 두 값을 비교
			{
				int temp = arr[element];
				arr[element] = arr[element + 1];
				arr[element + 1] = temp;
			}
		}
		size--;	// 처음엔 0~4, 그 다음엔 정렬된 arr[4]를 제외하고 조회하기 위해 size를 감소시킨다.
	}
}

int main()
{
	int arr[5] = { 5, 2, 4, 1, 3 };

	sortArray(arr, 5);

	// 정렬이 잘 됐는지 출력
	cout << "arr : [ ";
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << arr[4] << " ]" << endl;

	return 0;
}