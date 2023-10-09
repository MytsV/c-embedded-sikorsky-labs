name := list
sources := $(wildcard src/*.c) main.c
in := books.in
cflags := -Wall -Wextra -Werror

$(name): $(sources) $(in)
	gcc $(cflags) -o $(name) $(sources)

run: $(name)
	./$(name) $(in) > run.txt