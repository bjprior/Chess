OBJ = ChessMain.o Chessboard.o base.o pawn.o rook.o bishop.o knight.o queen.o king.o helper.o

EXE = chess

$(EXE): $(OBJ)
	g++ $^ -o $@

%.o: %.cpp Makefile
	g++ -Wall -g -c $<

ChessMain.o: Chessboard.hpp

Chessboard.o: Chessboard.hpp base.hpp pawn.hpp rook.hpp bishop.hpp knight.hpp queen.hpp king.hpp helper.hpp

base.o: base.hpp 

pawn.o: pawn.hpp base.hpp Chessboard.hpp

bishop.o: bishop.hpp base.hpp Chessboard.hpp

knight.o: knight.hpp base.hpp Chessboard.hpp

queen.o: queen.hpp base.hpp Chessboard.hpp

king.o: king.hpp base.hpp Chessboard.hpp

clean:
	rm -f $(OBJ) chess *.o
