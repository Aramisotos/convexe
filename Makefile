CC = clang
CFLAGS =-std=c17 -pedantic -Wall
LDFLAGS = -lMLV -lm
OBJ = convexe.o graph.o algo.o test.o option.o liste.o convexe.o main.o
EXE = convexe
REG = src/

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	
main.o: $(REG)main.c $(REG)graph.h $(REG)test.h

convexe.o: $(REG)convexe.c $(REG)convexe.h $(REG)option.h $(REG)algo.h

test.o : $(REG)test.c $(REG)test.h $(REG)liste.h $(REG)option.h $(REG)algo.h $(REG)graph.h $(REG)convexe.h

graph.o: $(REG)graph.c $(REG)graph.h $(REG)convexe.h

algo.o: $(REG)algo.c $(REG)algo.h $(REG)liste.h

option.o: $(REG)option.c $(REG)option.h $(REG)algo.h

liste.o: $(REG)liste.c $(REG)liste.h


%.o: $(REG)%.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXE)

install: $(EXE)
	mkdir bin
	mv $(EXE) bin/$(EXE)
	make mrproper

uninstall: mrproper
	rm -f bin/$(EXE)
	rm -rf bin