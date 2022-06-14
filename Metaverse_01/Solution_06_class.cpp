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

// 카드 덱에서 어떤 카드가 뽑혔는지 저장하는 배열
bool isUsedCard[cardDeckNum] = { false };

// Deck 타입
// 1. 모든 덱은 카드가 중복되지 않아야 한다.
// Make()
//     : 카드를 7장 뽑아서 덱을 구성한다. 
//		 모든 덱은 카드가 중복되지 않아야 한다.
//       단, 카드가 충분치 않은 경우 만들어지지 못할 수 있다.
//		 Deck decks[7]; decks.Make();
//		 Deck deck; deck.Make(); // 실패
// ToString()
//     : 현재 덱의 카드를 표현하는 문자열을 만든다.
//		 카드가 없는 경우 "The deck is empty"로 반환한다.
class Deck
{
	enum Card
	{
		A, J = 10, Q = 11, K = 12, Spade = 0, Clover = 13, Heart = 26, Diamond = 39, Joker = 52
	};

public:
	Deck() = default;
	Deck(const Deck& other) = delete;
	Deck& operator=(const Deck& other) = delete;
	~Deck()
	{
		Clear();
	}

	void Clear()
	{
		_existedCardNum = 53;
		_playerNum = 0;
		memset(deck, 0, 7);
	}

	/// <summary>
	/// 카드를 7장 뽑아서 덱을 구성한다.
	/// 모든 덱은 카드가 중복되지 않아야 한다.
	/// </summary>
	/// <returns>덱이 성공적으로 구성됐을 경우 true, 아니면 false</returns>
	bool Make()
	{
		if (_existedCardNum < 7)
		{
			return false;
		}

		for (int count = 0; count < 7; count++)	// 7장 배분
		{
			int card = rand() % cardDeckNum;	// 일단 카드를 생성하고
			while (isUsedCard[card])			// 이미 뽑은 카드면
			{
				card = rand() % cardDeckNum;	// 다시 생성
			}

			isUsedCard[card] = true;			// 카드가 남았다면 뽑았다고 체크하고
			deck[count] = card;					// 배열에 저장한다
		}

		_existedCardNum -= 7;

		return true;
	}

	string ToString(int Num)
	{
		string cardName;	// 카드 이름을 저장할 변수 생성

		static const string cardShape[] = { "♠", "♣", "♥", "◆" };
		static const string cardNum[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

		if (Num / 13 == 4)
		{
			return "Joker";
		}

		cardName = cardShape[Num / 13];
		cardName += cardNum[Num % 13];

		return cardName;
	}

	void Print()
	{
		if (deck[6] == 0)
		{
			cout << "The deck is empty" << endl;
			return;
		}

		cout << "Player : ";
		// 출력을 예쁘게 하기 위해 마지막 카드를 제외하고 출력
		for (int count = 0; count < 6; count++)
		{
			cout << ToString(deck[count]) << ", ";
		}
		cout << ToString(deck[6]) << endl;
	}

private:
	int _existedCardNum = 53;
	int _playerNum = 0;
	int deck[7] = {};
};

int main()
{
	srand(time(NULL));	// 매번 다른 값을 출력하기 위해 seed값 추가

	Deck player1;
	player1.Make();
	player1.Print();

	Deck player2;
	player2.Make();
	player2.Print();

	Deck player3;
	player3.Make();
	player3.Print();

	Deck player4;
	player4.Make();
	player4.Print();

	Deck player5;
	player5.Make();
	player5.Print();

	Deck player6;
	player6.Make();
	player6.Print();

	Deck player7;
	player7.Make();
	player7.Print();

	Deck player8;
	player8.Make();
	player8.Print();

	return 0;
}