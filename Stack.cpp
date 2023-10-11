#include "Stack.h"
#include <iostream>

#define SIZE 1

Stack::Stack()
    : top_element(0), size(SIZE)
{
    array = (int *)malloc(sizeof(int) * size);
    alloc_check();
    std::cout << "Stack initialized" << std::endl;
}

Stack::Stack(const Stack &source) 
    : top_element(source.top_element), size(source.size)
{
    array = (int *)malloc(sizeof(int) * size);
    alloc_check();
    for (int i = 0; i < top_element; i++)    
    {
        array[i] = source.array[i];
    }
    std::cout << "Stack copied" << std::endl;
}

Stack::~Stack()
{
    free(array);
    std::cout << "Stack destroyed" << std::endl;
}


Stack &Stack::operator=(const Stack &source)
{
    std::cout << "Assignment operator" << std::endl;
    if(this == &source)
        return *this;
    top_element = source.top_element;
    size = source.size;
    free(array);
    array = (int *)malloc(sizeof(int) * size);
    alloc_check();
    for (int i = 0; i < source.top_element; i++)
    {
        array[i] = source.array[i];
    }
    std::cout << "Stack assignment completed" << std::endl;

    return *this;
}

void Stack::push(int element)
{
    if (top_element >= size)
    {
        size *= 2;
        array = (int *)realloc(array, sizeof(int) * size);
        alloc_check();
        std::cout << "Stack size increased to " << size << std::endl;
    }
    array[top_element++] = element;
    std::cout << "Pushed " << element << " to stack" << std::endl;
}

bool Stack::isEmpty()
{
    return (top_element == 0);
}

int Stack::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
        abort();
    }
    else
    {
        top_element--;
        std::cout << "Popped " << array[top_element] << " from stack" << std::endl;
        return array[top_element];
    }
}

void Stack::alloc_check()
{
    if (array == NULL)
    {
        std::cout << "Wrong memory alloc" << std::endl;
        abort();
    }
}

void Stack::get_stack()
{
    for (int i = 0; i < top_element; i++)
    {
        std::cout << array[i] << std::endl;
    }
    
}

void pop_last_value1(Stack s)
{
    s.pop();
}

void pop_last_value2(Stack &s)
{
    s.pop();
}
