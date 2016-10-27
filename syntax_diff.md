# C++ and Java Syntax Differences Cheat Sheet

[source](http://www.cprogramming.com/tutorial/java/syntax-differences-java-c++.html)

## main function
**c++**
```c++
// free-floating function
int main( int argc, char* argv[] )
{
    printf("Hello world");
}
```

**java**
``` java
// every function must be part of a class; the main function for a particular
// class file is invoked when java <class> is run (so you can have one
// main function per class--useful for writing unit tests for a class)
class HelloWorld
{
    public abstric void main( String args[] )
    {
        System.out.println("Hello world");
    }
}
```

## Method declarations
Same, except that in Java, must always be part of a class, and may prefix with public/private/protected


## Constructors and destructors
Constructor has same syntax in both (name of the class), Java has no exact equivalent of the destructor

## Static member functions and variables
Same as method declarations, but Java provides static initialization blocks to initialize static variables (instead of putting a definition in a source code file):
```java
class Foo
{
    static private int x;
    // static initialization block
    { x = 5; }
}
```

## Scoping static methods and namespaces
**c++**
``` c++
class Foo
{
    public:
    static bar();
};
// now it's used like this
Foo::bar();
```

**java**
```java
class Java
{
    public static void bar()
    {
        // do something
    }
}
// now it's used like this
Foo.bar();
```

## object declarations
**c++**
```c++
// on the stack
MyClass x;
x.my_field;
// or on the heap
MyClass *x = new MyClass;
x->my_field;
delete x;
```

**java**
```c++
// always allocated on the heap (also, always need parens for constructor)
myClass x = new myClass();
x.my_field;
```

## References vs. pointers
**c++**
```c++
// references are immutable, use pointers for more flexibility
int bar = 7, qux = 6;
int & foo = bar;
```

**java**
```java
// references are mutable and store addresses only to objects; there are no raw pointers
myClass x;
x.foo(); // error, x is a null ``pointer''
```

## Inheritance
**c++**
```c++
class Foo : public Bar
{ ... };
```

**java**
```java
class Foo extends Bar
{ ... }
```

## Abstract classes
**c++**
```c++
// just need to include a pure virtual function
class Bar { public: virtual void foo() = 0; };
```

**java**
```java
// syntax allows you to be explicit!
abstract class Bar { public abstract void foo(); }

// or you might even want to specify an interface
interface Bar { public void foo(); }

// and later, have a class implement the interface:
class Chocolate implements Bar
{
    public void foo() { /* do something */ }
}
```

## const-ness
**c++**
```c++
const int x = 7; // c++
final int x = 7; // java
```

## Arrays
**c++**
```c++
int x[10];
// or
int *x = new x[10];
// use x, then reclaim memory
delete[] x;
```

**java**
```java
int[] x = new int[10];
// use x, memory reclaimed by the garbage collector or returned to the
// system at the end of the program's lifetime
```

## Collections and Iteration
**c++**
Iterators are members of classes. The start of a range is < container >.begin(), and the end is < container >.end(). Advance using ++ operator, and access using .
```c++
vector myVec;
for ( vector<int>::iterator itr = myVec.begin();
    itr != myVec.end();
    ++itr )
{
    cout << *itr;
}
```

**java**
Iterator is just an interface. The start of the range is <collection>.iterator, and you check to see if you're at the end with itr.hasNext(). You get the next element using itr.next() (a combination of using ++ and * in C++).
```java
ArrayList myArrayList = new ArrayList();
Iterator itr = myArrayList.iterator();
while ( itr.hasNext() )
{
    System.out.println( itr.next() );
}

// or, in Java 5
ArrayList myArrayList = new ArrayList();
for( Object o : myArrayList ) {
    System.out.println( o );
}
