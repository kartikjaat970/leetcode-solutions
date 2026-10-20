#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;

class FizzBuzz {
private:
    int n;
    int i;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) : n(n), i(1) {}

    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return i > n || (i % 3 == 0 && i % 5 != 0); });
            if (i > n) break;
            printFizz();
            ++i;
            lock.unlock();
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return i > n || (i % 5 == 0 && i % 3 != 0); });
            if (i > n) break;
            printBuzz();
            ++i;
            lock.unlock();
            cv.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return i > n || (i % 3 == 0 && i % 5 == 0); });
            if (i > n) break;
            printFizzBuzz();
            ++i;
            lock.unlock();
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return i > n || (i % 3 != 0 && i % 5 != 0); });
            if (i > n) break;
            printNumber(i++);
            lock.unlock();
            cv.notify_all();
        }
    }
};
