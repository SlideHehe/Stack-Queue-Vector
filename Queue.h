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
    bool flag1 = false; // empty flag
    bool flag = 0; // overflow flag
    long size;
    long back_point;
    long front_point;
    T5 *queue;


    short check_some_event()
    {
        if(front_point+1 == back_point) return 1; // empty queue
        else if(front_point == back_point+1) return 2; // overflow
        return 0;
    }

    bool overflow()
    {
        if(front_point == 0 && back_point == size) return 1;
        else if(back_point == front_point && front_point != 0 && back_point != 0) return 1;
        return 0;
    }



public:
    Queue(long size) {
        this->size = size;
        queue = new T5[size];
        back_point = 0;
        front_point = 0;
    }

    Queue(Queue &a) {
        back_point = a.back_point;
        front_point = a.front_point;
        size = a.size;
        if(front_point < back_point)
            for (int i = front_point; i < back_point; i++)
                queue[i] = a.queue[i];
        else 
        {
            for (int i = front_point; i < size; i++)
                queue[i] = a.queue[i];
            for (int i = 0; i < back_point; i++)
                queue[i] = a.queue[i];
        }
    }

    void print() {
        if(flag1 != 1){
            if(front_point < back_point)
                for (int i = front_point; i < back_point; i++)
                    cout << queue[i] << " ";
            else 
            {
                for (int i = front_point; i < size; i++)
                    cout << queue[i] << " ";
                for (int i = 0; i < back_point; i++)
                    cout << queue[i] << " ";
            }
            cout << endl;
        }else cerr << "Error. Queue is empty." << endl;
    }

    void push(const T5 a) 
    {
        if(!overflow())
        {
            if(back_point < size)
            {

                if(check_some_event() == 2)
                {
                    queue[back_point] = a;
                    back_point++;
                    flag = 1; 
                }
                else
                {
                    flag1 = 0;
                    queue[back_point] = a;
                    if(!flag) back_point++;
                }
                
            }else
            {
                back_point = 0;
                flag1 = 0;
                queue[back_point] = a;
                back_point++;
            }
        } else cerr << "Error. Queue is full." << endl;
    }

    T5 pop() {
        T5 buf;
        if(front_point < size)
        {
            if(check_some_event() == 1)
            {

                buf = queue[front_point];
                front_point++; 
                flag1 = 1; 
            }else
            {
                flag = 0;
                buf = queue[front_point];
                front_point++;
                if(flag1) {cerr << "Error. Queue is empty." << endl;}
            }
        }else
        {
            front_point = 0;
            flag = 0;
            buf = queue[front_point];
            front_point++;
        }
        return buf;
    }


    T5 peek() {
        if (!flag1) return queue[front_point];
        else cerr << "Error. Queue is empty" << endl;
        return 0;
    }

    void resize(int m) 
    {
        T5* queue_buf = new T5[m];
        memcpy( queue_buf, queue, count() * sizeof(T5));
        size = m;
        delete [] queue;
        queue = queue_buf;
    }

    long count() {
        long current_size = 0;
        if (front_point == 0 && back_point != 0) current_size = back_point;
        else if(flag1 == 1 && flag == 1) current_size = size;
        else if(back_point < front_point) current_size =size-front_point+back_point;
        else current_size =back_point-front_point;
        return current_size;
    }

    void Swap(Queue &a) {
        if (back_point > front_point && back_point-front_point == a.back_point-a.front_point)
            for (int i = 0; i < back_point; ++i)
                swap(queue[i], a.queue[i]);
        else if (back_point < front_point && front_point-back_point == a.front_point- a.back_point)
            for (int i = 0; i < back_point; ++i)
                swap(queue[i], a.queue[i]);
        else cerr << "Error. Number of elements must be equal." << endl;
    }

    bool isMount() {
        if (count() >= 3) {
            T5 max = queue[0];
            int imax = 0;

            for (int i = 1; i < back_point - 1; i++) {
                if (max == queue[i]) return false;
                if (max < queue[i]) {
                    max = queue[i];
                    imax = i;
                }
            }

            for (int i = 0; i < imax; i++) {
                if (queue[i] >= queue[i + 1]) return false;
            }

            for (int i = imax; i < back_point - 1; i++) {
                if (queue[i] <= queue[i + 1]) return false;
            }
            return true;
        } else return false;
    }

    Queue &operator=(const Queue &a) {
        count() = a.count();
        if(front_point < back_point)
            for (int i = front_point; i < back_point; i++)
                queue[i] = a.queue[i];
        else 
        {
            for (int i = front_point; i < size; i++)
                queue[i] = a.queue[i];
            for (int i = 0; i < back_point; i++)
                queue[i] = a.queue[i];
        }
        return *this;
    }

    bool operator<(Queue &a) {
        return (this->count() < a.count());
    }

    bool operator>(Queue &a) {
        return (this->count() > a.count());
    }

    bool operator<=(Queue &a) {
        return (this->count() <= a.count());
    }

    bool operator>=(Queue &a) {
        return (this->count() >= a.count());
    }

    bool operator==(Queue &a) {
        return (this->count() == a.count());
    }

    bool operator!=(Queue &a) {
        return (this->count() != a.count());
    }

    ~Queue() {
        delete[] queue;
    }
};

#endif //QUEUE_H
