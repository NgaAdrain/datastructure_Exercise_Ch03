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
	bool IsEmpty() const;		//C++�� true|false�� boolean �ڷ����� �����Ѵ�
	T& Top() const;				//������ ���� ���� ������Ʈ�� ��ȯ
	void Push(const T& item);	//������ ���� ���� ������Ʈ�� ����
	void Pop();	
	//friend std::ostream& operator<<(std::ostream &stream, Stack<T> &s);//������ ���� ���� ������Ʈ�� ����
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
	else if ((capacity / 2) == (top + 1)) {//���� ���� �� �뷮�� 2��� �ϰ� ����
		temp = stack;
		stack = new T[capacity];
		memcpy(stack, temp, sizeof(T)*(capacity / 2));
		delete(temp);
	}
	else {
	}
}

template <class T> //1~3�� ¥�� �Լ��� inline���� �ϴ� ���� ������� ������ �ȴ�.
inline bool Stack<T>::IsEmpty() const {
	return top == -1;
}

template <class T>
T& Stack<T>::Top() const {
	if (IsEmpty()) throw "Stack is Empty"; //try catch�� ���� �� �ִ�!!
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
	stack[top--].~T();//~�� �������ִ� �ı���!
}
/*
template <class T>
ostream& operator<<(ostream &stream, Stack<T> &s) {
	if (s.IsEmpty()) throw "Stack is Empty.";
	for(int i = 0; i < s.Top(); i++){
		stream << i << "��° : " << s.stack[i] << endl;
	}
	stream << s.Top() << endl;
	return stream;
}*/

#endif