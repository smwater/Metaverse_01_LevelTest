// 조커를 포함한 53장의 카드를 섞어서 두 명의 플레이어에게 7장씩 배분하는 프로그램
// 카드는 중복되면 안됨
// -> 카드를 bool 배열로 받아서 카드가 있을때만 출력
// 53장의 카드
// -> 조커, 기호, 영어를 열거형으로 만들어 switch case로 구분한다.
// 두명의 플레이어에게 7장씩 배분
// -> 반복문 사용, bool 배열을 이용해 중복된 카드를 지급하지 않게 한다.

#include <iostream>
#include <string>
#define playerHandInCard 7
#define cardDeckNum 53
using namespace std;

enum Card
{
	Joker, A, J = 11, Q = 12, K = 13, Spade = 0, Clover = 13, Heart = 26, Diamond = 39
};

/// <summary>
/// 플레이어에게 카드를 나눠준다.
/// </summary>
/// <param name="cardDeck">카드덱에 카드가 남았는지 확인하는 배열</param>
/// <param name="playerArr">플레이어 번호</param>
void handOutCard(bool* cardDeck, int* playerArr)
{
	for (int count = 0; count < playerHandInCard; count++)	// 7장 배분
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
	if (cardNum == Joker)	// 조커는 0번이므로 처음부터 제외
	{
		return "Joker";
	}
	else if (cardNum > Spade && cardNum <= Clover)	// 우선 기호로 구분하고
	{
		switch (cardNum - Spade)	// 각 카드마다 기호를 빼주고
		{
		case A:						// 영어는 따로 case로 return한 후에
			return "♠A";
		case J:
			return "♠J";
		case Q:
			return "♠Q";
		case K:
			return "♠K";
		default:
			return "♠" + to_string(cardNum - Spade);	// 나머지 숫자는 to_string으로 변환 후 결합한다.
		}
	}
	else if (cardNum > Clover && cardNum <= Heart)
	{
		switch (cardNum - Clover)
		{
		case A:
			return "♣A";
		case J:
			return "♣J";
		case Q:
			return "♣Q";
		case K:
			return "♣K";
		default:
			return "♣" + to_string(cardNum - Clover);
		}
	}
	else if (cardNum > Heart && cardNum <= Diamond)
	{
		switch (cardNum - Heart)
		{
		case A:
			return "♥A";
		case J:
			return "♥J";
		case Q:
			return "♥Q";
		case K:
			return "♥K";
		default:
			return "♥" + to_string(cardNum - Heart);
		}
	}
	else if (cardNum > Diamond)
	{
		switch (cardNum - Diamond)
		{
		case A:
			return "◆A";
		case J:
			return "◆J";
		case Q:
			return "◆Q";
		case K:
			return "◆K";
		default:
			return "◆" + to_string(cardNum - Diamond);
		}
	}
}

/// <summary>
/// 플레이어가 들고 있는 카드를 출력한다.
/// </summary>
/// <param name="playerArr">플레이어가 들고 있는 카드 배열</param>
/// <param name="playerNum">어떤 플레이어인지 확인하는 변수</param>
void printPlayerCard(int* playerArr, int playerNum)
{
	cout << "Player " << playerNum << " : ";
	// 출력을 예쁘게 하기 위해 마지막 카드를 제외하고 출력
	for (int count = 0; count < playerHandInCard - 1; count++)	
	{
		cout << printCard(playerArr[count]) << ", ";
	}
	cout << printCard(playerArr[playerHandInCard - 1]) << endl;
}

int main()
{
	srand(time(NULL));	// 매번 다른 값을 출력하기 위해 seed값 추가

	// 플레이어가 어떤 카드를 들고있는지 저장할 배열 생성
	int player1[playerHandInCard]{};
	int player2[playerHandInCard]{};
	
	// 카드 덱에서 어떤 카드가 뽑혔는지 저장하는 배열
	bool cardDisappeared[cardDeckNum] = { false };

	handOutCard(cardDisappeared, player1);
	handOutCard(cardDisappeared, player2);

	printPlayerCard(player1, 1);
	printPlayerCard(player2, 2);

	return 0;
}