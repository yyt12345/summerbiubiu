#include <iostream>
#include "threadpool.h"
using namespace std;
int i = 0;
void* print() {
    while (i < 100) {
        cout << "A:  Thread " << this_thread::get_id() << " is working: " << i++ << endl;
    }
    return NULL;
}
void helloworld() {
    return;
}

int main()
{
    threadpool pool(3);
    thread t1(helloworld);

    int* arg = new int;
    for (int i = 1; i < 5; i++) {
        *arg = i;
        pool.threadpool_add_task(print);
    }

    pool.~threadpool();
    return 0;

}


