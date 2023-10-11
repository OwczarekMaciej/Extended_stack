#include <iostream>
#include "Stack.h"

int main()
{
    Stack s1;

    for (int i = 0; i < 3; i++)
    {
        s1.push(i);
    }
    s1.get_stack();
    
    Stack s2(s1);
    Stack s3 = s1;

    s2.get_stack();
    s3.get_stack();

    std::cout << "=============" << std::endl;

    Stack s4;
    s4.push(10);
    s2 = s4;
    s2.get_stack();
    s4 = s1;
    s4.get_stack();

    std::cout << "=============" << std::endl;
    pop_last_value1(s4);
    s4.get_stack();
    pop_last_value2(s4);
    s4.get_stack();

    return 0;
}
