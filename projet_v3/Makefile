CC = clang
CFLAGS =-std=c17 -pedantic -Wall
LDFLAGS = -lMLV -lm
OBJ = tab_point.o graph.o algo.o test.o option.o liste.o tab_point.o convexe.o main.o
EXE = convexe
REG = src/

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	
main.o: $(REG)main.c $(REG)test.h $(REG)option.h

test.o : $(REG)test.c $(REG)test.h $(REG)liste.h $(REG)option.h $(REG)algo.h $(REG)tab_point.h

option.o: $(REG)option.c $(REG)option.h $(REG)algo.h

algo.o: $(REG)algo.c $(REG)algo.h $(REG)graph.h

graph.o: $(REG)graph.c $(REG)graph.h $(REG)tab_point.h $(REG)convexe.h

tab_point.o: $(REG)tab_point.c $(REG)tab_point.h $(REG)convexe.h

convexe.o:$(REG)convexe.c $(REG)convexe.h $(REG)liste.h

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
