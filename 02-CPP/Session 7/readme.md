# Threading & filesystem in C++

## Threading

### What is a thread?

A thread is a sequence of such instructions within a program that can be executed independently of other code. For simplicity, you can think of a thread as a parallel path of execution through a program. Threads are popular way to improve application through parallelism.

### Why use threads?

- **Responsiveness**: Multithreading can keep your application running smoothly even when performing CPU-intensive tasks.

- **Resource Sharing**: Threads share the same address space. This allows them to share data with each other easily.

- **Scalability**: Threads can be used to take advantage of multiple CPUs.

- **Simplicity**: Threads can simplify your code by moving complex tasks into separate threads.

### Creating a thread

```cpp

#include <iostream>
#include <thread>

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in thread\n";
}

int main()
{
    // create thread
    std::thread t(threadFunction);

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in main\n";

    // wait for thread to finish
    t.join();

    return 0;
}

```

#### if you dont join the thread, the program will crash

**Explanation**: When the main function exits, the program will terminate and the thread will be destroyed. If the thread is still running, the program will be terminated and the resources allocated to the thread will be lost. To prevent this, we call join on the thread object. This will tell the main function to wait for the thread to finish before exiting.

### Detaching a thread

```cpp

#include <iostream>

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in thread\n";
}

int main()
{
    // create thread
    std::thread t(threadFunction);

    // detach thread
    t.detach();

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in main\n";

    return 0;
}

```

**Explanation**: When we detach a thread, we are telling the runtime that we no longer need to wait for the thread to finish. The runtime can clean up the resources as soon as the thread finishes. This is useful when we don't need to wait for the thread to finish.

### Threads with arguments

```cpp

#include <iostream>

void threadFunction(int i)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in thread with argument: " << i << "\n";
}

int main()
{
    // create thread
    int i = 1;
    std::thread t(threadFunction, i);

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in main\n";

    // wait for thread to finish
    t.join();

    return 0;
}

```

### Threads with functors

```cpp

#include <iostream>

class Vehicle
{

public:
    void operator()()
    {
        std::cout << "Vehicle object has been created \n";
    }
};

int main()
{
    // create thread
    std::thread t(Vehicle());

    // do something in main()
    std::cout << "Finished work in main\n";

    // wait for thread to finish
    t.join();

    return 0;
}

```

### Sleeping

```cpp

#include <iostream>

int main()
{
    // simulate work
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work in main\n";

    return 0;
}

```

### Sleep Until

```cpp

#include <iostream>

int main()
{
    // get the current time
    auto start = std::chrono::high_resolution_clock::now();

    // wait for 1 second
    std::this_thread::sleep_until(start + std::chrono::seconds(1));

    // get the current time
    auto end = std::chrono::high_resolution_clock::now();

    // print the difference
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Waited " << elapsed.count() << " ms\n";

    return 0;
}

```

### Race Conditions

```cpp

#include <iostream>
#include <thread>

int counter = 0; // a global variable


void updateCounter()
{
    // simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    for (int i = 0; i < 100; i++)
    {
        counter++; // increment the counter
    }
} 

int main()
{
    // create thread
    std::thread t1(updateCounter);
    std::thread t2(updateCounter);

    // wait for thread to finish
    t1.join();
    t2.join();

    std::cout << "Final counter value is " << counter << "\n";

    return 0;
}

```

**Explanation**: In the code above, we have two threads that are incrementing a global variable counter. The threads are running in parallel and are updating the counter variable at the same time. This can lead to unexpected results because the threads are not synchronized and are not updating the counter in a thread-safe way. This is called a `Race Condition`.

### Mutex

`Mutex` is a locking mechanism that ensures that only one thread can access a shared resource at a time. It is used to protect shared data from being simultaneously accessed by multiple threads.

