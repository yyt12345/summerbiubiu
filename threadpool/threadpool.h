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
	int counter;//已有线程数
	int idle;//空闲线程数
	int Max_threads;//最大可容纳线程数
	task_t* first;
	task_t* last;	
	std::vector<std::thread> workers;//线程

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

