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
//�����̵߳�ִ��
//void threadpool::thread_rountine(void* arg) {
//	while (true) {
//		//lock�������ڽ������Զ�����
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
//			//ִ������
//			t->run(t->arg);
//			free(t);
//			queue_mutex.lock();
//		}
//		//�˳��̳߳�
//		if (this->quit && this->first == NULL) {
//			this->counter--;
//			if (this->counter == 0)
//				condition.notify_one();
//			break;//�Զ�����
//		}
//	}
//	std::cout << "Thread " << this_thread::get_id() << " is exiting" << endl;
//	return ;
//}
//void threadpool::threadpool_add_task(void* (*run)(void* arg), void* arg) {
//	task_t* newtask = (task_t*)malloc(sizeof(task_t));
//	newtask->run = run;
//	newtask->arg = arg;
//	newtask->next = NULL;//���������β���������
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
//	//�Զ�����
//	return;
//}

void* threadpool::thread_rountine() {
	while (true) {
		//lock�������ڽ������Զ�����
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
			//ִ������
			t->run();
			free(t);
			queue_mutex.lock();
		}
		//�˳��̳߳�
		if (this->quit && this->first == NULL) {
			this->counter--;
			if (this->counter == 0)
				condition.notify_one();
			break;//�Զ�����
		}
	}
	std::cout << "Thread " << this_thread::get_id() << " is exiting" << endl;
	return NULL;
}
void threadpool::threadpool_add_task(void* (*run)()) {
	task_t* newtask = (task_t*)malloc(sizeof(task_t));
	newtask->run = run;
	newtask->next = NULL;//���������β���������

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
	//�Զ�����
	return;
}

threadpool::~threadpool() {
	if (this->quit)
		return;
	unique_lock<mutex> lock(queue_mutex);
	this->quit = true;
	if (this->counter > 0) {
		//�������ڵȴ����̣߳����ͻ�������
		if (this->idle > 0)
			condition.notify_all();
		
	}
	for (thread& worker : workers)
		worker.join();
}