```cpp

#include <iostream>
#include <thread>
#include <mutex>

int counter = 0; // a global variable

std::mutex mtx; // mutex for critical section

void updateCounter()
{
    // simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
            mtx.lock();
    for (int i = 0; i < 100; i++)
    {
        counter++; // increment the counter
    }
            mtx.unlock();

}

int main()
{
    // create thread
    std::thread t1(updateCounter);
    std::thread t2(updateCounter);

    // wait for thread to finish
    t1.join();
    t2.join();

    std::cout << "Final counter value is " << counter << "\n";

    return 0;
}

```

**Explanation**: In the code above, we have two threads that are incrementing a global variable counter. We have used a mutex to protect the shared resource (counter) from being accessed by multiple threads at the same time. The mutex ensures that only one thread can access the shared resource at a time.

### Lock Guard

`std::lock_guard` is a class template that provides a convenient way to acquire and release a lock. When a `lock_guard` object is created, it acquires the lock on a mutex. When the `lock_guard` object goes out of scope, it releases the lock.

```cpp

#include <iostream>
#include <thread>
#include <mutex>

int counter = 0; // a global variable

std::mutex mtx; // mutex for critical section


void updateCounter()
{
    // simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::lock_guard<std::mutex> lck(mtx);
    for (int i = 0; i < 100; i++)
    {
        counter++; // increment the counter
    }
}


int main()
{
    // create thread
    std::thread t1(updateCounter);
    std::thread t2(updateCounter);

    // wait for thread to finish
    t1.join();
    t2.join();

    std::cout << "Final counter value is " << counter << "\n";

    return 0;
}

```

**Explanation**: In the code above, we have two threads that are incrementing a global variable counter. We have used a `lock_guard` to acquire and release the lock on the mutex. The `lock_guard` ensures that the lock is acquired when the `lock_guard` object is created and released when the `lock_guard` object goes out of scope.


### Unique Lock

`std::unique_lock` is a class template that provides a flexible way to manage locks. It provides more flexibility than `std::lock_guard` and can be used to defer lock acquisition, release the lock manually, and transfer lock ownership.

```cpp

#include <iostream>
#include <thread>
#include <mutex>

int counter = 0; // a global variable

std::mutex mtx; // mutex for critical section

void updateCounter()
{
    // simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::unique_lock<std::mutex> lck(mtx);
    for (int i = 0; i < 100; i++)
    {
        counter++; // increment the counter
    }
}

int main()
{
    // create thread
    std::thread t1(updateCounter);
    std::thread t2(updateCounter);

    // wait for thread to finish
    t1.join();
    t2.join();

    std::cout << "Final counter value is " << counter << "\n";

    return 0;
}

```

**Explanation**: In the code above, we have two threads that are incrementing a global variable counter. We have used a `unique_lock` to acquire and release the lock on the mutex. The `unique_lock` provides more flexibility than `lock_guard` and can be used to defer lock acquisition, release the lock manually, and transfer lock ownership.


### Condition Variables

`std::condition_variable` is a synchronization primitive that allows one or more threads to wait until notified by another thread. It is often used in combination with a `std::unique_lock` to protect the shared data.

```cpp

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx; // mutex for critical section
std::condition_variable cv; // condition variable for critical section
bool ready = false; // condition variable to check if data is ready

void print_id(int id)
{
    std::unique_lock<std::mutex> lck(mtx);
    while (!ready) cv.wait(lck);
    // print the id
    std::cout << "Thread " << id << "\n";
}

void go()
{
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_all();
}

int main()
{
    // create thread
    std::thread threads[10];
    for (int i = 0; i < 10; ++i)
    {
        threads[i] = std::thread(print_id, i);
    }

    std::cout << "10 threads" << std::endl;

    // wait for thread to finish
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    go();

    for (auto &t : threads)
    {
        t.join();
    }

    return 0;

}

```

**Explanation**: In the code above, we have 10 threads that are waiting for the `ready` flag to be set to true. The `go` function sets the `ready` flag to true and notifies all the waiting threads using the `notify_all` function. The waiting threads are then unblocked and print their id.

### Promise and Future

`std::promise` is a template class that allows you to store a value or an exception that can be retrieved asynchronously by a `std::future` object. `std::future` is a template class that provides a mechanism to access the result of an asynchronous operation.

