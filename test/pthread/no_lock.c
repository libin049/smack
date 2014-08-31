#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int x = 1;

void *t1(void *arg) {
  x++;
}

int main() {
  __SMACK_code("assume (forall i:int :: $pthreadStatus[i][0] == $pthread_uninitialized);"); 

  pthread_t t;

  pthread_create(&t, NULL, t1, NULL);
  x++;
  pthread_join(t, NULL);
  __SMACK_assert(x == 3);
  

}
