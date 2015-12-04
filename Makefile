NAME=indicurses
FLAGS=-Wint-to-pointer-cast
SRC=./src/*.c
INC=./include
DST=./lib
LINK=-string -lncurses -lm
LIB=libindicurses.a

TSTINC=./tests/include
TST=./tests
TSTS=./tests/*.c

all:
	gcc -I$(INC) -c $(SRC)
	ar rcs $(DST)/$(LIB) *.o
	rm *.o
	mkdir -p $(DST)/include
	cat /dev/null >| $(DST)/include/$(NAME).h
	find ./$(INC) -name "*.h" -exec cat {} > $(DST)/include/$(NAME).h \;

testlib: $(SRC)
	gcc -I$(TSTINC) -c $(SRC)
	ar rcs $(TST)/lib/$(LIB) *.o
	rm *.o

tests: testlib
	$(foreach test, $(TSTS), gcc $(test) -o $(TST)/bin/$(test).bin

install:
	echo 'Installing the library'
	cp $(DST)/include/*.h /usr/include
	cp $(DST)/*.a /usr/lib
clean:
	find ./ -iname "*.a" -exec rm {} \;
	find ./ -iname "*.o" -exec rm {} \;
	find ./ -iname "*.out" -exec rm {} \;
