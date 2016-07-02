#include <string>
#include <sstream>


#include <Stack.hpp>

int main(int argc, char *argv[])
{     
    Stack<std::string> s;
    
    s.insert("to");
    s.insert("be");
    s.insert("or");
    s.insert("not");
    s.insert("to");
    
    std::printf("%s ", s.pop().c_str());
    
    s.insert("be");
    
    std::printf("%s ", s.pop().c_str());
    std::printf("%s ", s.pop().c_str());
    
    s.insert("that");
    
    std::printf("%s ", s.pop().c_str());
    std::printf("%s ", s.pop().c_str());
    std::printf("%s ", s.pop().c_str());

    
    s.insert("is");
    
    return 0;
}