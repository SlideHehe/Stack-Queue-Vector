#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstring>

using std::cout;
using std::cerr;
using std::endl;
using std::swap;

template<typename T5>
class Queue {
private:
    int cnt;
    T5 *queue;

    bool empty() {
        return (cnt == 0);
    }

    void shift_left() {
        for (int i = 1; i < cnt; ++i)
            queue[i - 1] = queue[i];

        resize(cnt - 1);
    }

    void resize(int m) {
        T5 *queue_buf = new T5[m];
        if (cnt <= m) memcpy(queue_buf, queue, cnt * sizeof(T5));
        else {
            memcpy(queue_buf, queue, m * sizeof(T5));
            cnt = m;
        }
        cnt = m;
        delete[] queue;
        queue = queue_buf;
    }

public:
    explicit Queue() {
        cnt = 0;
    }

    Queue(Queue &a) {
        cnt = a->cnt;
        for (int i = 0; i < cnt; i++)
            queue[i] = a->queue[i];
    }

    void print() {
        for (int i = 0; i < cnt; i++)
            cout << queue[i] << " ";
        cout << endl;
    }

    void push(const T5 a) {
        resize(cnt + 1);
        queue[cnt - 1] = a;
    }

    T5 pop() {
        T5 buf;
        if (!empty()) {
            buf = queue[0];
            shift_left();
            return buf;
        } else cerr << "Error. Queue is empty." << endl;
        return 0;
    }

    T5 peek() {
        if (!empty()) return queue[cnt - 1];
        else
            cerr << "Error. Queue is empty" << endl;
        return 0;
    }

    int count() {
        return cnt;
    }

    void Swap(Queue &a) {
        if (cnt == a.cnt)
            for (int i = 0; i < cnt; ++i)
                swap(queue[i], a.queue[i]);
        else cerr << "Error. Number of elements must be equal." << endl;
    }

    bool isMount() {
        if (cnt >= 3) {
            T5 max = queue[0];
            int imax = 0;

            for (int i = 1; i < cnt - 1; i++) {
                if (max == queue[i]) return false;
                if (max < queue[i]) {
                    max = queue[i];
                    imax = i;
                }
            }

            for (int i = 0; i < imax; i++) {
                if (queue[i] >= queue[i + 1]) return false;
            }

            for (int i = imax; i < cnt - 1; i++) {
                if (queue[i] <= queue[i + 1]) return false;
            }
            return true;
        } else return false;
    }

    Queue &operator=(const Queue &a) {
        cnt = a.cnt;
        for (int i = 0; i < cnt; i++)
            queue[i] = a.queue[i];
        return *this;
    }

    bool operator<(const Queue &a) {
        return (cnt < a.cnt);
    }

    bool operator>(const Queue &a) {
        return (cnt > a.cnt);
    }

    bool operator<=(const Queue &a) {
        return (cnt <= a.cnt);
    }

    bool operator>=(const Queue &a) {
        return (cnt >= a.cnt);
    }

    bool operator==(const Queue &a) {
        return (cnt == a.cnt);
    }

    bool operator!=(const Queue &a) {
        return (cnt != a.cnt);
    }

    ~Queue() {
        delete[] queue;
    }
};

#endif //QUEUE_H
