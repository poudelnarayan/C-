// The Final Specifier

/*
C++11 provides the final specifier
    . When used at the class level:  Prevents a class from being derived from
    . When used at the method level: Prevents a virtual method being overridden in derived classes

*/

/*
CLASS LEVEL FINAL SPECIFIER

class MyClass final {
    ....
};

class Derived final : public Base {
    ....
};

*/

/*
METHOD LEVEL FINAL SPECIFIER

class A {
    public :
        virtual void doSomething();
};

class B : public A {
    public:
        virtual void doSomething() final;  // prevent further overriding
};

class C : public B {
    public:
        virtual void doSomething();   // Compiler Error - Can't Override
}

*/
