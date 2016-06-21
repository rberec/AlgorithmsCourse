* Problem:

error: undefined reference to `vtable for XXX':

* Solution:

This linker error usually (in my experience) means that you've overridden a virtual function in a child class with a declaration, but haven't given a definition for the method. For example:

class Base
{
    virtual void f() = 0;
}
class Derived : public Base
{
    void f();
}

But you haven't given the definition of f. When you use the class, you get the linker error. Much like a normal linker error, it's because the compiler knew what you were talking about, but the linker couldn't find the definition. It's just got a very difficult to understand message.
