#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>

typedef struct task {
	void* (*run)();
	//void* (*run)(void* args);
	//void* arg;
	struct task* next;
}task_t;

class threadpool
{
	int counter;//�����߳���
	int idle;//�����߳���
	int Max_threads;//���������߳���
	task_t* first;
	task_t* last;	
	std::vector<std::thread> workers;//�߳�

	std::mutex queue_mutex;
	std::condition_variable condition;

	bool quit;

	//void thread_rountine(void* arg);
	void* thread_rountine();

public:
	void helloworld();
	threadpool(int threads);
	void threadpool_add_task(void* (*run)());
	//void threadpool_add_task(void *(*run)(void *args),void *args);
	~threadpool();
};

