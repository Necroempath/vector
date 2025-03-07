//Set() - заменяет элемент в массиве по индексу
//PushBack() - добавляет в конец элемент
//Insert() - добавляет элемент в указанный индекс
//Pop() - удаляет последний элемент
//Remove() - удаляет элемент по индексу

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class SuperVector
{
private:
	int* _data;
	size_t _size;
	size_t _capacity;

	void ResizeArray(const float factor)
	{
		int* temp = new int[_capacity * factor]();

		for (int i = 0; i < _size; i++)
		{
			temp[i] = _data[i];
		}

		_capacity *= factor; //comment this and catch sweet bug)
		delete[] _data;
		_data = temp;
	}

public:

	SuperVector() : _data(nullptr), _size(0), _capacity(0) {}

	SuperVector(size_t size) : _size(size), _capacity(size * 1.5f)
	{
		_data = new int[_capacity]();
	}

	SuperVector(const SuperVector& other) : _size(other._size), _capacity(other._capacity)
	{
		_data = new int[_capacity];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = other._data[i];
		}
	}

	int Get(size_t index) const
	{
		if (index < _size && index >= 0)
		{
			return _data[index];
		}
		return 0;
	}

	size_t Size() const
	{
		return _size;
	}

	bool Set(int index, int value)
	{
		if (index >= 0 && index < _size) {
			_data[index] = value;
			return 1;
		}

		return 0;
	}

	void PushBack(int value)
	{
		if (_size == _capacity) ResizeArray(1.5f);

		_data[_size++] = value;
	}

	bool Insert(int index, int value)
	{
		if (index < 0 || index > _size) return 0;

		if (_size == _capacity) ResizeArray(1.5f);

		for (int i = _size; i > index; i--)
		{
			_data[i] = _data[i - 1];
			
		}

		_data[index] = value;

		_size++;
		return 1;
	}

	void Pop()
	{
		_data[--_size] = 0;

		if (_size <= _capacity * 0.7f) ResizeArray(0.7f);
	}

	bool Remove(int index)
	{
		if (index < 0 || index >= _size) return 0;

		for (int i = index; i < _size - 1; i++)
		{
			_data[i] = _data[i + 1];
		}

		Pop();
		return true;
	}

	~SuperVector()
	{
		delete[] _data;
	}

};

void DisplayVector(const SuperVector& vector)
{
	for (int i = 0; i < vector.Size(); ++i)
	{
		std::cout << vector.Get(i) << " ";
	}
}


int main()
{
	SuperVector vector(6);

	vector.Set(0, 1);
	vector.Set(1, 2);
	vector.Set(2, 3);
	vector.Set(3, 4);
	vector.Set(4, 5);
	vector.Set(5, 6);
	vector.Insert(3, 10);
	vector.Pop();
	vector.PushBack(10);
	vector.Remove(1);
	DisplayVector(vector);

	return 0;
}