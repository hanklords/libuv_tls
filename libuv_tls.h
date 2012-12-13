#ifndef __LIBUV_TLS_H__
#define __LIBUV_TLS_H__

#ifdef _WIN32
#include <windows.h>
typedef DWORD uv_thread_key_t;
# else
typedef pthread_key_t uv_thread_key_t;
#endif

int uv_thread_key_create(uv_thread_key_t *key);
int pthread_key_delete(uv_thread_key_t key);
void *uv_thread_getspecific(uv_thread_key_t key);
int uv_thread_setspecific(uv_thread_key_t key, void *data);

#endif