```cpp

#include <iostream>
#include <thread>
#include <future>

void print_int(std::future<int> &fut)
{
    int x = fut.get();
    std::cout << "Value: " << x << std::endl;
}

int main()
{
    // create promise and future
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    // create thread
    std::thread t(print_int, std::ref(fut));

    // set the value
    prom.set_value(10);

    // wait for thread to finish
    t.join();

    return 0;
}

```

### Promise and Future with return value

```cpp

#include <iostream>
#include <thread>
#include <future>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    // create promise and future
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    // create thread
    std::thread t([&prom]() {
        int result = add(10, 20);
        prom.set_value(result);
    });

    // get the result
    int result = fut.get();
    std::cout << "Result: " << result << std::endl;

    // wait for thread to finish
    t.join();

    return 0;
}

```

### Async

`std::async` is a function template that runs a function asynchronously (potentially in a separate thread) and returns a `std::future` that will hold the result of the function.

```cpp

#include <iostream>
#include <future>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    // run add asynchronously
    std::future<int> fut = std::async(add, 10, 20);

    // get the result
    int result = fut.get();
    std::cout << "Result: " << result << std::endl;

    return 0;
}

```

### Async vs thread

`std::async` is a higher-level abstraction that allows you to run a function asynchronously and get the result using a `std::future`. `std::async` can run the function in a separate thread or in the same thread depending on the implementation. `std::thread` is a lower-level abstraction that allows you to create and manage threads manually.

## Filesystem

The `filesystem` library provides facilities for performing operations on file systems and their components, such as paths, regular files, and directories.

```cpp

#include <iostream>
#include <filesystem>

int main()
{
    // create a directory
    std::filesystem::create_directory("test");

    // check if the directory exists
    if (std::filesystem::exists("test"))
    {
        std::cout << "Directory exists\n";
    }

    // remove the directory
    std::filesystem::remove("test");

    // check if the directory exists
    if (!std::filesystem::exists("test"))
    {
        std::cout << "Directory does not exist\n";
    }

    return 0;
}

```

**Explanation**: In the code above, we create a directory called `test` using the `create_directory` function. We then check if the directory exists using the `exists` function. We remove the directory using the `remove` function and check if the directory exists again.


### fstream

`fstream` is a header file in the C++ Standard Library that provides classes for file handling. It allows you to read from and write to files using file streams.

```cpp

#include <iostream>
#include <fstream>

int main()
{
    // create a file stream
    std::ofstream file("test.txt");

    // write to the file
    file << "Hello, World!\n";

    // close the file
    file.close();

    // open the file for reading
    std::ifstream infile("test.txt");

    // read from the file
    std::string line;
    while (std::getline(infile, line))
    {
        std::cout << line << std::endl;
    }

    // close the file
    infile.close();

    return 0;
}

```

**Explanation**: In the code above, we create a file stream called `file` and write the string `Hello, World!` to the file `test.txt`. We then close the file. We open the file for reading using `ifstream` and read the contents of the file line by line using `getline`. We then close the file.

### Filesystem and fstream

```cpp

#include <iostream>
#include <fstream>
#include <filesystem>

int main()
{
    // create a directory
    std::filesystem::create_directory("test");

    // create a file stream
    std::ofstream file("test/test.txt");

    // write to the file
    file << "Hello, World!\n";

    // close the file
    file.close();

    // open the file for reading
    std::ifstream infile("test/test.txt");

    // read from the file
    std::string line;
    while (std::getline(infile, line))
    {
        std::cout << line << std::endl;
    }

    // close the file
    infile.close();

    // remove the directory
    std::filesystem::remove_all("test");

    return 0;
}

```

### rdbuf

`rdbuf` is a member function of the `std::ifstream` class that returns a pointer to the file buffer associated with the stream. You can use this pointer to read data from the file buffer.

