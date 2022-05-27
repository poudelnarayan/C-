/*
Iterators allows us to think a container as a sequence of elements.It doesnot matter what the container
is . For exmaple , we might have a vector or a set or a map.
They are very different container but iterators allows us to process sequence of elements from these containers
without worrying or even needing to know about hoe the container is  implemented behind the scenes.
That gives us so much power.

Iterators are implemented as template classes so we create iterator objects and use them to iterate through our containers.
The syntax you use for iterators will remind you of pointers.
We can use the derefrence operator , the increment operators and decrement operator and so forth.


*/

#include <iostream>
#include <vector>

int main()
{

    std::vector<int> vec{1, 2, 3};
    std::vector<int>::reverse_iterator rit = vec.rbegin();
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    while (rit != vec.rend())
    {
        std::cout << *rit << " ";
        rit++;
    }

    return 0;
}
