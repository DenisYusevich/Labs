#pragma once



using namespace std;

template<class T>
class Vector {

private:

	unsigned int size;
	unsigned int capacity;
	T* buffer;

public:

	Vector();
	Vector(unsigned int vSize);
	Vector(const Vector<T> &value);
	Vector(unsigned int size, const T* initial);
	//~myVector();
	void push_back(const T &value);
	T pop_back();
	void reserve(unsigned int capacity);
	T& print_back();
	void show();
	Vector<T>  operator+(const Vector &value);
	Vector<T>  operator-(const Vector &value);
	Vector<T>  operator/(int value);
	Vector<T>  operator*(int value);
	bool isEmpty();
	T& operator[](int index);
	Vector<T> & operator=(const Vector &value);
	int vec_size();
	//void clear();
	

};

template<class T>
Vector<T>::Vector() {

	size = 0;
	capacity = 0;
	buffer = 0;

}


template<class T>
Vector<T>::Vector(unsigned int vSize) {

	size = vSize;
	capacity = vSize;
	buffer = new T[size];

}

template<class T>
Vector<T>::Vector(const Vector<T> &value)
{

	size = value.size;
	capacity = value.capacity;

	T* buffer = new T[size];
	for (int i = 0; i < size; ++i) {
		buffer[i] = value.buffer[i];
	}
}

template<class T>
Vector<T>::Vector(unsigned int size, const T* initial)
{
	this->size = size;
	capacity = size;
	buffer = new T[size];
	for (unsigned int i = 0; i < size; i++)
		buffer[i] = initial[i];

}


template<class T>
void Vector<T>::push_back(const T &value) {
	if (size >= capacity) {
		reserve(capacity + 5);
	}

	buffer[size++] = value;

}


template<class T>
T Vector<T>::pop_back() {

	T val;
	val = buffer[size - 1];
	size--;
	return val;

}

template<class T>
void Vector<T>::reserve(unsigned int capacity)
{
	if (buffer == 0)
	{
		size = 0;
		this->capacity = 0;
	}
	T * Newbuffer = new T[capacity];

	unsigned int l_Size = capacity < size ? capacity : size;


	for (unsigned int i = 0; i < l_Size; i++)
		Newbuffer[i] = buffer[i];

	this->capacity = capacity;
	delete[] buffer;
	buffer = Newbuffer;
}

template<class T>
T& Vector<T>::operator[](int index) {

	return buffer[index];

}

template<class T>
Vector<T> & Vector<T>::operator = (const Vector<T> & v)
{
	delete[] buffer;
	size = v.size;
	capacity = v.capacity;
	buffer = new T[size];
	for (unsigned int i = 0; i < size; i++)
		buffer[i] = v.buffer[i];
	return *this;
}



template<class T>
T& Vector<T>::print_back()
{
	return buffer[size - 1];
}

template<class T>
bool Vector<T>:: isEmpty() {

	if (size == 0) {
		return true;
	}
	else {
		return false;
	}

}



template<class T>
Vector<T>  Vector<T>::operator+(const Vector<T> & v) {

	if (this->size == v.size) {

		T* newBuffer = new T[size];

		for (int i = 0; i < size; ++i) {

			newBuffer[i] = this->buffer[i] + v.buffer[i];
		}

		return Vector<T>(size, newBuffer);

	}
	else {
		cout << "vectors are not equal\n";
	}

}

template<class T>
Vector<T>  Vector<T>::operator-(const Vector<T> & v) {

	if (this->size == v.size) {

		T* newBuffer = new T[size];

		for (int i = 0; i < size; ++i) {

			newBuffer[i] = this->buffer[i] - v.buffer[i];
		}

		return Vector<T>(size, newBuffer);
	}
	else {
		cout << "vectors are not equal\n";
	}
}

template<class T>
Vector<T>  Vector<T>::operator/(int value) {

	for (int i = 0; i < size; ++i) {
		buffer[i] /= value;
	}

	return Vector<T>(size, buffer);



}


template<class T>
Vector<T>  Vector<T>::operator*(int value) {

	for (int i = 0; i < size; ++i) {
		buffer[i] *= value;
	}

	return Vector<T>(size, buffer);

}


template<class T>
void Vector<T>::show() {


	for (int i = 0; i < size; ++i) {
		cout << buffer[i];
	}


}

template<class T>
int Vector<T>::vec_size() {

	return this->size;

}



