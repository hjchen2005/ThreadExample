// translation of pthread example (https://en.wikipedia.org/wiki/POSIX_Threads) to C++
// Have to enable C++ 2011
    // in COde::Blocks: Project -> Build options
#include <iostream>
#include <thread>
#include <cstdlib>
#include <cassert>

using namespace std;

#define NUM_THREADS 5

void *perform_work(void *argument) {
   int passed_in_value;

   passed_in_value = *((int *) argument);
   cout << "Hello World! It's me, thread with argument %d!\n" << passed_in_value<< endl;

   /* optionally: insert more useful stuff here */

   return NULL;
}

int main(int argc, char* argv[]){
    thread threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int result_code, index;

   for (index = 0; index < NUM_THREADS; ++index) {
      // block until thread 'index' completes
      threads[index].join();
      cout <<"In main: thread %d has completed\n"<< index<<endl;
      //assert(0 == result_code);
   }
   cout<<"In main: All threads completed successfully\n";
   exit(EXIT_SUCCESS);
}
