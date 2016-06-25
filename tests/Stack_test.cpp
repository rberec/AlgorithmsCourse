#include <string>

#include <Stack.hpp>

int main(int argc, char *argv[])
{     
    Stack<std::string> s;
    
    s.insert("to");
    s.insert("be");
    s.insert("or");
    s.insert("not");
    s.insert("to");
    
    s.pop();
    
    s.insert("be");
    
    s.pop();
    s.pop();
    
    s.insert("that");
    
    s.pop();
    s.pop();
    s.pop();
    
    s.insert("is");
    
    return 0;
}