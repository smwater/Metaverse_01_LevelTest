// 조커를 포함한 53장의 카드를 섞어서 두 명의 플레이어에게 7장씩 배분하는 프로그램
// 카드는 중복되면 안됨
// -> 카드를 bool 배열로 받아서 카드가 있을때만 출력
// 53장의 카드
// -> 조커, 기호, 영어를 열거형으로 만들어 switch case로 구분한다.
// 두명의 플레이어에게 7장씩 배분
// -> 반복문 사용, bool 배열을 이용해 중복된 카드를 지급하지 않게 한다.
#include <iostream>
#include <string>

#define cardDeckNum 53

using namespace std;

enum Card
{
	A, J = 10, Q = 11, K = 12, Spade = 0, Clover = 13, Heart = 26, Diamond = 39, Joker = 52
};

/// <summary>
/// 플레이어에게 카드를 나눠준다.
/// </summary>
/// <param name="cardDeck">카드덱에 카드가 남았는지 확인하는 배열</param>
/// <param name="playerArr">플레이어 번호</param>
/// <param name="handCard">나눠줄 카드 수</param>
void handOutCard(bool* cardDeck, int* playerArr, int handCard)
{
	for (int count = 0; count < handCard; count++)	// n장 배분
	{
		int card = rand() % cardDeckNum;	// 일단 카드를 생성하고
		while (cardDeck[card])				// 이미 뽑은 카드면
		{
			card = rand() % cardDeckNum;	// 다시 생성
		}
		cardDeck[card] = true;				// 중복이 아니면 뽑았다고 체크하고

		playerArr[count] = card;			// 배열에 저장한다
	}
}

/// <summary>
/// 숫자를 받아 카드로 출력해준다.
/// </summary>
/// <param name="cardNum">카드 숫자</param>
/// <returns>출력할 카드 이름</returns>
string printCard(int cardNum)
{
	string cardName;	// 카드 이름을 저장할 변수 생성

	switch (cardNum / 13)	// 각 카드마다 기호를 빼주고
	{
	case 0:
		cardName = "♠";
		break;
	case 1:
		cardName = "♣";
		break;
	case 2:
		cardName = "♥";
		break;
	case 3:
		cardName = "◆";
		break;
	default:
		return "Joker";		// 조커는 바로 반환해준다
	}

	switch (cardNum % 13)	
	{
	case A:						// 영어는 case로 따로 변환한 후에
		cardName += "A";
		break;
	case J:
		cardName += "J";
		break;
	case Q:
		cardName += "Q";
		break;
	case K:
		cardName += "K";
		break;
	default:
		cardName += to_string(cardNum % 13 + 1);	// 나머지 숫자는 to_string으로 변환 후 결합한다.
	}
	
	return cardName;
}

/// <summary>
/// 플레이어가 들고 있는 카드를 출력한다.
/// </summary>
/// <param name="playerArr">플레이어가 들고 있는 카드 배열</param>
/// <param name="handCard">플레이어가 든 카드의 수</param>
/// <param name="playerNum">어떤 플레이어인지 확인하는 변수</param>
void printPlayerCard(int* playerArr, int handCard, int num)
{
	cout << "Player " << num + 1 << " : ";
	// 출력을 예쁘게 하기 위해 마지막 카드를 제외하고 출력
	for (int count = 0; count < handCard - 1; count++)
	{
		cout << printCard(playerArr[count]) << ", ";
	}
	cout << printCard(playerArr[handCard - 1]) << endl;
}

int main()
{
	srand(time(NULL));	// 매번 다른 값을 출력하기 위해 seed값 추가

	int playerNum;
	cout << "카드를 나눠줄 플레이어 수 : ";
	cin >> playerNum;

	int handCard;
	cout << "나눠줄 카드 수 : ";
	cin >> handCard;

	// 플레이어가 어떤 카드를 들고있는지 저장할 정적 배열 생성
	// int player[playerNum][playerHandInCard]{};

	// 플레이어가 어떤 카드를 들고있는지 저장할 동적 배열 생성
	int** player = new int* [playerNum];
	for (int i = 0; i < playerNum; i++)
	{
		player[i] = new int[handCard];
	}

	// 카드 덱에서 어떤 카드가 뽑혔는지 저장하는 배열
	bool cardDisappeared[cardDeckNum] = { false };

	for (int i = 0; i < playerNum; i++)
	{
		handOutCard(cardDisappeared, player[i], handCard);
	}

	for (int i = 0; i < playerNum; i++)
	{
		printPlayerCard(player[i], handCard, i);
	}

	// 할당 해제
	for (int i = 0; i < playerNum; i++)
	{
		delete[] player[i];
	}

	return 0;
}