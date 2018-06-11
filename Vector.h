#ifndef VECTOR_H
#define VECTOR_H

#include<exception>

template<typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector& v);
	~Vector();
	Vector& operator=(const Vector& v);

	T& operator[](const int index) const;

	void Erase(int index);
	void PushBack(const T& element);
	int Size() const { return size; }

private:
	T * container;
	int capacity;
	int size;

	void CopyObject(const Vector& v);
	void FreeMemory();

	void MoveElements(T * target, T * source);
	void Resize();
	void SwapToBack(int index);
};

#endif // !VECTOR_H

template<typename T>
inline Vector<T>::Vector()
{
	size = 0;
	capacity = 1;
	container = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(const Vector & v)
{
	CopyObject(v);
}

template<typename T>
inline Vector<T>::~Vector()
{
	FreeMemory();
}

template<typename T>
inline Vector<T> & Vector<T>::operator=(const Vector<T> & v)
{
	if (this != &v)
	{
		FreeMemory();
		CopyObject(v);
	}

	return *this;
}

template<typename T>
inline T & Vector<T>::operator[](const int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index out of range.");
	}

	return container[index];
}

template<typename T>
inline void Vector<T>::Erase(int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index out of range.");
	}

	SwapToBack(index);
	size--;
}

template<typename T>
inline void Vector<T>::PushBack(const T & element)
{
	if (capacity == size)
	{
		Resize();
	}

	container[size++] = element;
}

template<typename T>
inline void Vector<T>::CopyObject(const Vector<T>& v)
{
	size = v.size;
	capacity = v.capacity;

	container = new T[capacity];
	MoveElements(container, v.container);
}

template<typename T>
inline void Vector<T>::FreeMemory()
{
	delete[] container;
}

template<typename T>
inline void Vector<T>::MoveElements(T * target, T * source)
{
	for (int i = 0; i < size; i++)
	{
		target[i] = source[i];
	}
}

template<typename T>
inline void Vector<T>::Resize()
{
	capacity *= 2;

	T* newContainer = new T[capacity];
	MoveElements(newContainer, container);

	FreeMemory();
	container = newContainer;
}

template<typename T>
inline void Vector<T>::SwapToBack(int index)
{
	for (index; index < size - 1; index++)
	{
		T temp = container[index];
		container[index] = container[index + 1];
		container[index + 1] = temp;
	}
}
