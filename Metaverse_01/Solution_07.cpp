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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define squareSize 5
#define rowSize squareSize
#define columnSize squareSize

/// <summary>
/// �������� �����.
/// </summary>
/// <param name="board">���� �������� ������ �迭</param>
void makeBingoBoard(int (*board)[columnSize]);

/// <summary>
/// �������� ����Ѵ�.
/// </summary>
/// <param name="board">����� ������ �迭</param>
void printBingoBoard(int (*board)[columnSize]);

/// <summary>
/// �����ǿ��� ���ڸ� �����.
/// </summary>
/// <param name="board">üũ�� ������</param>
/// <param name="num">üũ�ؼ� ���� ����</param>
void checkBingoBoard(int (*board)[columnSize], int num);

/// <summary>
/// �����ǿ��� ���� �ϼ��Ǹ� �� ���� ��ȯ�Ѵ�.
/// </summary>
/// <param name="board">Ȯ���� ������</param>
/// <returns>�ϼ��� ���� �� ��</returns>
int checkBingoCount(int (*board)[columnSize]);

int main()
{
	srand(time(NULL));

	int bingoBoard[5][5] = {};
	bool existNum[25] = {};

	makeBingoBoard(bingoBoard);

	int bingoCount = 0;
	while (true)
	{
		printBingoBoard(bingoBoard);

		printf("���� %d���� ���� �ϼ��Ǿ����ϴ�.\n\n", bingoCount);
		printf("���ڸ� �Է��� �ּ��� : ");
		
		int num;
		scanf("%d", &num);
		checkBingoBoard(bingoBoard, num);

		bingoCount = checkBingoCount(bingoBoard);

		system("cls");
	}
}

void makeBingoBoard(int (*board)[columnSize])
{
	bool existNum[25] = {};	// �ߺ��� �����ϱ� ���� �̹� ���� ���ڸ� ������ �迭

	for (int row = 0; row < rowSize; row++)
	{
		for (int column = 0; column < columnSize; column++)
		{
			int num = rand() % 25 + 1;	// ������ �� ����
			while (existNum[num - 1])	// �迭�� �����ϴ� ���̶��
			{
				num = rand() % 25 + 1;	// ������ �� �����
			}

			board[row][column] = num;	// �������� �ʴ´ٸ� ����

			existNum[num - 1] = true;	// �迭�� �����Ѵٰ� üũ�Ѵ�
		}
	}
}

void printBingoBoard(int (*board)[columnSize])
{
	for (int row = 0; row < rowSize; row++)
	{
		for (int column = 0; column < columnSize; column++)
		{
			printf("%-4d", board[row][column]);	// ���ڸ� 4ĭ�� ���� ���ķ� ���
		}
		printf("\n\n");
	}
}

void checkBingoBoard(int (*board)[columnSize], int num)
{
	for (int row = 0; row < rowSize; row++)
	{
		for (int column = 0; column < columnSize; column++)
		{
			if (num == board[row][column])	// num�� �����ǿ� �����ִٸ�
			{
				board[row][column] = 0;		// ���ڸ� 0���� �ٲ۴�
				return;
			}
		}
	}
}

int checkBingoCount(int (*board)[columnSize])
{
	int bingoCount = 0;

	int rowBingo[5] = {};		// �������� ���� �����ϴ� �迭
	int columnBingo[5] = {};	// �������� ���� �����ϴ� �迭
	int diagonalBingo[2] = {};	// �밢���� ���� �����ϴ� �迭

	// �� ���� ���� ���Ѵ�
	for (int rowCount = 0; rowCount < rowSize; rowCount++)
	{
		columnBingo[0] += board[rowCount][0];
		columnBingo[1] += board[rowCount][1];
		columnBingo[2] += board[rowCount][2];
		columnBingo[3] += board[rowCount][3];
		columnBingo[4] += board[rowCount][4];
	}
	for (int columnCount = 0; columnCount < columnSize; columnCount++)
	{
		rowBingo[0] += board[0][columnCount];
		rowBingo[1] += board[1][columnCount];
		rowBingo[2] += board[2][columnCount];
		rowBingo[3] += board[3][columnCount];
		rowBingo[4] += board[4][columnCount];
	}
	for (int count = 0; count < squareSize; count++)
	{
		diagonalBingo[0] += board[count][count];
		diagonalBingo[1] += board[count][squareSize - 1 - count];
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

	return bingoCount;
}