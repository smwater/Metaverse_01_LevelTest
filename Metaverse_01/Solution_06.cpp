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

enum Card
{
	A, J = 10, Q = 11, K = 12, Spade = 0, Clover = 13, Heart = 26, Diamond = 39, Joker = 52
};

/// <summary>
/// �÷��̾�� ī�带 �����ش�.
/// </summary>
/// <param name="cardDeck">ī�嵦�� ī�尡 ���Ҵ��� Ȯ���ϴ� �迭</param>
/// <param name="playerArr">�÷��̾� ��ȣ</param>
/// <param name="handCard">������ ī�� ��</param>
void handOutCard(bool* cardDeck, int* playerArr, int handCard)
{
	for (int count = 0; count < handCard; count++)	// n�� ���
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
	string cardName;	// ī�� �̸��� ������ ���� ����

	switch (cardNum / 13)	// �� ī�帶�� ��ȣ�� ���ְ�
	{
	case 0:
		cardName = "��";
		break;
	case 1:
		cardName = "��";
		break;
	case 2:
		cardName = "��";
		break;
	case 3:
		cardName = "��";
		break;
	default:
		return "Joker";		// ��Ŀ�� �ٷ� ��ȯ���ش�
	}

	switch (cardNum % 13)	
	{
	case A:						// ����� case�� ���� ��ȯ�� �Ŀ�
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
		cardName += to_string(cardNum % 13 + 1);	// ������ ���ڴ� to_string���� ��ȯ �� �����Ѵ�.
	}
	
	return cardName;
}

/// <summary>
/// �÷��̾ ��� �ִ� ī�带 ����Ѵ�.
/// </summary>
/// <param name="playerArr">�÷��̾ ��� �ִ� ī�� �迭</param>
/// <param name="handCard">�÷��̾ �� ī���� ��</param>
/// <param name="playerNum">� �÷��̾����� Ȯ���ϴ� ����</param>
void printPlayerCard(int* playerArr, int handCard, int num)
{
	cout << "Player " << num + 1 << " : ";
	// ����� ���ڰ� �ϱ� ���� ������ ī�带 �����ϰ� ���
	for (int count = 0; count < handCard - 1; count++)
	{
		cout << printCard(playerArr[count]) << ", ";
	}
	cout << printCard(playerArr[handCard - 1]) << endl;
}

int main()
{
	srand(time(NULL));	// �Ź� �ٸ� ���� ����ϱ� ���� seed�� �߰�

	int playerNum;
	cout << "ī�带 ������ �÷��̾� �� : ";
	cin >> playerNum;

	int handCard;
	cout << "������ ī�� �� : ";
	cin >> handCard;

	// �÷��̾ � ī�带 ����ִ��� ������ ���� �迭 ����
	// int player[playerNum][playerHandInCard]{};

	// �÷��̾ � ī�带 ����ִ��� ������ ���� �迭 ����
	int** player = new int* [playerNum];
	for (int i = 0; i < playerNum; i++)
	{
		player[i] = new int[handCard];
	}

	// ī�� ������ � ī�尡 �������� �����ϴ� �迭
	bool cardDisappeared[cardDeckNum] = { false };

	for (int i = 0; i < playerNum; i++)
	{
		handOutCard(cardDisappeared, player[i], handCard);
	}

	for (int i = 0; i < playerNum; i++)
	{
		printPlayerCard(player[i], handCard, i);
	}

	// �Ҵ� ����
	for (int i = 0; i < playerNum; i++)
	{
		delete[] player[i];
	}

	return 0;
}