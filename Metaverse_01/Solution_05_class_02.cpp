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
	static const int MAX_DIGIT_COUNT = 100;
public:
	LimitedLotto() = default;
	LimitedLotto(const LimitedLotto& other) = delete;
	LimitedLotto& operator=(const LimitedLotto& other) = delete;
	~LimitedLotto()
	{
		Clear();
	}

	/// <summary>
	/// �ζ� ��ȣ�� �����Ѵ�. �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
	/// </summary>
	/// <param name="maxNum">�ִ� ��ȣ</param>
	/// <param name="count">���� ���� ����, �ִ� ���� ���ڴ� 100��</param>
	void Make(int maxNum, int count);

	/// <summary>
	/// �����͸� �����.
	/// </summary>
	void Clear();

	/// <summary>
	/// �ζ� ��ȣ�� ����Ѵ�. ���࿡ ������ ��ȣ�� ���ٸ� �ƹ��͵� ������� �ʴ´�.
	/// </summary>
	void Print();

private:
	int _count = 0;
	int _lotto[100] = {};
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
	// count : [1, 100]
	// 1. count�� �ּڰ�(1) ���� ���� ��
	// 2. count�� �ִ�(100) ���� Ŭ ��
	// 3. count�� �ּڰ��� �ִ� ���̿� ���� ��
	// Clamp() �� �߰����� �̾Ƴ��� �Լ�
	count = max(1, min(count, MAX_DIGIT_COUNT));
	
	_count = count;

	// 1. �̹� ������ ��ȣ�� �����ش�.
	Clear();

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

		_lotto[i] = num;						// �ߺ��� �ƴϸ� �迭�� ����
		existNum[num] = true;				// �ߺ����� üũ�ϴ� �迭�� ����
	}

	delete[] existNum;
}

/// <summary>
/// �����͸� �����.
/// /// </summary>
void LimitedLotto::Clear()
{
	_count = 0;
}

void LimitedLotto::Print()
{
	for (int i = 0; i < _count; i++)
	{
		cout << _lotto[i] << " ";			// ���
	}
}