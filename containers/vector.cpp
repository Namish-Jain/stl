#include <iostream>

template <typename T>
class Vector {
private:
    T* array;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity) {
        T* new_array = new T[new_capacity];
        for (size_t i = 0; i < size; i++) {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        capacity = new_capacity;
    }

public:
    Vector() : array(nullptr), size(0), capacity(0) {}

    void push_back(const T& value) {
        if (size == capacity) {
            if (capacity == 0) resize(1);
            else resize(capacity * 2);
        }

        array[size++] = value;
    }

    void pop_back() {
        if (size == 0) throw std::out_of_range("Vector is empty");
        size--;
    }

    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

    bool empty() const{
        return (size == 0);
    }

    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return array[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return array[index];
    }

    void insert(size_t index, const T& value) {
        if (index > size) throw std::out_of_range("Index out of range");

        if (size == capacity) {
            if (capacity == 0) resize(1);
            else resize(capacity * 2);
        }

        for (size_t i = size; i > index; --i) {
            array[i] = array[i - 1];
        }

        array[index] = value;
        size++;
    }

    void clear() {
        delete[] array;
        array = nullptr;
        size = 0;
        capacity = 0;
    }
};