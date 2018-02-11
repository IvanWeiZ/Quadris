CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = quadris
OBJECTS = main.o window.o cell.o board.o textDisplay.o nextBlock.o block.o blockI.o blockJ.o blockL.o blockT.o blockS.o blockZ.o blockO.o vector.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
