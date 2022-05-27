/*
Data structure that can store object of almost any type
    .Template-based classes

Each container has member functions
    some are specific to the container
    Others are available to all containers

Each container has an associated header file
    . #include <container_type>
*/

/*
Some of the  common methods provided by STL containers


Default constructor  -> initializes an empty container
Overloaded constructor -> initializes container with many options
Copy constructors -> Initializes a container as a copy of another container
Move constructor -> Moves existing container to new container
Destructor -> Destroys a container
Copy Assignment (operator=) -> copy one container to another
Move Assignment (operator=) -> Move one container to another
size -> REturns the number of elements in the container
empty -> Returns boolean - is the container empty?
insert -> insert an element into the container

*/

/*
What type of element can we store in containers?

. A copy of the element will be stored in the container
    . All primitive Ok

. Element should be
    . Copyable and assignable (copy constructor / copy assignment)
    . Moveable for efficiency (move constructor / move assignment)

. Ordered associative containers must be able to  compare element
    .operator< , operator ==

*/