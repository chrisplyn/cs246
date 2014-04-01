CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = main
OBJECTS = main.o block.o Board.o cell.o display.o iblock.o jblock.o lblock.o NextBlock.o NextBlockImpl.o oblock.o sblock.o score.o tblock.o zblock.o trie.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
