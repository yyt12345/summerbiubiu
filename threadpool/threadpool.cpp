#include "threadpool.h"
#include <iostream>
using namespace std;
void threadpool::helloworld() {
	return ;
}
threadpool::threadpool(int threads) :Max_threads(threads), counter(0), idle(0), quit(false) {
	this->first = NULL;
	this->last = NULL;
}
//创建线程的执行
//void threadpool::thread_rountine(void* arg) {
//	while (true) {
//		//lock生命周期结束后自动解锁
//		std::cout << "Thread " << this_thread::get_id() << " is starting" << endl;
//		unique_lock<mutex> lock(this->queue_mutex);
//		this->idle++;
//		std::cout << "Thread " << this_thread::get_id() << " is waiting" << endl;
//		this->condition.wait(lock, [this] {return this->first != NULL || this->quit; });
//		this->idle--;
//		if (this->first != NULL) {
//			task_t* t = this->first;
//			this->first = t->next;
//			queue_mutex.unlock();
//			//执行任务
//			t->run(t->arg);
//			free(t);
//			queue_mutex.lock();
//		}
//		//退出线程池
//		if (this->quit && this->first == NULL) {
//			this->counter--;
//			if (this->counter == 0)
//				condition.notify_one();
//			break;//自动解锁
//		}
//	}
//	std::cout << "Thread " << this_thread::get_id() << " is exiting" << endl;
//	return ;
//}
//void threadpool::threadpool_add_task(void* (*run)(void* arg), void* arg) {
//	task_t* newtask = (task_t*)malloc(sizeof(task_t));
//	newtask->run = run;
//	newtask->arg = arg;
//	newtask->next = NULL;//在任务队列尾端添加任务
//
//	unique_lock<mutex> lock(this->queue_mutex);
//	if (this->first == NULL)
//		this->first = newtask;
//	else
//		this->last->next = newtask;
//	this->last = newtask;
//
//	if (this->idle > 0)
//		condition.notify_one();
//	else if (this->counter < this->Max_threads) {
//		thread t1(this->thread_rountine);
//		//workers.push_back(t1);
//		this->counter++;
//	}
//	//自动解锁
//	return;
//}

void* threadpool::thread_rountine() {
	while (true) {
		//lock生命周期结束后自动解锁
		std::cout << "Thread " << this_thread::get_id() << " is starting" << endl;
		unique_lock<mutex> lock(this->queue_mutex);
		this->idle++;
		std::cout << "Thread " << this_thread::get_id() << " is waiting" << endl;
		this->condition.wait(lock, [this] {return this->first != NULL || this->quit; });
		this->idle--;
		if (this->first != NULL) {
			task_t* t = this->first;
			this->first = t->next;
			queue_mutex.unlock();
			//执行任务
			t->run();
			free(t);
			queue_mutex.lock();
		}
		//退出线程池
		if (this->quit && this->first == NULL) {
			this->counter--;
			if (this->counter == 0)
				condition.notify_one();
			break;//自动解锁
		}
	}
	std::cout << "Thread " << this_thread::get_id() << " is exiting" << endl;
	return NULL;
}
void threadpool::threadpool_add_task(void* (*run)()) {
	task_t* newtask = (task_t*)malloc(sizeof(task_t));
	newtask->run = run;
	newtask->next = NULL;//在任务队列尾端添加任务

	unique_lock<mutex> lock(this->queue_mutex);
	if (this->first == NULL)
		this->first = newtask;
	else
		this->last->next = newtask;
	this->last = newtask;

	if (this->idle > 0)
		condition.notify_one();
	else if (this->counter < this->Max_threads) {
		thread t1(&threadpool::thread_rountine);
		//workers.push_back(t1);
		this->counter++;
	}
	//自动解锁
	return;
}

threadpool::~threadpool() {
	if (this->quit)
		return;
	unique_lock<mutex> lock(queue_mutex);
	this->quit = true;
	if (this->counter > 0) {
		//对于正在等待的线程，发送唤醒命令
		if (this->idle > 0)
			condition.notify_all();
		
	}
	for (thread& worker : workers)
		worker.join();
}