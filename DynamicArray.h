#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// ============================================================================
// GENERIC DYNAMIC ARRAY TEMPLATE
// Strict Pointer Arithmetic: Zero [] Subscript Operators
// ============================================================================
template <typename T>
class DynamicArray {
private:
    T*  data;
    int capacity;
    int size;

    void resize() {
        int newCap = (capacity < 4) ? 4 : capacity * 2;
        T*  newData = new T[newCap];

        T* src = data;
        T* dst = newData;
        T* end = data + size;
        while (src != end) {
            *dst = *src;
            ++src;
            ++dst;
        }

        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:
    DynamicArray() : data(nullptr), capacity(0), size(0) {}

    explicit DynamicArray(int initialCapacity) : data(nullptr), capacity(0), size(0) {
        if (initialCapacity > 0) {
            data = new T[initialCapacity];
            capacity = initialCapacity;
        }
    }

    // Rule of Three: Deep Copy Constructor
    DynamicArray(const DynamicArray<T>& other) : data(nullptr), capacity(0), size(0) {
        if (other.size > 0) {
            data = new T[other.capacity];
            capacity = other.capacity;
            size = other.size;

            T* src = other.data;
            T* dst = data;
            T* end = other.data + other.size;
            while (src != end) {
                *dst = *src;
                ++src;
                ++dst;
            }
        }
    }

    // Rule of Three: Deep Assignment Operator
    DynamicArray<T>& operator=(const DynamicArray<T>& other) {
        if (this != &other) {
            delete[] data;
            data = nullptr;
            capacity = 0;
            size = 0;

            if (other.size > 0) {
                data = new T[other.capacity];
                capacity = other.capacity;
                size = other.size;

                T* src = other.data;
                T* dst = data;
                T* end = other.data + other.size;
                while (src != end) {
                    *dst = *src;
                    ++src;
                    ++dst;
                }
            }
        }
        return *this;
    }

    // Rule of Three: Destructor
    ~DynamicArray() {
        delete[] data;
        data = nullptr;
        capacity = 0;
        size = 0;
    }

    void add(const T& item) {
        if (size >= capacity) {
            resize();
        }
        *(data + size) = item;
        ++size;
    }

    T& get(int index) const {
        return *(data + index);
    }

    T* getPtr(int index) const {
        return (data + index);
    }

    void set(int index, const T& item) {
        *(data + index) = item;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) return;
        T* current = data + index;
        T* nextElem = current + 1;
        T* endPtr = data + size;
        while (nextElem != endPtr) {
            *current = *nextElem;
            ++current;
            ++nextElem;
        }
        --size;
    }

    int  getSize()     const { return size; }
    int  getCapacity() const { return capacity; }
    bool isEmpty()     const { return size == 0; }
    void clear()             { size = 0; }

    T* begin() const { return data; }
    T* end()   const { return data + size; }
};

#endif // DYNAMIC_ARRAY_H
