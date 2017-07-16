CFLAGS=-Wall -Wextra -Werror
CC=clang

3: 3.c
	$(CC) $(CFLAGS) -o $@ $@.c -lm $(shell pkg-config --cflags --libs glib-2.0)
