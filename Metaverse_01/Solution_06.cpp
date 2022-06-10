// ��Ŀ�� ������ 53���� ī�带 ��� �� ���� �÷��̾�� 7�徿 ����ϴ� ���α׷�
// ī��� �ߺ��Ǹ� �ȵ�
// -> ī�带 bool �迭�� �޾Ƽ� ī�尡 �������� ���
// 53���� ī��
// -> ��Ŀ, ��ȣ, ��� ���������� ����� switch case�� �����Ѵ�.
// �θ��� �÷��̾�� 7�徿 ���
// -> �ݺ��� ���, bool �迭�� �̿��� �ߺ��� ī�带 �������� �ʰ� �Ѵ�.

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
/// �÷��̾�� ī�带 �����ش�.
/// </summary>
/// <param name="cardDeck">ī�嵦�� ī�尡 ���Ҵ��� Ȯ���ϴ� �迭</param>
/// <param name="playerArr">�÷��̾� ��ȣ</param>
void handOutCard(bool* cardDeck, int* playerArr)
{
	for (int count = 0; count < playerHandInCard; count++)	// 7�� ���
	{
		int card = rand() % cardDeckNum;	// �ϴ� ī�带 �����ϰ�
		while (cardDeck[card])				// �̹� ���� ī���
		{
			card = rand() % cardDeckNum;	// �ٽ� ����
		}
		cardDeck[card] = true;				// �ߺ��� �ƴϸ� �̾Ҵٰ� üũ�ϰ�

		playerArr[count] = card;			// �迭�� �����Ѵ�
	}
}

/// <summary>
/// ���ڸ� �޾� ī��� ������ش�.
/// </summary>
/// <param name="cardNum">ī�� ����</param>
/// <returns>����� ī�� �̸�</returns>
string printCard(int cardNum)
{
	if (cardNum == Joker)	// ��Ŀ�� 0���̹Ƿ� ó������ ����
	{
		return "Joker";
	}
	else if (cardNum > Spade && cardNum <= Clover)	// �켱 ��ȣ�� �����ϰ�
	{
		switch (cardNum - Spade)	// �� ī�帶�� ��ȣ�� ���ְ�
		{
		case A:						// ����� ���� case�� return�� �Ŀ�
			return "��A";
		case J:
			return "��J";
		case Q:
			return "��Q";
		case K:
			return "��K";
		default:
			return "��" + to_string(cardNum - Spade);	// ������ ���ڴ� to_string���� ��ȯ �� �����Ѵ�.
		}
	}
	else if (cardNum > Clover && cardNum <= Heart)
	{
		switch (cardNum - Clover)
		{
		case A:
			return "��A";
		case J:
			return "��J";
		case Q:
			return "��Q";
		case K:
			return "��K";
		default:
			return "��" + to_string(cardNum - Clover);
		}
	}
	else if (cardNum > Heart && cardNum <= Diamond)
	{
		switch (cardNum - Heart)
		{
		case A:
			return "��A";
		case J:
			return "��J";
		case Q:
			return "��Q";
		case K:
			return "��K";
		default:
			return "��" + to_string(cardNum - Heart);
		}
	}
	else if (cardNum > Diamond)
	{
		switch (cardNum - Diamond)
		{
		case A:
			return "��A";
		case J:
			return "��J";
		case Q:
			return "��Q";
		case K:
			return "��K";
		default:
			return "��" + to_string(cardNum - Diamond);
		}
	}
}

/// <summary>
/// �÷��̾ ��� �ִ� ī�带 ����Ѵ�.
/// </summary>
/// <param name="playerArr">�÷��̾ ��� �ִ� ī�� �迭</param>
/// <param name="playerNum">� �÷��̾����� Ȯ���ϴ� ����</param>
void printPlayerCard(int* playerArr, int playerNum)
{
	cout << "Player " << playerNum << " : ";
	// ����� ���ڰ� �ϱ� ���� ������ ī�带 �����ϰ� ���
	for (int count = 0; count < playerHandInCard - 1; count++)	
	{
		cout << printCard(playerArr[count]) << ", ";
	}
	cout << printCard(playerArr[playerHandInCard - 1]) << endl;
}

int main()
{
	srand(time(NULL));	// �Ź� �ٸ� ���� ����ϱ� ���� seed�� �߰�

	// �÷��̾ � ī�带 ����ִ��� ������ �迭 ����
	int player1[playerHandInCard]{};
	int player2[playerHandInCard]{};
	
	// ī�� ������ � ī�尡 �������� �����ϴ� �迭
	bool cardDisappeared[cardDeckNum] = { false };

	handOutCard(cardDisappeared, player1);
	handOutCard(cardDisappeared, player2);

	printPlayerCard(player1, 1);
	printPlayerCard(player2, 2);

	return 0;
}