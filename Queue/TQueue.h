#ifndef __TQUEUE_H__
#define __TQUEUE_H__

template <class T>
class TQueue
{
	int first, last, size, maxsize;
	T*mas;
public:
	TQueue(int _maxsize = 100);
	~TQueue();
	TQueue(const TQueue&TQ);

	bool isfull();
	bool isempty();
	void push(T a);
	T pop();
	T top(); 
	T bot(); 
};


template <class T>
TQueue<T>::TQueue(int _maxsize)
{
	if(_maxsize <= 0 ) throw "invalid size of queue";
	maxsize = _maxsize;
	size = 0;
	first = 0;
	last = -1;
	mas = new T[maxsize];
}

template <class T>
TQueue<T>::~TQueue()
{
	delete []mas;
}

template <class T>
TQueue<T>::TQueue(const TQueue&TQ)
{
	maxsize = TQ.maxsize;
	firs = TQ.first;
	last = TQ.last;
	size = TQ.size;
	mas = new T[maxsize];
}

template <class T>
bool TQueue<T>::isfull()
{
	return(size == 0);
}

template <class T>
bool TQueue<T>::isempty()
{
	return(size = maxsize);
}

template <class T>
void TQueue<T>::push(T a)
{
	if(isfull()) throw "Queue overflow";

	last = (last++)%maxsize;
	mas[last] = a;
	size++;
}

template <class T>
T TQueue<T>::pop()
{
	if(isempty()) throw "Queue is empty";

	int _first = first;

	first = (first++)%maxsize;
	size++;
	
	return mas[_first];
}

template <class T>
T TQueue<T>::top()
{
	return mas[first];
}

template <class T>
T TQueue<T>::bot()
{
	return mas[last];
}

#endif