/*
 * Shell Simulator
 * 2010.08.19 by alex
 */

#ifndef BASE_SINGLETON_H_
#define BASE_SINGLETON_H_
#pragma once 

/**
 * Singleton design pattern; only one instance is allowed.
 */
template <class T> 
class Singleton
{
    public:

    /**
     * Create an instance of T.
     * @return Pointer to T.
     */
    static T * instance()
    {
		if (!Singleton<T>::obj)
		{
			Singleton<T>::obj = new T();
		}
		return Singleton<T>::obj;
	}
	
    private:

	/** One and only instance. */    
	static T *obj;
};

/* Initialize the static member obj. */
template <class T> T* Singleton<T>::obj = 0;

#endif /* BASE_SINGLETON_H_ */