.PHONY: say_pile generate clean create compile
all: say_pile generate

say_pile:
	@echo "(1, 'g', 1);"
generate:
	@echo "creating file..."
	touch file-{1..10}.txt
clean:
	@echo "Cleaning up..."
	rm *.txt
create:
	@echo "Creating .c"
	vim main.c

compile:
	@cc -Wall -Wextra -Werror *.c | ./a.out
