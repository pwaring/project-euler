CFLAGS=-Wall -Wextra -Werror
CC=clang

3: 3.c
	$(CC) $(CFLAGS) -o $@ $< -lm $(shell pkg-config --cflags --libs glib-2.0)

5: 5.c
	$(CC) $(CFLAGS) -o $@ $< -lm

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
