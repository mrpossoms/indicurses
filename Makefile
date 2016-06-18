NAME=indicurses
CFLAGS += -Wint-to-pointer-cast -std=gnu99
SRC=./src/*.c
INC=include
DST=./lib
LINK=-string -lncurses -lm
LIB=libindicurses.a
INSTALL_PREFIX ?= /usr/local

TSTINC=./tests/include
TST=./tests
TSTS=./tests/*.c

all:
	$(CC) $(CFLAGS) $(CPPFLAGS) -I./$(INC) -c $(SRC)
	$(AR) rcs $(DST)/$(LIB) *.o
	rm *.o
	mkdir -p $(DST)/include
	cat /dev/null >| $(DST)/include/$(NAME).h
	find ./$(INC) -name "*.h" -exec cat {} > $(DST)/include/$(NAME).h \;

testlib: $(SRC)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(TSTINC) -c $(SRC)
	$(AR) rcs $(TST)/lib/$(LIB) *.o
	rm *.o

tests: testlib
	$(foreach test, $(TSTS), $(CC) $(CFLAGS) $(CPPFLAGS) $(test) -o $(TST)/bin/$(test).bin

install:
	@echo 'Installing the library'
	cp $(DST)/include/*.h $(INSTALL_PREFIX)/include
	cp $(DST)/*.a $(INSTALL_PREFIX)/lib
clean:
	find ./ -iname "*.a" -exec rm {} \;
	find ./ -iname "*.o" -exec rm {} \;
	find ./ -iname "*.out" -exec rm {} \;
