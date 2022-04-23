#include "Tests.h"
#include "Stack.h"
#include "Queue.h"
#include "Vector.h"

void written_stack_test() {
    cout << "--------------------" << endl << "Test of written stack functions:" << endl;
    Stack<int> st1(3);
    st1.push(4);
    st1.push(2);
    st1.push(3);
    st1.print();
    st1.resize(5);
    st1.push(6);
    st1.push(5);
    st1.push(8);
    st1.print();
    if (st1.isMount()) cout << "Stack is mount" << endl;
    else cout << "Stack is not mount" << endl;
    Stack<int> st2(5);
    st2.push(1);
    st2.push(2);
    st2.push(3);
    st2.push(4);
    st2.push(5);
    st2.print();
    st1.Swap(st2);
    st1.print();
    st2.print();
    if (st1 > st2) cout << "Gt" << endl;
    else if (st1 < st2) cout << "Lt" << endl;
    else cout << "Equal" << endl;
    cout << st1.pop() << endl;
    cout << st1.pop() << endl;
    cout << "Stack peek: " << st1.peek() << endl;
    cout << st1.pop() << endl;
    cout << st1.pop() << endl;
    cout << st1.pop() << endl;
    cout << st1.pop() << endl;
}

void stack_time_comparison() {
    cout << "--------------------" << endl << "Time comparison test between STL stack and written stack:" << endl;
    auto written_stack_start = std::chrono::high_resolution_clock::now();
    Stack<int> written_stack(2000000);
    for (int i = 0; i < 200000; i++)
        written_stack.push(i);
    cout << written_stack.count() << endl;
    cout << written_stack.peek() << endl;
    for (int i = 0; i < 100000; i++)
        written_stack.pop();
    cout << written_stack.count() << endl;
    cout << written_stack.peek() << endl;
    for (int i = 0; i < 40000; i++)
        written_stack.pop();
    cout << written_stack.count() << endl;
    cout << written_stack.peek() << endl;
    auto written_stack_end = std::chrono::high_resolution_clock::now();
    auto written_stack_res = std::chrono::duration_cast<ms>(written_stack_end - written_stack_start).count();
    cout << "Written stack performance time: " << written_stack_res << " ms" << endl << endl;

    auto stl_stack_start = std::chrono::high_resolution_clock::now();
    stack<int> stl_stack;
    for (int i = 0; i < 200000; i++)
        stl_stack.push(i);
    cout << stl_stack.size() << endl;
    cout << stl_stack.top() << endl;
    for (int i = 0; i < 100000; i++)
        stl_stack.pop();
    cout << stl_stack.size() << endl;
    cout << stl_stack.top() << endl;
    for (int i = 0; i < 40000; i++)
        stl_stack.pop();
    cout << stl_stack.size() << endl;
    cout << stl_stack.top() << endl;
    auto stl_stack_end = std::chrono::high_resolution_clock::now();
    auto stl_stack_res = std::chrono::duration_cast<ms>(stl_stack_end - stl_stack_start).count();
    cout << "STL stack performance time: " << stl_stack_res << " ms" << endl << "--------------------" << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////

void written_queue_test() {
    Queue<int> queue1;
    queue1.push(4);
    queue1.push(2);
    queue1.push(3);
    queue1.print();
    queue1.push(6);
    queue1.push(5);
    queue1.print();
    if (queue1.isMount()) cout << "Queue is mount" << endl;
    else cout << "Queue is not mount" << endl;
    Queue<int> queue2;
    queue2.push(1);
    queue2.push(2);
    queue2.push(3);
    queue2.push(4);
    queue2.push(5);
    queue2.print();
    queue1.Swap(queue2);
    queue1.print();
    queue2.print();
    if (queue1 > queue2) cout << "Gt\n";
    else if (queue1 == queue2) cout << "equal\n";
    else cout << "LT\n";
    cout << queue1.peek() << endl;
    cout << queue1.pop() << endl;
    cout << queue1.pop() << endl;
    cout << queue1.pop() << endl;
    cout << queue1.pop() << endl;
    cout << queue1.pop() << endl;
    cout << queue1.peek() << endl;
}

void queue_time_comparison() {

}

//////////////////////////////////////////////////////////////////////////////////////////

void written_vector_test() {
    Vector<int> v1(3);
    v1.push(2);  v1.push(234, 0); v1.push(22,1);
    v1.print();
    v1.pop(); v1.print();
    cout << v1.at(2) << "\n" << v1.count() << " " << v1.peek()<<endl;
    v1.resize(1);
    v1.push(1);  v1.push(2); v1.push(3);
    v1.print();
    Vector<int> v2(4);
    v2.push(1); v2.push(2); v2.push(3); v2.push(1);
    v1.resize(4);
    v1.push(1);  v1.push(2); v1.push(3);
    v2.Swap(v1);
    v1.print();
    cout << (v1.isMount())<<" "<<(v2.isMount())<<" "<<(v1>=v2)<<endl;
    Vector<float> vg(2000000);
    for (int i = 0; i < 2000000; i++)
        vg.push(i);
    cout << vg.count() << " " << vg.at(10032)<<endl;
    vg.pop(10032); cout<< vg.count() << " " << vg.at(10032)<<endl;
}

void vector_time_comparison() {
    cout << "--------------------" << endl << "Time comparison test between STL vector and written vector:" << endl;
    cout << "--------------------" << endl << "Time comparison test between STL vector and written vector:" << endl;
    auto written_vector_start = std::chrono::high_resolution_clock::now();
    Vector<int> written_vector(2000000);
    for (int i = 0; i < 2000000; i++)
        written_vector.push(i);
    cout << written_vector.count() << endl;
    cout << written_vector.peek() << endl;
    for (int i = 0; i < 1000000; i++)
        written_vector.pop();
    cout << written_vector.count() << endl;
    cout << written_vector.peek() << endl;
    for (int i = 0; i < 400000; i++)
        written_vector.pop();
    cout << written_vector.count() << endl;
    cout << written_vector.peek() << endl;
    cout << written_vector.at(5) << endl;
    auto written_vector_end = std::chrono::high_resolution_clock::now();
    auto written_vector_res = std::chrono::duration_cast<ms>(written_vector_end - written_vector_start).count();
    cout << "Written vector performance time: " << written_vector_res << " ms" << endl << endl;

    auto stl_vector_start = std::chrono::high_resolution_clock::now();
    vector<int> stl_vector;
    for (int i = 0; i < 2000000; i++)
        stl_vector.push_back(i);
    cout << stl_vector.size() << endl;
    cout << stl_vector.back() << endl;
    for (int i = 0; i < 1000000; i++)
        stl_vector.pop_back();
    cout << stl_vector.size() << endl;
    cout << stl_vector.back() << endl;
    for (int i = 0; i < 400000; i++)
        stl_vector.pop_back();
    cout << stl_vector.size() << endl;
    cout << stl_vector.back() << endl;
    cout << stl_vector.at(5) << endl;
    auto stl_vector_end = std::chrono::high_resolution_clock::now();
    auto stl_vector_res = std::chrono::duration_cast<ms>(stl_vector_end - stl_vector_start).count();
    cout << "STL vector performance time: " << stl_vector_res << " ms" << endl << "--------------------" << endl;
}

