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

    // detach thread and continue with main
    t.detach();

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in main\n";

    return 0;
}

/*
分离线程：调用 detach() 方法后，线程将变为“分离”状态，意味着它将独立于 std::thread 对象运行。
不再可控：分离后的线程将自动运行到完成，不能再通过 std::thread 对象对其进行操作，如 join()。
资源管理：分离线程后，程序员不再需要手动调用 join()
来等待线程完成，但需要确保线程运行期间不访问已销毁的资源，以避免未定义行为。
*/