```cpp

#include <iostream>
#include <fstream>

int main()
{
    // open the file for reading
    std::ifstream infile("test.txt");

    // get the file buffer
    std::filebuf *pbuf = infile.rdbuf();

    // get the file size
    std::size_t size = pbuf->pubseekoff(0, infile.end, infile.in);
    pbuf->pubseekpos(0, infile.in);

    // allocate memory to store the file data
    char *buffer = new char[size];

    // read the file data
    pbuf->sgetn(buffer, size);

    // print the file data
    std::cout.write(buffer, size);

    // deallocate memory
    delete[] buffer;

    // close the file
    infile.close();

    return 0;
}

```

### is_open/open/close

`is_open` is a member function of the `std::ifstream` class that checks if the file stream is open. `open` is a member function of the `std::ifstream` class that opens a file. `close` is a member function of the `std::ifstream` class that closes the file.

```cpp

#include <iostream>
#include <fstream>

int main()
{
    // open the file for reading
    std::ifstream infile;
    infile.open("test.txt");

    // check if the file is open
    if (infile.is_open())
    {
        std::cout << "File is open\n";
    }

    // close the file
    infile.close();

    return 0;
}

```

### basic_istream


`basic_istream` is a template class that provides input operations on streams. It is the base class for all input stream classes in the C++ Standard Library.

check ![cppreference](https://en.cppreference.com/w/cpp/io/basic_istream) for more information

### bitstate

`bitstate` is a member function of the `std::ios_base` class that returns the current state of the stream. It returns a bitmask that represents the state of the stream.
the possible values are:
        
        - goodbit -> no error
        - badbit  -> unrecoverable error
        - failbit -> recoverable error
        - eofbit  -> end of file

```cpp

#include <iostream>
#include <fstream>


int main()
{
    // open the file for reading
    std::ifstream infile("test.txt");

    // get the bit state
    std::ios_base::iostate state = infile.rdstate();

    // check if the stream is good
    if (state == std::ios_base::goodbit)
    {
        std::cout << "Stream is good\n";
    }

    // close the file
    infile.close();

    return 0;
}

```

### seek

`seek` is a member function of the `std::ifstream` class that sets the position of the file pointer. It allows you to seek to a specific position in the file.
the possible values are:
        
        - beg -> beginning of the file
        - cur -> current position
        - end -> end of the file

```cpp

#include <iostream>
#include <fstream>

int main()
{
    // open the file for reading
    std::ifstream infile("test.txt");

    // seek to the end of the file
    infile.seekg(0, std::ios_base::end);

    // get the current position
    std::streampos pos = infile.tellg(); //tellg() returns the current position of the file pointer

    // print the current position
    std::cout << "Current position: " << pos << std::endl;

    // close the file
    infile.close();

    return 0;
}

```

### Read file

```cpp

#include <iostream>
#include <fstream>

int main()
{
    // open the file for reading
    std::fstream file("test.txt", std::ios::in); // std::ios::in is used to open the file for reading

    if (!file.is_open())
    {
        std::cerr << "Error opening file\n";
        return 1;
    }
    // read the file
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }

    // close the file
    file.close();

    return 0;

}

```

### Write file

```cpp

#include <iostream>
#include <fstream>

int main()
{
    // open the file for writing
    std::fstream file("test.txt", std::ios::out); // std::ios::out is used to open the file for writing

    if (!file.is_open())
    {
        std::cerr << "Error opening file\n";
        return 1;
    }

    // write to the file
    file << "Hello, World!\n";

    // close the file
    file.close();

    return 0;
}

```

### Read binary

```cpp

#include <iostream>
#include <fstream>


int main()
{
    // open the file for reading in binary mode
    std::fstream file("test.bin", std::ios::binary|std::ios::in);

    if (!file.is_open())
    {
        std::cerr << "Error opening file\n";
        return 1;
    }

    // read the file
    char buffer[256];
    file.read(buffer, sizeof(buffer));

    // print the file data
    std::cout.write(buffer, file.gcount()); // gcount() returns the number of characters read

    // close the file
    file.close();

    return 0;

}
```

