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
	/// ī�带 7�� �̾Ƽ� ���� �����Ѵ�.
	/// ��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�.
	/// </summary>
	/// <returns>���� ���������� �������� ��� true, �ƴϸ� false</returns>
	bool Make()
	{
		if (existedCard < 7)
		{
			return false;
		}

		for (int i = 0; i < 7; i++)	// 7�� ���
		{
			int card = rand() % cardDeckNum;	// �ϴ� ī�带 �����ϰ�
			while (isUsedCard[card])			// �̹� ���� ī���
			{
				card = rand() % cardDeckNum;	// �ٽ� ����
			}

			isUsedCard[card] = true;			// ī�尡 ���Ҵٸ� �̾Ҵٰ� üũ�ϰ�
			_deck[i] = card;					// �迭�� �����Ѵ�
		}

		existedCard -= 7;

		return true;
	}

	// ToString()
	//		: ���� ���� ī�带 ǥ���ϴ� ���ڿ��� �����.
	//		  ī�尡 ���� ��� "The deck is empty" �� ��ȯ�Ѵ�.
	//		  ���� : ��9 ��A ��J ��K ��A ��8 ��Q
	string ToString()
	{
		string result = "";

		// ���� �ϼ����� �ʾ��� ���,
		// �Ʒ��� ������ �������� �ʰ� ��ȯ�Ѵ�.
		if (_deck[0] == -1)
		{
			return "The deck is empty";
		}

		// Lookup Table
		static const string cardShape[] = { "��", "��", "��", "��" };
		static const string cardNum[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
		
		// ���� ��� ���Ҹ� ���ڿ��� ��ȯ 
		for (int i = 0; i < 7; i++)
		{
			if (_deck[i] / 13 == 4)	// ī���� ����� ������������ �����Ѵ�.
			{
				result += "Joker ";	
				continue;			// ��Ŀ��� �Ʒ��� ������ �������� �ʰ� ���� ���� Ȯ��
			}

			result += cardShape[_deck[i] / 13];	// ���� ī���� ���
			result += cardNum[_deck[i] % 13];	// �������� ī���� ����(Ȥ�� ����)

			result += " ";	// �������� ���� space �߰�
		}

		return result;		// ���ļ� ��ȯ
	}

private:
	int _deck[7] = { -1 };
};

bool Deck::isUsedCard[cardDeckNum] = { false };
int Deck::existedCard = cardDeckNum;

int main()
{
	srand(time(NULL));	// �Ź� �ٸ� ���� ����ϱ� ���� seed�� �߰�

	const int playerNum = 10;

	Deck deck[playerNum];
	for (int i = 0; i < playerNum; i++)
	{
		if (false == deck[i].Make())
		{
			cout << i + 1 << "��° �÷��̾�� �� ���� ����\n";
		}
	}

	cout << endl;

	for (int i = 0; i < playerNum; i++)
	{
		cout << "Player " << i + 1 << " : " << deck[i].ToString() << endl;
	}

	return 0;
}