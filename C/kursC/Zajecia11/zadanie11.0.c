#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

char* napis = "Pod haslem Bunt Maszyn rusza druga edycja Into Tech Future. Wydarzenie poswiecone robotyce przyszlosci w biznesie, nauce i kulturze rozpocznie sie 18 stycznia 2022 roku o godz. 17.00.";
pthread_mutex_t mutex_napis = PTHREAD_MUTEX_INITIALIZER;

void *pisz(void * tid){
  int *mojID = (int *) tid;
  pthread_mutex_lock(&mutex_napis);
  printf("%c ID watku %d\n", napis[*mojID], *mojID);
  pthread_mutex_unlock(&mutex_napis);
  pthread_exit(NULL);
}

int main()
{
  int n = strlen(napis);
  pthread_t pthreads[n];
  int indices[n];

  for (int i = 0; i < n; i++){
    indices[i] = i;
    pthread_create(&pthreads[i],NULL, pisz, (void *) &indices[i]);
  }

  for (int i = 0; i < n; i++) {
    pthread_join(pthreads[i], NULL);
  }

  return 0;
}