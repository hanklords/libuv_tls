PROGRAM = uv_tls
CC = gcc
AR = ar
CFLAGS = -g -Wall
LDFLAGS = 

uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
ifneq (,$(findstring MINGW,$(uname_S)))
OBJS = libuv_tls_win32.o
else
OBJS = libuv_tls_unix.o
LDFLAGS += -lpthread
endif

all: lib$(PROGRAM).a

lib$(PROGRAM).a: $(OBJS)
	$(AR) rcs $@ $^

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

clean:
	rm -f $(PROGRAM) lib$(PROGRAM).a $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
