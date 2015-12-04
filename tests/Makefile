FLAGS=-Wint-to-pointer-cast
SRC=./src/*.c
INC=./../include
LIB=-L./../lib/
LINK= -lm -lncurses -lindicurses

all:
	find ./ -iname "*.c" -exec gcc {} $(LIB) -I$(INC) $(LINK) -o {}.bin \;

clean:
	rm *.bin