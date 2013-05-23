// POSA Assignment 2.
// Monitor pattern

// Build instructions:
//		Rename from main.txt to main.cpp
//		Open Visual Studio 2012 Command Prompt
//		cd to file
//		run: cl /EHsc main.cpp

#include <iostream>
#include <string>
#include <sstream>

#include <thread>
#include <chrono>
#include <mutex>
#include <string>
#include <vector>
#include <condition_variable>

// Monitor which is used to prevent deadlocks
class DiningMonitor
{
public:
	DiningMonitor(int num) : m_dinerCount(num)
	{
		for (int i=0; i<m_dinerCount; ++i)
		{
			m_diners.push_back(false);
		}
	}

	void GrabChopsticks(int requesterPos)
	{
		std::unique_lock<std::mutex> scopeLock(m);

		// If my neighbors are eating then I cannot.
		while (!AllowedToEat(requesterPos))
		{
			m_cv.wait(scopeLock);
		}

		m_diners[requesterPos] = true;
	}

	void ReleaseChopsticks(int requesterPos)
	{
		std::lock_guard<std::mutex> scopeLock(m);

		m_diners[requesterPos] = false;

		m_cv.notify_all();
	}
	
private:
	bool AllowedToEat(int requesterPos)
	{
		int left = Wrap(requesterPos+1);
		int right = Wrap(requesterPos-1);
		return m_diners[left] == false && m_diners[right] == false;
	}

	int Wrap(int n)
	{
		n = n % m_dinerCount;
		if (n<0)
			n = m_dinerCount + n;
		return n;
	}

	std::mutex m;
	int m_dinerCount;
	std::vector<bool> m_diners;
	std::condition_variable m_cv;
};

// I hate stringstreams...
std::mutex print;
void ThreadSafePrint(std::ostream& output)
{
	std::lock_guard<std::mutex> scopeLock(print);

	std::ostringstream& s = dynamic_cast<std::ostringstream&>(output);
	std::cout << s.str() << std::flush;
}

void PhilosopherWorkThread(DiningMonitor* diningManager, int pos, int sleepTime)
{
	diningManager->GrabChopsticks(pos);
	ThreadSafePrint(std::ostringstream() << "Philosopher " << pos+1 << " picks up left chopstick" << std::endl
		<< "Philosopher " << pos+1 	<< " picks up right chopstick" << std::endl);
	 
	ThreadSafePrint(std::ostringstream() << "Philosopher " << pos+1 << " eats" << std::endl);
	//std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
	
	diningManager->ReleaseChopsticks(pos);
	
	ThreadSafePrint(std::ostringstream() << "Philosopher " << pos+1 << " puts down left chopstick" << std::endl
		<< "Philosopher " << pos+1 << " puts down right chopstick" << std::endl);
}

int main()
{
	ThreadSafePrint(std::ostringstream() << "Dinner is starting!" << std::endl << std::endl);

	const int numPhilosophers = 5;
	DiningMonitor diningManager(numPhilosophers);
	std::vector<std::thread> philoThreads;

	// Throw in some randomness to test variabilty of monitor access
	const int sleepTimes[numPhilosophers] = { 1000, 0, 50, 200, 0 };

	for (int i=0; i<numPhilosophers; ++i)
	{
		// Philo 0 has Chop0 on right, Chop1 on left
		// Philo 1 has Chop1 on right, Chop2 on left
		// Philo N has ChopN on right, ChopN+1%M on left (it wraps)
		// ...
		
		int right = i;
		// wrap if we hit last Philosopher
		int left = (i+1) % numPhilosophers;
		philoThreads.push_back(std::thread(PhilosopherWorkThread, &diningManager, i, sleepTimes[i]));
	}
	
	for (auto& thread : philoThreads)
	{
		thread.join();
	}
	 
	ThreadSafePrint(std::ostringstream() << std::endl << "Dinner is over!" << std::endl);

	// WINDOWS ONLY!
	system("pause");

	return 0;
}