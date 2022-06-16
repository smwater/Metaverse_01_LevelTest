#include <iostream>

using namespace std;

#define squareSize 5
#define rowSize squareSize
#define columnSize squareSize

class Bingo
{
public:
	Bingo() = default;
	Bingo(const Bingo& other) = delete;
	Bingo& operator=(const Bingo& other) = delete;
	~Bingo() = default;

	void Init()
	{
		srand(time(NULL));

		bool _existNum[rowSize * columnSize] = {};	// 중복을 제외하기 위해 이미 나온 숫자를 저장할 배열

		for (int row = 0; row < rowSize; row++)
		{
			for (int column = 0; column < columnSize; column++)
			{
				int num = rand() % (rowSize * columnSize) + 1;	// 랜덤한 값 생성
				while (_existNum[num - 1])	// 배열에 존재하는 값이라면
				{
					num = rand() % (rowSize * columnSize) + 1;	// 랜덤한 값 재생성
				}

				_board[row][column] = num;	// 존재하지 않는다면 저장

				_existNum[num - 1] = true;	// 배열에 존재한다고 체크한다
			}
		}
	}
	bool isCompleted() const
	{
		if (_count < squareSize * 2 + 2)
		{
			return false;
		}

		return true;
	}
	void Print() const
	{
		for (int row = 0; row < rowSize; row++)
		{
			for (int column = 0; column < columnSize; column++)
			{
				if (_board[row][column] == 0)
				{
					cout << "♡\t";
				}
				else
				{
					cout << _board[row][column] << "\t";	// 숫자를 4칸에 왼쪽 정렬로 출력
				}
			}
			cout << "\n\n";
		}

		cout << "현재 " << _count << "줄의 빙고가 완성되었습니다.\n\n";
	}
	void Update(int num)
	{
		if (num < 1 && num > rowSize * columnSize)
		{
			return;
		}

		for (int row = 0; row < rowSize; row++)
		{
			for (int column = 0; column < columnSize; column++)
			{
				if (num == _board[row][column])	// num이 빙고판에 남아있다면
				{
					_board[row][column] = 0;		// 숫자를 0으로 바꾼다
					_count = rowBingo() + columnBingo() + diagonalBingo();
					return;
				}
			}
		}
	}

private:
	int rowBingo() const
	{
		int rowSum[rowSize] = {};
		for (int rowCount = 0; rowCount < rowSize; rowCount++)
		{
			for (int columnCount = 0; columnCount < columnSize; columnCount++)
			{
				rowSum[rowCount] += _board[rowCount][columnCount];
			}
		}

		int rowBingo = 0;
		for (int count = 0; count < rowSize; count++)
		{
			if (rowSum[count] == 0)
			{
				rowBingo++;
			}
		}

		return rowBingo;
	}
	int columnBingo() const
	{
		int columnSum[columnSize] = {};
		for (int columnCount = 0; columnCount < columnSize; columnCount++)
		{
			for (int rowCount = 0; rowCount < rowSize; rowCount++)
			{
				columnSum[columnCount] += _board[rowCount][columnCount];
			}
		}

		int columnBingo = 0;
		for (int count = 0; count < columnSize; count++)
		{
			if (columnSum[count] == 0)
			{
				columnBingo++;
			}
		}

		return columnBingo;
	}
	int diagonalBingo() const
	{
		int diagonalSum[columnSize] = {};
		for (int count = 0; count < squareSize; count++)
		{
			diagonalSum[0] += _board[count][count];
			diagonalSum[1] += _board[count][squareSize - 1 - count];
		}

		int diagonalBingo = 0;
		for (int count = 0; count < 2; count++)
		{
			if (diagonalSum[count] == 0)
			{
				diagonalBingo++;
			}
		}

		return diagonalBingo;
	}

private:	
	int _board[rowSize][columnSize] = {};
	int _count = 0;
};

int main()
{
	Bingo bingo;
	bingo.Init();

	while (false == bingo.isCompleted())
	{
		system("cls");

		bingo.Print();

		cout << "숫자를 입력해주세요 : ";
		int input;
		cin >> input;

		bingo.Update(input);
	}
}