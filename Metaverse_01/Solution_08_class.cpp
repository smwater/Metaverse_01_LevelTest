// 교수님 코드
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

		// 1. 배열 만들기
		_arr = new int[_size * _size];
		memset(_arr, 0, sizeof(int) * _size * _size);
		// 2. 달팽이 배열 세팅
		// 2-1. 달팽이 데이터 초기화
		int r = 0;
		int c = 0;
		int footstep = 1;
		enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
		Direction direction = DIR_RIGHT;
		for (int i = 0; i < _size * _size; ++i)
		{
			// 2-2. 발자국을 남긴다.
			_arr[r * _size + c] = footstep;
			++footstep;

			// 2-3. 이동할 위치를 계산한다.
			static const int dr[] = { 0, 1, 0, -1 };
			static const int dc[] = { 1, 0, -1, 0 };

			int nr = r + dr[(int)direction];
			int nc = c + dc[(int)direction];

			// 2-4. 이동이 가능한지 판별한다.
			// 2-4-1. 벽에 닿았을 때 => r, c의 위치가 [0, size)
			// 2-4-2. 이미 지나온 곳일 때 => arr[nr][nc] != 0
			if (nr < 0 || nr >= _size || nc < 0 || nc >= _size || _arr[nr * _size + nc] != NOT_VISITED)
			{
				// 2-5. 이동이 불가능하므로 방향 전환을 한다.
				direction = (Direction)((direction + 1) % DIR_MAX);

				// 2-6. 위치값을 다시 계산한다.
				nr = r + dr[(int)direction];
				nc = c + dc[(int)direction];
			}

			// 2-7. 이동한다.
			r = nr;
			c = nc;
		}
	}

	void print()
	{
		// 3. 출력
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
	cout << "배열의 크기를 입력하세요 : ";
	int size;
	cin >> size;

	SnailArray sa;
	sa.make(size);
	sa.print();
}