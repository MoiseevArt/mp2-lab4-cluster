#include <stack>

using namespace std;


template<typename T>
class TStackQueue {

public:
	TStackQueue() : sz(0) {};

	/* ��������� ������ �������. */
	size_t size() const { return sz; }

	/* ��������� true, ���� ������� ����� � false, ���� ���. */
	bool isEmpty() const { return sz == 0; }

	/* ��������� ������ ������� �������. */
	T top() {
		if (rightStack.empty()) {
			while (!leftStack.empty()) {
				rightStack.push(leftStack.top());
				leftStack.pop();
			}
		}
		return rightStack.top();
	}

	/* ���������� �������� � �������. */
	void push(const T& val) { leftStack.push(val); sz++; }

	/* ������� � ��������� ������ ������� �������. */
	T pop() {

		if (rightStack.empty())
		{
			while (!leftStack.empty()) { rightStack.push(leftStack.top()); leftStack.pop(); }
		}
		T val = rightStack.top();
		rightStack.pop();
		sz--;
		return val;
	}

private:
	size_t sz;
	stack<T> leftStack;
	stack<T> rightStack;
};