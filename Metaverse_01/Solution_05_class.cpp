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
class LimitedLotto
{
public:
	LimitedLotto() = default;
	LimitedLotto(const LimitedLotto& other) = delete;
	LimitedLotto& operator=(const LimitedLotto& other) = delete;
	~LimitedLotto()
	{
		Clear();
	}

	void Make(int maxNum, int count);
	void Clear();
	void Print();

private:
	int _count = 0;
	int* _lotto = nullptr;
};

int main()
{
	// �Է� �޴´�.
	cout << "�ִ밪 : ";
	int maxNum;
	cin >> maxNum;
	cout << "������ ���� : ";
	int count;
	cin >> count;

	// ó�� : �ζ� ����
	LimitedLotto lotto;
	lotto.Make(maxNum, count);

	// ��� : �ζ� ��ȣ ���
	lotto.Print();

	return 0;
}

void LimitedLotto::Make(int maxNum, int count)
{
	// 1. �̹� ������ ��ȣ�� �����ش�.
	Clear();

	_count = count;

	int* lotto = new int[count];
	bool* existNum = new bool[maxNum + 1];	// �ߺ����� �˻��ϴ� �迭
	memset(existNum, 0, (size_t)(maxNum + 1));

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

	_lotto = lotto;

	delete[] existNum;
}

/// <summary>
/// �����͸� �����.
/// /// </summary>
void LimitedLotto::Clear()
{
	delete[] _lotto;
	_lotto = nullptr;
	_count = 0;
}

void LimitedLotto::Print()
{
	for (int i = 0; i < _count; i++)
	{
		cout << _lotto[i] << " ";			// ���
	}
}