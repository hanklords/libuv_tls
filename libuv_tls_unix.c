#include <pthread.h>
#include "libuv_tls.h"

int uv_thread_key_create(uv_thread_key_t *key) {
  return pthread_key_create(key, NULL) ? -1 : 0;
}

int uv_thread_key_delete(uv_thread_key_t key) {
  return pthread_key_delete(key) ? -1 : 0;
}

void *uv_thread_getspecific(uv_thread_key_t key) {
  return pthread_getspecific(key);
}

int uv_thread_setspecific(uv_thread_key_t key, void *data) {
  return pthread_setspecific(key, data) ? -1 : 0;
}

