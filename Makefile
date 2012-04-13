SRC := src/driver.cpp src/gui.cpp
INC := ./headers/
NAME := ClassCatcher
CC := g++
FLAGS := -Wall -g
PKG := `pkg-config gtkmm-3.0 --cflags --libs`

main:
	${CC} ${FLAGS} ${SRC} -I${INC} -o ${NAME} ${PKG}

clean:
	rm -f */*~ *~
