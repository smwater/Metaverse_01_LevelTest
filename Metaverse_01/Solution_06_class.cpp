// ��Ŀ�� ������ 53���� ī�带 ��� �� ���� �÷��̾�� 7�徿 ����ϴ� ���α׷�
// ī��� �ߺ��Ǹ� �ȵ�
// -> ī�带 bool �迭�� �޾Ƽ� ī�尡 �������� ���
// 53���� ī��
// -> ��Ŀ, ��ȣ, ��� ���������� ����� switch case�� �����Ѵ�.
// �θ��� �÷��̾�� 7�徿 ���
// -> �ݺ��� ���, bool �迭�� �̿��� �ߺ��� ī�带 �������� �ʰ� �Ѵ�.
#include <iostream>
#include <string>

#define cardDeckNum 53

using namespace std;

// ī�� ������ � ī�尡 �������� �����ϴ� �迭
bool isUsedCard[cardDeckNum] = { false };

// Deck Ÿ��
// 1. ��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�.
// Make()
//     : ī�带 7�� �̾Ƽ� ���� �����Ѵ�. 
//		 ��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�.
//       ��, ī�尡 ���ġ ���� ��� ��������� ���� �� �ִ�.
//		 Deck decks[7]; decks.Make();
//		 Deck deck; deck.Make(); // ����
// ToString()
//     : ���� ���� ī�带 ǥ���ϴ� ���ڿ��� �����.
//		 ī�尡 ���� ��� "The deck is empty"�� ��ȯ�Ѵ�.
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
	/// ī�带 7�� �̾Ƽ� ���� �����Ѵ�.
	/// ��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�.
	/// </summary>
	/// <returns>���� ���������� �������� ��� true, �ƴϸ� false</returns>
	bool Make()
	{
		if (_existedCardNum < 7)
		{
			return false;
		}

		for (int count = 0; count < 7; count++)	// 7�� ���
		{
			int card = rand() % cardDeckNum;	// �ϴ� ī�带 �����ϰ�
			while (isUsedCard[card])			// �̹� ���� ī���
			{
				card = rand() % cardDeckNum;	// �ٽ� ����
			}

			isUsedCard[card] = true;			// ī�尡 ���Ҵٸ� �̾Ҵٰ� üũ�ϰ�
			deck[count] = card;					// �迭�� �����Ѵ�
		}

		_existedCardNum -= 7;

		return true;
	}

	string ToString(int Num)
	{
		string cardName;	// ī�� �̸��� ������ ���� ����

		static const string cardShape[] = { "��", "��", "��", "��" };
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
		// ����� ���ڰ� �ϱ� ���� ������ ī�带 �����ϰ� ���
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
	srand(time(NULL));	// �Ź� �ٸ� ���� ����ϱ� ���� seed�� �߰�

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