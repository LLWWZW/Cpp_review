#include <algorithm>
#include <condition_variable>
#include <deque>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

template <class T> class MessageQueue
{
  public:
    T receive()
    {
        std::unique_lock<std::mutex> uLock(_mutex);
        _cond.wait(uLock, [this] { return !_messages.empty() || _stopped; });

        if (_messages.empty())
        {
            return T(); // 返回默认构造的对象
        }

        T msg = std::move(_messages.back());
        _messages.pop_back();

        return msg;
    }

    void send(T &&msg)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::lock_guard<std::mutex> uLock(_mutex);
        std::cout << "   Message " << msg << " has been sent to the queue" << std::endl;
        _messages.push_back(std::move(msg));
        _cond.notify_one();
    }

    void stop()
    {
        std::lock_guard<std::mutex> uLock(_mutex);
        _stopped = true;
        _cond.notify_all();
    }

    bool dataIsAvailable()
    {
        std::lock_guard<std::mutex> uLock(_mutex);
        return !_messages.empty();
    }

    bool isStopped()
    {
        std::lock_guard<std::mutex> uLock(_mutex);
        return _stopped;
    }

  private:
    std::mutex _mutex;
    std::condition_variable _cond;
    std::deque<T> _messages;
    bool _stopped = false;
};

int main()
{
    std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);

    std::cout << "Spawning threads..." << std::endl;
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; ++i)
    {
        int message = i;
        futures.emplace_back(std::async(std::launch::async, &MessageQueue<int>::send, queue, std::move(message)));
    }

    std::future<void> receiver = std::async(std::launch::async, [&queue]() {
        while (true)
        {
            if (queue->isStopped() && !queue->dataIsAvailable())
                break;
            int message = queue->receive();
            if (message != int()) // 如果 message 是默认值，跳过打印
            {
                std::cout << "   Message #" << message << " has been removed from the queue" << std::endl;
            }
        }
    });

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) { ftr.wait(); });
    queue->stop();
    receiver.wait();

    std::cout << "Finished!" << std::endl;

    return 0;
}
