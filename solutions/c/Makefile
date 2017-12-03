CFLAGS=-Wall -Wextra -Werror
CC=clang

3: 3.c
	$(CC) $(CFLAGS) -o $@ $< -lm $(shell pkg-config --cflags --libs glib-2.0)

5: 5.c
	$(CC) $(CFLAGS) -o $@ $< -lm

7: 7.c primes.h
	$(CC) $(CFLAGS) -o $@ $< -lm $(shell pkg-config --cflags --libs glib-2.0)

10: 10.c primes.h
	$(CC) $(CFLAGS) -o $@ $< $(shell pkg-config --cflags --libs glib-2.0)

11: 11.c
	$(CC) $(CFLAGS) -o $@ $< -lm

16: 16.c convert.h
	$(CC) $(CFLAGS) -o $@ $< -lgmp

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
