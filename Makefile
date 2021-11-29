VPATH=pieces players display

CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD
EXEC = chess
OBJECTS = main.o piece.o board.o subject.o textobserver.o move.o game.o human.o level1.o rook.o knight.o bishop.o queen.o king.o pawn.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
