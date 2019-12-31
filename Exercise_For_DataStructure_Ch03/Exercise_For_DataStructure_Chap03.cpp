// Exercise_For_DataStructure_Chap03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 주의!!!!! template를 사용할 때!!!!!
// template를 사용했을 때는 header file에 선언 및 구현 다 해야 한다!!!!! 중요
#include "Stack.h" //pre-compiled header
#include "Queue.h"
#include <iostream>

int main()
{
	std::cout << "Hello World!\n";
	Stack<int> test;
	Queue<int> test2;
	test = Stack<int>(12);
	test2 = Queue<int>(8);
	for (int i = 0; i < 20; i++) {
		test.Push(20 + i);
		test2.Push(10 + i);
		std::cout << test.Top() << std::endl;
		std::cout << test2.Front() << " " << test2.Rear() << std::endl;
	}
	test.Pop();
	std::cout << test.Top() << std::endl;
	test2.Pop();
	std::cout << test2.Front() << std::endl;
	//std::cout << test;
	return 0;
}

//구현해야 하는 것 : Stack(완료), Queue


