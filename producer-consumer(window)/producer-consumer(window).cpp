#include<iostream>
#include<windows.h>
using namespace std;
HANDLE hmutex;
CRITICAL_SECTION cs;
CONDITION_VARIABLE cv;
const int ThreadCount = 20, Producercount = 10, Consumercount = 10;
int buffer = 0;
DWORD WINAPI Producer(void* no)
{
	EnterCriticalSection(&cs);
	while (buffer == 10)
	{
		SleepConditionVariableCS(&cv, &cs, INFINITE);
		// ReleaseMutex(hmutex);
	}
	buffer++;
	cout << "PRODUCER " << no << " PRODUCED " << buffer << endl;
	Sleep(2000);
	LeaveCriticalSection(&cs);
	WakeConditionVariable(&cv);
	return 0;
}
DWORD WINAPI Consumer(void* no)
{
	// WaitForSingleObject(hmutex, INFINITE);
	EnterCriticalSection(&cs);
	while (buffer == 0)
	{
		SleepConditionVariableCS(&cv, &cs, INFINITE);
		//ReleaseMutex(hmutex);
	}
	buffer--;
	cout << "Consumer " << no << " CONSUMED " << buffer << endl;
	Sleep(2000);
	LeaveCriticalSection(&cs);
	WakeConditionVariable(&cv);
	//ReleaseMutex(hmutex);
	return 0;
}
int main()
{
	HANDLE threads[ThreadCount];
	InitializeCriticalSection(&cs);
	InitializeConditionVariable(&cv);
	DWORD threadid;
	for (int i = 0; i < Producercount; i++)
	{
		threads[i] = CreateThread(NULL, 0, &Producer, (void*)i, 0, &threadid);
	}
	for (int j = 10, i = 0; i < Producercount; j++, i++)
	{
		threads[j] = CreateThread(NULL, 0, &Consumer, (void*)i, 0, &threadid);
	}
	WakeAllConditionVariable(&cv);
	WaitForMultipleObjects(20, threads, TRUE, INFINITE);
	for (int i = 0; i < ThreadCount; i++)
	{
		CloseHandle(threads[i]);
	}
}