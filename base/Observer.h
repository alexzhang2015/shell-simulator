/*
 * Shell Simulator
 * 2010.08.18 by alex
 */

#ifndef BASE_OBSERVER_H_
#define BASE_OBSERVER_H_
#pragma once 

#include <list>
using namespace std;

/**
 * Observer 模式，抽象的基类，符合bridge模式，生成
 * 实例观察者模式类，通过组合的方式进行操作。
 */
template <class T>
class Observer {
public:
	Observer()
	{
	}

	~Observer()
	{
	}
	
	/**
	 * Accept the class attach.
	 * @param t  T type class
	 */
	void attach(T *t)
	{
		list_t.push_back(t);
	}

	/**
	 * Accept the class detach.
	 * @param t  T type class
	 */
	void detach(T *t)
	{
		if (list_t.size() >= 0)
		{
			list_t.remove(t);
		}
	}

	/**
	 * Sent notify to all T type objects.
	 */
	virtual void notify() = 0;

protected:

	/* List T type data */
	list<T *> list_t;

};

#endif /* BASE_OBSERVER_H_ */