CFLAGS=-Wall -Wextra -Werror
CC=clang

3: 3.c
	$(CC) $(CFLAGS) -o $@ $< -lm $(shell pkg-config --cflags --libs glib-2.0)

5: 5.c
	$(CC) $(CFLAGS) -o $@ $< -lm

7: 7.c primes.h
	$(CC) $(CFLAGS) -o $@ $< -lm $(shell pkg-config --cflags --libs glib-2.0)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
