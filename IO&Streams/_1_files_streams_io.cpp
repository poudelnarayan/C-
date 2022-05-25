/*
Common Header Files

iostream -> Provides definition for formatted input and output from/to streams
fstream -> Provides definitions for formatted input and output from/to file streams
iomanip -> provides definition for manipulators used to format stream I/O

*/

/*
When we include these header files we get access to many C++ classes that we can use for file IO.

ios  -> provides basic support for formatted and unformatted I/O operations.
ifstream -> Provides for high-level input operations on file based system
ofstream -> provides for high-level output operations on file based streams
fstream -> provides for high-level I/O operations on file based streams. Derived from ofstream and ifstream
stringstream -> Provides for high-level I/O operations on memory based strings. Derived from istringstream and ostringstream

*/

/*
Global stream objects

cin  -> Standard input stream - by default 'connected' to the standard input device (keyboard) . Instance of istream
cout -> Standard output stream - by default 'connected' to the standard output device (console). Instance of ostream
cerr -> Standard error stream - by default 'connected' to the standard error device (console). Instance of ostream (unbuffered)
clog -> Standard log stream - by default 'connected' to the standard log device (console) . Instance of ostream (uinbuffered)

Global objects -> initialized before main executes
Best practice is t use cerr for error messages and clog for log message


*/
