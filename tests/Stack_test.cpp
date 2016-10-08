#include <string>
#include <sstream>
#include <stdio.h>


#include <Stack.hpp>

int main(int argc, char *argv[])
{     
    Stack<std::string> s;
    
    s.insert("to");
    s.insert("be");
    s.insert("or");
    s.insert("not");
    s.insert("to");
    
    printf("%s ", s.pop().c_str());
    
    s.insert("be");
    
    printf("%s ", s.pop().c_str());
    printf("%s ", s.pop().c_str());
    
    s.insert("that");
    
    printf("%s ", s.pop().c_str());
    printf("%s ", s.pop().c_str());
    printf("%s ", s.pop().c_str());

    
    s.insert("is");
    
    return 0;
}