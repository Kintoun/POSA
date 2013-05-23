// POSA Assignment 1.
// I went with a Semaphore since that is the easiest way to alternate processing
// between 2 threads. Purely academic. I wouldn't want to create an entire
// infrastructure or framework for something so simple.

// Build instructions:
//		Rename from main.txt to main.cpp
//		Open Visual Studio 2012 Command Prompt
//		cd to file
//		run: cl /EHsc main.cpp

#include <iostream>

#include <thread>
#include <mutex>
#include <condition_variable>

// A simple non-count Sempahore.
class Semaphore
{
public:
	Semaphore(int startCount = 0) : count(startCount) {}

	void Wait()
	{
		std::unique_lock<std::mutex> scopedLock(m);
		while (count == 0)
			cv.wait(scopedLock);
		--count;
	}

	void Notify()
	{
		std::lock_guard<std::mutex> scopedLock(m);
		++count;
		cv.notify_one();
	}

private:
	std::mutex m;
	std::condition_variable cv;
	unsigned int count;
};

// TODO: Why does a reference not work here?
void WorkThread(const char* output, int iterations, Semaphore* myLock, Semaphore* theirLock)
{
	for (int i=0; i<iterations; ++i)
	{
		myLock->Wait();
		std::cout << output << std::endl;
		theirLock->Notify();
	}
}

int main()
{
	std::cout << "Ready... Set... Go!" << std::endl << std::endl;

	// TODO: I can do this without 2 locks, just the code isn't as clean
	Semaphore pingLock(1); // starts unlocked
	Semaphore pongLock;
	const int count = 3;

    std::thread ping(WorkThread, "Ping!", count, &pingLock, &pongLock);
	std::thread pong(WorkThread, "Pong!", count, &pongLock, &pingLock);
	
	// Wait for threads to complete
	ping.join();
    pong.join();

	std::cout << "Done!" << std::endl;

	// WINDOWS ONLY!
	system("pause");

    return 0;
}