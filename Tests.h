#ifndef TESTS_H
#define TESTS_H

#include <chrono>
#include <stack>
#include <queue>
#include <vector>

using std::stack;
using std::queue;
using std::vector;

using ms = std::chrono::milliseconds;

void written_stack_test();

void stack_time_comparison();

void written_queue_test();

void queue_time_comparison();

void written_vector_test();

void vector_time_comparison();

#endif //TESTS_H