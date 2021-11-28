VPATH=pieces players display

CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD
EXEC = chess
OBJECTS = main.o board.o subject.o move.o game.o human.o piece.o rook.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
