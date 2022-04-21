#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H

#include <iostream>
#include <cstring>

using std::cout;
using std::cerr;
using std::endl;
using std::swap;

template<typename T0>
class Vector {
private:
    unsigned long n, cnt = 0;
    T0 *head = nullptr;

public:
    Vector(int n) {
        this->n = n;
        head = new T0[n];
        cnt = 0;
    }

    Vector(Vector &a) {
        this->n = a->n;
        this->cnt = a->cnt;
        for (int i = 0; i < cnt; i++)
            this->head[i] = a->head[i];
    }

    void push(const T0 a) {
        if (cnt != n) {
            head[cnt] = a;
            cnt++;
        } else cerr << "Error. Vector is overflowed." << endl;
    }

    void push(const T0 a, int index) {
        if (cnt != n) {
            for (int i = cnt; i > index; i--)
                head[i] = head[i - 1];
            head[index] = a;
            cnt++;
        } else cerr << "Error. Vector is overflowed." << endl;
    }

    T0 pop() {
        T0 buf;
        if (cnt != 0) {
            buf = head[cnt];
            cnt--;
            return buf;
        } else cerr << "Error. Vector is empty." << endl;
        return 0;
    }

    T0 pop(int index) {
        T0 buf;
        if (cnt != 0) {
            buf = head[index];
            for (int i = index; i < cnt - 1; i++)
                head[i] = head[i + 1];
            cnt--;
            return buf;
        } else cerr << "Error. Vector is empty." << endl;
        return 0;
    }

    void print() {
        for (int i = 0; i < cnt; i++)
            cout << head[i] << " ";
        cout << endl;
    }

    T0 peek() {
        if (cnt != 0) return head[cnt - 1];
        else
            cerr << "Error. Vector is empty" << endl;
        return 0;
    }

    int count() {
        return cnt;
    }

    T0 at(int index) {
        if (index + 1 <= cnt) return head[index];
        else cerr << "Error. There is no element with this index" << ":";
        return 0;
    }

    void resize(int m) {
        T0 *head_buf = new T0[m];
        if (cnt <= m) memcpy(head_buf, head, cnt * sizeof(T0));
        else {
            memcpy(head_buf, head, m * sizeof(T0));
            cnt = m;
        }
        n = m;
        delete[] head;
        head = head_buf;
    }

    void Swap(Vector &a) {
        if (this->cnt == a.cnt)
            for (int i = 0; i < cnt; i++)
                swap(this->head[i], a.head[i]);
        else cerr << "Error. Number of elements must be equal." << endl;
    }

    bool isMount() {
        if (cnt >= 3) {
            T0 max = head[0];
            int imax = 0;

            for (int i = 1; i < cnt - 1; i++) {
                if (max == head[i]) return false;
                if (max < head[i]) {
                    max = head[i];
                    imax = i;
                }
            }

            for (int i = 0; i < imax; i++) {
                if (head[i] >= head[i + 1]) return false;
            }

            for (int i = imax; i < cnt - 1; i++) {
                if (head[i] <= head[i + 1]) return false;
            }
            return true;
        } else return false;
    }

    bool operator<(const Vector &a) {
        return (this->cnt < a.cnt);
    }

    bool operator>(const Vector &a) {
        return (this->cnt > a.cnt);
    }

    bool operator<=(const Vector &a) {
        return (this->cnt <= a.cnt);
    }

    bool operator>=(const Vector &a) {
        return (this->cnt >= a.cnt);
    }

    bool operator==(const Vector &a) {
        return (this->cnt == a.cnt);
    }

    bool operator!=(const Vector &a) {
        return (this->cnt != a.cnt);
    }

    ~Vector() {
        delete[] head;
    }
};

#endif //UNTITLED_VECTOR_H
