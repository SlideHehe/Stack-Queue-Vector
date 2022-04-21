#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstring>

using std::cout;
using std::cerr;
using std::endl;
using std::swap;

template<typename T>
class Stack {
public:
    explicit Stack(int n) {
        this->n = n;
        data = new T[n];
        cnt = 0;
    }

    Stack(Stack &a) {
        n = a->n;
        cnt = a->cnt;
        for (int i = 0; i < cnt; i++)
            data[i] = a->data[i];
    }

    void print() {
        for (int i = 0; i < cnt; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void push(const T a) {
        if (!overflow()) {
            data[cnt] = a;
            cnt++;
        } else cerr << "Error. Stack is overflowed." << endl;
    }

    T pop() {
        if (!empty()) {
            cnt--;
            return data[cnt];
        } else cerr << "Error. Stack is empty." << endl;
        return 0;
    }

    void resize(int m) {
        T *new_data = new T[m];
        if (cnt <= m) memcpy(new_data, data, cnt * sizeof(T));
        else {
            memcpy(new_data, data, m * sizeof(T));
            cnt = m;
        }
        n = m;
        delete[] data;
        data = new_data;
    }

    T peek() {
        if (!empty()) return data[cnt - 1];
        else {
            cerr << "Error. Stack is empty" << endl;
            return 0;
        }
    }

    int count() {
        return cnt;
    }

    void Swap(Stack &a) {
        if (n == a.n) {
            for (int i = 0; i < n; i++) {
                swap(data[i], a.data[i]);
            }
        } else cerr << "Error. Number of elements must be equal." << endl;
    }

    bool isMount() {
        if (cnt >= 3) {
            T max = data[0];
            int imax = 0;

            for (int i = 1; i < cnt - 1; i++) {
                if (max == data[i]) return false;
                if (max < data[i]) {
                    max = data[i];
                    imax = i;
                }
            }

            for (int i = 0; i < imax; i++) {
                if (data[i] >= data[i + 1]) return false;
            }

            for (int i = imax; i < cnt - 1; i++) {
                if (data[i] <= data[i + 1]) return false;
            }
            return true;
        } else return false;
    }

    Stack &operator=(const Stack &a) {
        n = a.n;
        cnt = a.cnt;
        for (int i = 0; i < cnt; i++)
            data[i] = a.data[i];
        return *this;
    }

    bool operator<(const Stack &a) {
        return (n < a.n);
    }

    bool operator>(const Stack &a) {
        return (n > a.n);
    }

    bool operator<=(const Stack &a) {
        return (n <= a.n);
    }

    bool operator>=(const Stack &a) {
        return (n >= a.n);
    }

    bool operator==(const Stack &a) {
        return (n == a.n);
    }

    bool operator!=(const Stack &a) {
        return (n != a.n);
    }

    ~Stack() {
        delete[] data;
    }

private:
    int n{}, cnt{};
    T *data = nullptr;

    bool overflow() {
        return (cnt == n);
    }

    bool empty() {
        return (cnt == 0);
    }
};

#endif //STACK_H
