#ifndef VECTOR_HPP
#define VECTOR_HPP

template <class T>
class Vector 
{
    T* elements;
    int size;
    int capacity;

    void erase() 
    {
        delete[] elements;
    }

    void copy(const Vector& other) 
    {
        capacity = other.capacity;
        size = other.size;
        elements = new T[capacity];
        for(int i = 0; i < size; i++)
        {
            elements[i] = other.elements[i];
        }
    }

    void resize() 
    {
        capacity *= 2;
        T* new_els = new T[capacity];
        for(int i = 0; i < size; i++)
        {
            new_els[i] = elements[i]; 
        }
        erase();
        elements = new_els;
    }
public:
    Vector()
    {
        capacity = 16;
        size = 0;
        elements = new T[capacity];
    }

    Vector(int size) {
        this->size = size;
        capacity = size;
        elements = new T[capacity];
    }

    Vector(const Vector& other)
    {
        copy(other);
    }

    ~Vector()
    {
        erase(); 
    }

    Vector& operator=(const Vector& other)
    {
        if(this != &other)
        {
            erase();
            copy(other);
        }
        return *this;
    }

    T& operator[](int index)
    {
        return elements[index]; 
    }

    void push_back(T element) 
    {
        if(size >= capacity)
        {
            resize();
        }
        elements[size++] = element;
    }

    void push_front(T element)
    {
        Vector temp;
        temp.push_back(element);
        for(int i = 0; i < size; i++)
        {
            temp.push_back(elements[i]);
        }
        *this = temp;
    }

    void pop_back()
    {
        Vector temp;
        if(size > 0)
        {
            size--; 
            for(int i = 0; i < size; i++)
            {
                temp.push_back(elements[i]);
            }
            *this = temp; 
        }
    }

    void pop_front()
    {
        Vector temp;
        if(size > 0)
        {
            for(int i = 1; i < size; i++)
            {
                temp.push_back(elements[i]);
            }
            size--; 
            *this = temp; 
        }
    }

    void set(int index, T element)
    {
        if(index < 0 || index > size)
            return;
        elements[index] = element;
    }

    void insert(int index, T element)
    {
        if(index < 0 || index > size)
            return;
        if(size >= capacity)
            resize();
        for(int i = size; i > index; i--)
            elements[i] = elements[i-1];
        elements[index] = element;
        size++;
    }

    void remove(int index)
    {
        if(index < 0 || index > size)
            return;
        size--;
        for(int i = index; i < size; i++)
        {
            elements[i] = elements[i+1];
        }
    }

    int get_size() const
    {
        return size;
    }

    bool empty()
    {
        return size == 0;
    }
};

#endif