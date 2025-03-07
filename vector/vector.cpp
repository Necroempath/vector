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

    void ResizeArray(float factor)
    {

    }

public:
    
    SuperVector() : _data(nullptr), _size(0), _capacity(0) { std::cout << "default constructor" << std::endl; }

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
        if (index <= _size && index >= 0) //mistake
        {
            return _data[index];
        }
        return 0;
    }

    size_t Size() const
    {
        return _size;
    }

    bool Set(int index, int value) const
    {
        if (index >= 0 && index < _size) {
            _data[index] = value;
            return true;
        }

        return false;
    }



    void PushBack(int value)
    {
        if (_size == _capacity) ResizeArray(1.5f);

        _data[_size] = value;
    }

    bool Insert(int index, int value)
    {
        if (index < 0 || index >= _size) return false;

        if (_size == _capacity) ResizeArray(1.5f);

        int temp = _data[index];
        _data[index] = value;

        for (int i = index + 1; i < _size + 1; i++)
        {
            int _temp = _data[i];
            _data[i] = temp;
            temp = _temp;
        }

        _size++;
        return true;
    }

    void Pop()
    { 
        _data[--_size] = 0; 

        if (_size <= _capacity * 0.7f) ResizeArray(0.7f);
    }

    bool Remove(int index)
    {
        if (index < 0 || index >= _size) return false;

        int temp = _data[_size - 2];

        for (int i = _size - 1; i > index; i--)
        {
            int temp = _data[i - 1];
            _data[_size - 1] = _data[i - 1];
            _data[i - 1] = temp;
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
    SuperVector vector(5);
    //vector.Set(4, 6);
    //vector.Insert(7, 12);
    //vector.Insert(10, 80);
    //vector.Pop();
    vector.Set(0, 1);
    vector.Set(1, 2);
    vector.Set(2, 3);
    vector.Set(3, 4);
    vector.Set(4, 5);
    vector.Remove(1);
    DisplayVector(vector);
    return 0;
}