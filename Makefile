CC=gcc
CFLAGS=-I.
DEPS = biblioteca.h livro_service.h livro.h
OBJ = biblioteca.o livro_service.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

biblioteca: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ core *.exe