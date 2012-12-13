#include <windows.h> 
#include "libuv_tls.h"

int uv_thread_key_create(uv_thread_key_t *key) {
  *key = TlsAlloc();
  
  return *key == TLS_OUT_OF_INDEXES ? -1 : 0;
}

int uv_thread_key_delete(uv_thread_key_t key) {
  BOOL r;

  r = TlsFree(key);

  return r ? 0 : -1;
}

void *uv_thread_getspecific(uv_thread_key_t key) {
  return TlsGetValue(key);
}

int uv_thread_setspecific(uv_thread_key_t key, void *data) {
  BOOL r;

  r = TlsSetValue(key, data);

  return r ? 0 : -1;
}
