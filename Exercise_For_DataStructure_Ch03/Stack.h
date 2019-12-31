#pragma once
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <memory.h>
#include <Windows.h>

using namespace std;

template <class T>
class Stack {
public :
	Stack();
	Stack(int stackCapacity);	//default = 10
	bool IsEmpty() const;		//C++은 true|false의 boolean 자료형을 지원한다
	T& Top() const;				//스택의 가장 위의 오브젝트를 반환
	void Push(const T& item);	//스택의 가장 위에 오브젝트를 저장
	void Pop();	
	//friend std::ostream& operator<<(std::ostream &stream, Stack<T> &s);//스택의 가장 위의 오브젝트를 제거
private :
	void setStack();
	T* stack;
	int top;
	int capacity;
};
//======================//
//implements//
template <class T>
Stack<T>::Stack() {
	capacity = 10;
	top = -1;
	setStack();
}

template <class T>
Stack<T>::Stack(int stackCapacity) {
	capacity = stackCapacity;
	top = -1;
	setStack();
}

template <class T>
void Stack<T>::setStack() {
	T* temp;
	if (top == -1) {
		stack = new T[capacity];
	}
	else if ((capacity / 2) == (top + 1)) {//스택 부족 시 용량을 2배로 하고 복사
		temp = stack;
		stack = new T[capacity];
		memcpy(stack, temp, sizeof(T)*(capacity / 2));
		delete(temp);
	}
	else {
	}
}

template <class T> //1~3줄 짜리 함수는 inline으로 하는 것이 성능향상에 도움이 된다.
inline bool Stack<T>::IsEmpty() const {
	return top == -1;
}

template <class T>
T& Stack<T>::Top() const {
	if (IsEmpty()) throw "Stack is Empty"; //try catch로 잡을 수 있다!!
	return stack[top];
}

template <class T>
void Stack<T>::Push(const T& obj) {
	if (top == capacity - 1) {
		capacity *= 2;
		setStack();
	}
	stack[++top] = obj;
}

template <class T>
void Stack<T>::Pop() {
	if (IsEmpty()) throw "Stack is Empty. Can't Delete.";
	stack[top--].~T();//~는 정해져있는 파괴자!
}
/*
template <class T>
ostream& operator<<(ostream &stream, Stack<T> &s) {
	if (s.IsEmpty()) throw "Stack is Empty.";
	for(int i = 0; i < s.Top(); i++){
		stream << i << "번째 : " << s.stack[i] << endl;
	}
	stream << s.Top() << endl;
	return stream;
}*/

#endif