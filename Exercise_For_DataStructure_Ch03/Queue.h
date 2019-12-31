#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <memory.h>
#include <Windows.h>

template <class T>
class Queue {
public:
	Queue();
	Queue(int queueCapacity);
	bool IsEmpty() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T& obj);
	void Pop();
private:
	void setQueue();
	T* queue;
	int front;
	int rear;
	int capacity;
};
/////////////////////////////////
//implements//
template <class T>
Queue<T>::Queue() {
	capacity = 10;
	front = rear = 0;
	setQueue();
}

template <class T>
Queue<T>::Queue(int queueCapacity) {
	capacity = queueCapacity;
	front = rear = 0;
	setQueue();
}

template <class T>
void Queue<T>::setQueue() {
	T* temp;
	if ((front == 0) && (rear == 0)) {
		queue = new T[capacity];
	}
	else if ((capacity / 2) == (rear + 1)) {//���� ���� �� �뷮�� 2��� �ϰ� ����
		temp = queue;
		queue = new T[capacity];
		memcpy(queue, temp + front, sizeof(T)*(rear - front));
		rear = rear - front;
		front = 0;
		delete(temp);
	}
	else {
	}
}

template <class T>
inline bool Queue<T>::IsEmpty() const {
	return front == rear;
}

template <class T>
T& Queue<T>::Front() const {
	if (IsEmpty()) throw "Queue is empty. No front element";
	return queue[(front + 1) % capacity];
}

template <class T>
T& Queue<T>::Rear() const {
	if (IsEmpty()) throw "Queue is empty. No rear element";
	return queue[rear-1];//rear�� �� �ڸ� �̹Ƿ� �� �ڸ��� empty!
}

template <class T>
void Queue<T>::Push(const T& obj) {
	if (rear + 1 == capacity) {//�� ����� rear�� capacity�� �����ϸ� �ø��� �����ϴ� ����� ä��
		capacity *= 2;
		setQueue();
	}
	queue[rear++] = obj;//�̰� �� �س��� ��? �� ť�� �ȵ��� ������;;;;
}

template <class T>
void Queue<T>::Pop() {
	if (IsEmpty()) throw "Queue is empty. Can't delete.";
	front = (front + 1) % capacity;
	queue[front].~T();
}

#endif