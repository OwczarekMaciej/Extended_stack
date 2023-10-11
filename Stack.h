#ifndef STACK_H
#define STACK_H

#pragma once

class Stack
{
public:
    Stack();
    ~Stack();

    Stack(const Stack &source);
    Stack &operator=(const Stack &source);

    void push(int element);
    int pop();
    bool isEmpty();
    void get_stack();

private:
    int *array;
    int top_element;
    int size;
    void alloc_check();
};

void pop_last_value1(Stack s);
void pop_last_value2(Stack &s);

#endif
