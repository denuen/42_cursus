#include "Array.hpp"

template <typename T>
Array<T>::Array() :
n(0) {

	buffer = nullptr;

}

template <typename T>
Array<T>::Array(const unsigned int n) :
n(n) {

	if (n > 0) {
		buffer = new T[n]();
	} else {
		buffer = nullptr;
	}

}

template <typename T>
Array<T>::Array(const Array<T>& a) :
n(a.n) {

	if (n > 0) {
		buffer = new T[n];
		for (unsigned int i = 0; i < n; i++) {
			buffer[i] = a.buffer[i];
		}
	} else {
		buffer = nullptr;
	}

}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& a) {

	if (this != &a) {

		if (buffer) {
			delete[] buffer;
		}

		n = a.n;

		if (n > 0) {
			buffer = new T[a.n];
			for (unsigned int i = 0; i < n; i++) {
				buffer[i] = a.buffer[i];
			}
		} else {
			buffer = nullptr;
		}

	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) {

	if (index >= n) {
		throw OutOfBounds();
	} else {
		return (buffer[index]);
	}

}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const {

	if (index >= n) {
		throw OutOfBounds();
	} else {
		return (buffer[index]);
	}

}

template <typename T>
const char*	Array<T>::OutOfBounds::what() const throw() {
	return ("Invalid index");
}

template <typename T>
Array<T>::~Array() {

	if (buffer) {
		delete[] buffer;
	}

}
