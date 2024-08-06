#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <stdexcept>

template <typename T>
class Array {
	private:
		T *array;
		std::size_t arraySize;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array&);
		Array &operator=(const Array&);
		T &operator[](std::size_t);
		const T &operator[](std::size_t) const;
		std::size_t size() const;
};

template <typename T>
Array<T>::Array() {
	this->array = new T[0]();
	this->arraySize = 0;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->array;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->array = new T[n]();
	this->arraySize = n;
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
	this->arraySize = other.size();
	this->array = new T[this->arraySize];
		
	for (size_t i=0; i<this->arraySize; i++)
		this->array[i] = other.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other) {
		delete[] this->array;
		this->arraySize = other.size();
		this->array = new T[this->arraySize];
		
		for (size_t i=0; i<this->arraySize; i++)
			this->array[i] = other.array[i];
	}
	return *this;
}

template <typename T>
std::size_t Array<T>::size() const
{
	return this->arraySize;
}

template <typename T>
T &Array<T>::operator[](std::size_t idx)
{
	if (idx >= this->size()) throw std::out_of_range("the idx is out of range");
	return this->array[idx];
}

template <typename T>
const T &Array<T>::operator[](std::size_t idx) const
{
	if (idx >= this->size()) throw std::out_of_range("the idx is out of range");
	return this->array[idx];
}

#endif