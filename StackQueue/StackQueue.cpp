#include <iostream>
#include <stack>
#include <queue>

int main()
{
	std::cout << "---------- Stack ----------" << std::endl;
	std::stack<int> st;

	st.push(10); // push element into the stack
	int a = st.top(); // equivalent to peek
	std::cout << a << std::endl;
	bool flag = st.empty(); // isEmpty => 1 if empty, 0 if not
	std::cout << flag << std::endl;
	st.pop();  // remove the top element	


	std::cout << "\n---------- Queue ----------" << std::endl;
	std::queue<int> queue;
	queue.push(5); // push element into to the queue
	queue.push(10);
	queue.push(15);
	int front = queue.front(); // gives the first out element
	std::cout << front << std::endl;
	front = queue.back(); // gives the last in element 
	std::cout << front << std::endl;

	queue.pop(); // removes the first out element

}
