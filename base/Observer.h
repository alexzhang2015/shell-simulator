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
 * Observer ģʽ������Ļ��࣬����bridgeģʽ������
 * ʵ���۲���ģʽ�࣬ͨ����ϵķ�ʽ���в�����
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