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
	static bool isUsedCard[cardDeckNum];
	static int existedCard;
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
		memset(_deck, 0, 7);
	}

	/// <summary>
	/// 카드를 7장 뽑아서 덱을 구성한다.
	/// 모든 덱은 카드가 중복되지 않아야 한다.
	/// </summary>
	/// <returns>덱이 성공적으로 구성됐을 경우 true, 아니면 false</returns>
	bool Make()
	{
		if (existedCard < 7)
		{
			return false;
		}

		for (int i = 0; i < 7; i++)	// 7장 배분
		{
			int card = rand() % cardDeckNum;	// 일단 카드를 생성하고
			while (isUsedCard[card])			// 이미 뽑은 카드면
			{
				card = rand() % cardDeckNum;	// 다시 생성
			}

			isUsedCard[card] = true;			// 카드가 남았다면 뽑았다고 체크하고
			_deck[i] = card;					// 배열에 저장한다
		}

		existedCard -= 7;

		return true;
	}

	// ToString()
	//		: 현재 덱의 카드를 표현하는 문자열을 만든다.
	//		  카드가 없는 경우 "The deck is empty" 로 반환한다.
	//		  예시 : ◆9 ♣A ♥J ♣K ♠A ♥8 ♠Q
	string ToString()
	{
		string result = "";

		// 덱이 완성되지 않았을 경우,
		// 아래의 절차를 실행하지 않고 반환한다.
		if (_deck[0] == -1)
		{
			return "The deck is empty";
		}

		// Lookup Table
		static const string cardShape[] = { "♠", "♣", "♥", "◆" };
		static const string cardNum[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
		
		// 덱의 모든 원소를 문자열로 변환 
		for (int i = 0; i < 7; i++)
		{
			if (_deck[i] / 13 == 4)	// 카드의 모양이 무엇인지부터 생각한다.
			{
				result += "Joker ";	
				continue;			// 조커라면 아래의 절차는 시행하지 않고 다음 원소 확인
			}

			result += cardShape[_deck[i] / 13];	// 몫은 카드의 모양
			result += cardNum[_deck[i] % 13];	// 나머지는 카드의 숫자(혹은 영어)

			result += " ";	// 가독성을 위해 space 추가
		}

		return result;		// 합쳐서 반환
	}

private:
	int _deck[7] = { -1 };
};

bool Deck::isUsedCard[cardDeckNum] = { false };
int Deck::existedCard = cardDeckNum;

int main()
{
	srand(time(NULL));	// 매번 다른 값을 출력하기 위해 seed값 추가

	const int playerNum = 10;

	Deck deck[playerNum];
	for (int i = 0; i < playerNum; i++)
	{
		if (false == deck[i].Make())
		{
			cout << i + 1 << "번째 플레이어는 덱 구성 실패\n";
		}
	}

	cout << endl;

	for (int i = 0; i < playerNum; i++)
	{
		cout << "Player " << i + 1 << " : " << deck[i].ToString() << endl;
	}

	return 0;
}