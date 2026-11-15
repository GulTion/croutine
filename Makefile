all: main
	./main

croutine.o: croutine.fasm
	fasm croutine.fasm croutine.o

main: main.c croutine.o
	gcc -g -no-pie -z noexecstack main.c croutine.o -o main

FN ?= main

d: main
	/home/gultion/Documents/gf/gf2 ./main -ex "break $(FN)" -ex "run"

gdb: main
	gdb ./main \
		-ex 'gef config context.layout "regs stack code"' \
		-ex "gef config dereference.max_recursion 1" \
		-ex 'gef config context.ignore_registers "$$cs $$ss $$ds $$es $$fs $$gs"' \
		-ex "gef config context.nb_lines_stack 4" \
		-ex "break $(FN)" -ex "run"

clean:
	rm -f main croutine.o
