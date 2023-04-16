// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
    T* arr;
    int first, last, count;

public:
    TPQueue() : first(0), last(0), count(0) {
        arr = new T[size];
    }
    ~TPQueue() {
        delete[] arr;
    }
    bool isEmpty() const {
        return 0 == count;
    }
    bool isFull() const {
        return count == size;
    }
    void push(const T& value) {
        if (isFull()) {
            throw std::string("Full!");
        } else {
            int index = first;
            while (index != last && arr[index].prior >= value.prior)
                index = ++index % size;
            for (int i = last; i != index; i = (--i + size) % size)
                arr[i] = arr[((i - 1) + size) % size];
            arr[index] = value;
            last = ++last % size;
            ++count;
        }
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("Empty!");
        } else {
            --count;
            return arr[first++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
