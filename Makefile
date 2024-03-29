VPATH=pieces players display

CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -O3
EXEC = chess
OBJECTS = main.o inputparser.o piece.o board.o subject.o textobserver.o graphicsobserver.o window.o move.o game.o human.o level1.o level2.o level3.o level4.o rook.o knight.o bishop.o queen.o king.o pawn.o
#add graphicsobserver.o window.o for graphic display
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}