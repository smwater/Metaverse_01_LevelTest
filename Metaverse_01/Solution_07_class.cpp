// 1~25 ������ ���ڰ� �����ϰ� ��ġ�Ǵ� 5x5������� ���� ���� ��,
// ���� �Է��� ���� ������ �ش� ���ڸ� �����ְ� ���� ���� �밢�� �������� �ϼ��� ������
// ���� ������ �����ؼ� ǥ�����ִ� ���� ������ �����Ͻÿ�.

// 1~25 ������ ����
// -> rand()%25 + 1;
// -> �ߺ� ����
// 5x5 ������� ��
// -> 2���� �迭�� �������� �ֱ�
// ���� �Է��� ���� ������
// -> �ݺ��� + cin ���. 
// �ش� ���ڸ� ������
// -> �迭�� Ž���ؼ� �ش� ���ڸ� 0���� ����
// �������� �ϼ��� ������
// -> ���� ���δ� �� ���� ���缭
// -> �밢���� ���� ����ؼ� ���� ���
// ���� ������ ����
// -> ���� count ����
// ǥ�����ִ�
// -> �Ʒ��� ���
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#define squareSize 5
#define rowSize squareSize
#define columnSize squareSize

class Bingo
{
public:
	Bingo()
	{
		make();
	}

	~Bingo() = default;
	Bingo(const Bingo& other) = delete;
	Bingo& operator=(const Bingo& other) = delete;

	/// <summary>
	/// �������� ����Ѵ�.
	/// </summary>
	/// <param name="board">����� ������ �迭</param>
	void print();

	/// <summary>
	/// �����ǿ��� ���ڸ� �����.
	/// </summary>
	/// <param name="board">üũ�� ������</param>
	/// <param name="num">üũ�ؼ� ���� ����</param>
	void check(int num);

	/// <summary>
	/// ���� �������� �Ǻ��Ѵ�.
	/// </summary>
	/// <returns>�����ٸ� true, �ƴϸ� false�� ��ȯ�Ѵ�.</returns>
	bool isComplited();

private:
	/// <summary>
	/// �������� �����.
	/// </summary>
	/// <param name="board">���� �������� ������ �迭</param>
	void make();
	
	/// <summary>
	/// �����ǿ��� ���� �ϼ��Ǹ� �� ���� ����Ѵ�.
	/// </summary>
	/// <param name="board">Ȯ���� ������</param>
	void checkBingoCount();

	/// <summary>
	/// ���� �� ���� ��ȯ�Ѵ�.
	/// </summary>
	/// <returns>�ϼ��� ���� �� ��</returns>
	int getBingoCount()
	{
		checkBingoCount();
		return _count;
	}

	int _board[rowSize][columnSize] = {};
	int _count = 0;
};

int main()
{
	srand(time(NULL));

	Bingo bingo;

	while (bingo.isComplited() == false)
	{
		bingo.print();

		cout << "���ڸ� �Է��� �ּ��� : ";

		int num = 0;
		cin >> num;

		if (num >= 1 && num <= rowSize * columnSize)
		{
			bingo.check(num);
		}

		system("cls");
	}

	cout << "���� �ϼ�!" << endl;
}

void Bingo::make()
{
	bool _existNum[rowSize * columnSize] = {};	// �ߺ��� �����ϱ� ���� �̹� ���� ���ڸ� ������ �迭

	for (int row = 0; row < rowSize; row++)
	{
		for (int column = 0; column < columnSize; column++)
		{
			int num = rand() % (rowSize * columnSize) + 1;	// ������ �� ����
			while (_existNum[num - 1])	// �迭�� �����ϴ� ���̶��
			{
				num = rand() % (rowSize * columnSize) + 1;	// ������ �� �����
			}

			_board[row][column] = num;	// �������� �ʴ´ٸ� ����

			_existNum[num - 1] = true;	// �迭�� �����Ѵٰ� üũ�Ѵ�
		}
	}
}

void Bingo::print()
{
	for (int row = 0; row < rowSize; row++)
	{
		for (int column = 0; column < columnSize; column++)
		{
			if (_board[row][column] == 0)
			{
				cout << "��\t";
			}
			else
			{
				cout << _board[row][column] << "\t";	// ���ڸ� 4ĭ�� ���� ���ķ� ���
			}
		}
		cout << "\n\n";
	}

	cout << "���� " << getBingoCount() << "���� ���� �ϼ��Ǿ����ϴ�.\n\n";
}

void Bingo::check(int num)
{
	for (int row = 0; row < rowSize; row++)
	{
		for (int column = 0; column < columnSize; column++)
		{
			if (num == _board[row][column])	// num�� �����ǿ� �����ִٸ�
			{
				_board[row][column] = 0;		// ���ڸ� 0���� �ٲ۴�
				return;
			}
		}
	}
}

void Bingo::checkBingoCount()
{
	int bingoCount = 0;

	int rowBingo[rowSize] = {};		// �������� ���� �����ϴ� �迭
	int columnBingo[columnSize] = {};	// �������� ���� �����ϴ� �迭
	int diagonalBingo[2] = {};	// �밢���� ���� �����ϴ� �迭

	// �� ���� ���� ���Ѵ�
	for (int columnCount = 0; columnCount < columnSize; columnCount++)
	{
		for (int rowCount = 0; rowCount < rowSize; rowCount++)
		{
			columnBingo[columnCount] += _board[rowCount][columnCount];
		}
	}
	for (int rowCount = 0; rowCount < rowSize; rowCount++)
	{
		for (int columnCount = 0; columnCount < columnSize; columnCount++)
		{
			rowBingo[rowCount] += _board[rowCount][columnCount];
		}
	}
	for (int count = 0; count < squareSize; count++)
	{
		diagonalBingo[0] += _board[count][count];
		diagonalBingo[1] += _board[count][squareSize - 1 - count];
	}

	// �� ���� ���� 0�̶�� �� ���� ��� 0���� ġȯ.
	// ��, üũ�ƴٴ� ������ ���� �Ǿ��ٰ� �� �� �ִ�.
	for (int count = 0; count < squareSize; count++)
	{
		if (rowBingo[count] == 0)
		{
			bingoCount++;
		}
		if (columnBingo[count] == 0)
		{
			bingoCount++;
		}
	}

	for (int count = 0; count < 2; count++)
	{
		if (diagonalBingo[count] == 0)
		{
			bingoCount++;
		}
	}
	
	_count = bingoCount;
}

bool Bingo::isComplited()
{
	if (getBingoCount() < squareSize * 2 + 2)
	{
		return false;
	}

	return true;
}