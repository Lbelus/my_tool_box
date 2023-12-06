#include <threadpool.hpp>


unsigned int GetThreadCount(unsigned int divBy)
{
     unsigned int nbThread = std::thread::hardware_concurrency();
     unsigned int result = nbThread / divBy;
     return result;
}

void printTask(int number)
{
    std::cout << "Printing number: " << number << std::endl;
}


// int main()
// {
//     ThreadPool pool(2); // 2 worker threads

//     for (int i = 0; i < 5; ++i)
//     {
//         pool.enqueue([i]() { printTask(i); });
//     }

//     std::this_thread::sleep_for(std::chrono::seconds(2)); // let threads process tasks
//     return 0;
// }