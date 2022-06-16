// ������ �ڵ�
#include <iostream>

using namespace std;

#define NOT_VISITED 0
	
class SnailArray
{
public:
	SnailArray() = default;
	~SnailArray()
	{
		clear();
	}

	SnailArray(const SnailArray& other) = delete;
	SnailArray& operator=(const SnailArray& other) = delete;

	void make(int size)
	{
		_size = size;

		// 1. �迭 �����
		_arr = new int[_size * _size];
		memset(_arr, 0, sizeof(int) * _size * _size);
		// 2. ������ �迭 ����
		// 2-1. ������ ������ �ʱ�ȭ
		int r = 0;
		int c = 0;
		int footstep = 1;
		enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
		Direction direction = DIR_RIGHT;
		for (int i = 0; i < _size * _size; ++i)
		{
			// 2-2. ���ڱ��� �����.
			_arr[r * _size + c] = footstep;
			++footstep;

			// 2-3. �̵��� ��ġ�� ����Ѵ�.
			static const int dr[] = { 0, 1, 0, -1 };
			static const int dc[] = { 1, 0, -1, 0 };

			int nr = r + dr[(int)direction];
			int nc = c + dc[(int)direction];

			// 2-4. �̵��� �������� �Ǻ��Ѵ�.
			// 2-4-1. ���� ����� �� => r, c�� ��ġ�� [0, size)
			// 2-4-2. �̹� ������ ���� �� => arr[nr][nc] != 0
			if (nr < 0 || nr >= _size || nc < 0 || nc >= _size || _arr[nr * _size + nc] != NOT_VISITED)
			{
				// 2-5. �̵��� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
				direction = (Direction)((direction + 1) % DIR_MAX);

				// 2-6. ��ġ���� �ٽ� ����Ѵ�.
				nr = r + dr[(int)direction];
				nc = c + dc[(int)direction];
			}

			// 2-7. �̵��Ѵ�.
			r = nr;
			c = nc;
		}
	}

	void print()
	{
		// 3. ���
		for (int r = 0; r < _size; ++r)
		{
			for (int c = 0; c < _size; ++c)
			{
				cout << _arr[r * _size + c] << "\t";
			}
			cout << "\n";
		}
	}

	void clear()
	{
		delete[] _arr;
	}

private:
	int* _arr = nullptr;
	int _size = 0;
};

int main()
{
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	int size;
	cin >> size;

	SnailArray sa;
	sa.make(size);
	sa.print();
}