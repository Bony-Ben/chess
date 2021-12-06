VPATH=pieces players display moves

CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD
EXEC = chess
OBJECTS = main.o piece.o board.o subject.o textobserver.o graphicsobserver.o window.o move.o game.o human.o level1.o rook.o knight.o bishop.o queen.o king.o pawn.o
#add graphicsobserver.o window.o for graphic display
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -L/opt/X11/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
