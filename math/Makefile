name := calc
sources := $(wildcard src/*.c)
main_sources := $(sources) main.c
test_sources := $(sources) test/main.c
cflags := -Wall -Wextra -Werror -lm

cases := test/cases.in

$(name): $(main_sources)
	gcc $(cflags) -o $(name) $(main_sources)

$(name)_test: $(test_sources) $(cases)
	gcc $(cflags) -o $(name)_test $(test_sources)

test: clean $(name)_test
	@(./$(name)_test $(cases) && echo "Pass!" || echo "Fail!")

clean:
	rm -f $(name)_test

fclean: clean
	rm -f $(name)
