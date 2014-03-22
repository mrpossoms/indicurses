FLAGS=-Wint-to-pointer-cast
SRC=./src/*.c
INC=./../include
LIB=./../lib/libindicurses.a
LINK= -lm -lncurses

all:
	find ./ -iname "*.c" -exec gcc {} $(LIB) -I$(INC) $(LINK) -o {}.bin \;

clean:
	rm *.bin