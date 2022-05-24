/*
shared_ptr

. Provides shared ownership of heap objects

. shared_ptr<T>
    . Points to an object of type T on the heap
    . It is not unique - there can  be many shared_ptrs pointing to the smae object on the heap
    . Establishes shared ownership relationship
    . CAN be assigned and copied
    . CAN be moved
    . Does'nt support managing arrays by default
    . When the use count is Zero, the managed object on the heap is destroyed

*/