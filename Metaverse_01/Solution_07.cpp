// 1~25 까지의 숫자가 랜덤하게 배치되는 5x5빙고게임 판을 생성 후,
// 숫자 입력을 받을 때마다 해당 숫자를 지워주고 가로 세로 대각선 빙고줄이 완성될 때마다
// 빙고 개수를 갱신해서 표시해주는 빙고 게임을 제작하시오.

// 1~25 까지의 숫자
// -> rand()%25 + 1;
// -> 중복 제외
// 5x5 빙고게임 판
// -> 2차원 배열에 랜덤숫자 넣기
// 숫자 입력을 받을 때마다
// -> 반복문 + cin 사용. 
// 해당 숫자를 지워줌
// -> 배열을 탐색해서 해당 숫자를 0으로 만듦
// 빙고줄이 완성될 때마다
// -> 가로 세로는 행 열에 맞춰서
// -> 대각선은 따로 계산해서 빙고 취급
// 빙고 개수를 갱신
// -> 빙고 count 갱신
// 표시해주는
// -> 아래에 출력
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define squareSize 5
#define rowSize squareSize
#define columnSize squareSize

/// <summary>
/// 빙고판을 만든다.
/// </summary>
/// <param name="board">만든 빙고판을 저장할 배열</param>
void makeBingoBoard(int (*board)[columnSize]);

/// <summary>
/// 빙고판을 출력한다.
/// </summary>
/// <param name="board">출력할 빙고판 배열</param>
void printBingoBoard(int (*board)[columnSize]);

/// <summary>
/// 빙고판에서 숫자를 지운다.
/// </summary>
/// <param name="board">체크할 빙고판</param>
/// <param name="num">체크해서 지울 숫자</param>
void checkBingoBoard(int (*board)[columnSize], int num);

/// <summary>
/// 빙고판에서 빙고가 완성되면 줄 수를 반환한다.
/// </summary>
/// <param name="board">확인할 빙고판</param>
/// <returns>완성된 빙고 줄 수</returns>
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

		printf("현재 %d줄의 빙고가 완성되었습니다.\n\n", bingoCount);
		printf("숫자를 입력해 주세요 : ");
		
		int num;
		scanf("%d", &num);
		checkBingoBoard(bingoBoard, num);

		bingoCount = checkBingoCount(bingoBoard);

		system("cls");
	}
}

void makeBingoBoard(int (*board)[columnSize])
{
	bool existNum[25] = {};	// 중복을 제외하기 위해 이미 나온 숫자를 저장할 배열

	for (int row = 0; row < rowSize; row++)
	{
		for (int column = 0; column < columnSize; column++)
		{
			int num = rand() % 25 + 1;	// 랜덤한 값 생성
			while (existNum[num - 1])	// 배열에 존재하는 값이라면
			{
				num = rand() % 25 + 1;	// 랜덤한 값 재생성
			}

			board[row][column] = num;	// 존재하지 않는다면 저장

			existNum[num - 1] = true;	// 배열에 존재한다고 체크한다
		}
	}
}

void printBingoBoard(int (*board)[columnSize])
{
	for (int row = 0; row < rowSize; row++)
	{
		for (int column = 0; column < columnSize; column++)
		{
			printf("%-4d", board[row][column]);	// 숫자를 4칸에 왼쪽 정렬로 출력
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
			if (num == board[row][column])	// num이 빙고판에 남아있다면
			{
				board[row][column] = 0;		// 숫자를 0으로 바꾼다
				return;
			}
		}
	}
}

int checkBingoCount(int (*board)[columnSize])
{
	int bingoCount = 0;

	int rowBingo[5] = {};		// 가로줄의 합을 저장하는 배열
	int columnBingo[5] = {};	// 세로줄의 합을 저장하는 배열
	int diagonalBingo[2] = {};	// 대각선의 합을 저장하는 배열

	// 각 줄의 합을 구한다
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

	// 각 줄의 합이 0이라면 그 줄은 모두 0으로 치환.
	// 즉, 체크됐다는 것으로 빙고가 되었다고 볼 수 있다.
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