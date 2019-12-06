OBJ = ChessMain.o Chessboard.o base.o pawn.o rook.o bishop.o knight.o queen.o king.o helper.o

EXE = chess

$(EXE): $(OBJ)
	g++ $^ -o $@

%.o: %.cpp Makefile
	g++ -Wall -g -c $<

ChessMain.o: Chessboard.hpp

Chessboard.o: Chessboard.hpp base.hpp pawn.hpp rook.hpp bishop.hpp knight.hpp queen.hpp king.hpp helper.hpp errors.hpp

base.o: base.hpp 

pawn.o: pawn.hpp base.hpp Chessboard.hpp errors.hpp

bishop.o: bishop.hpp base.hpp Chessboard.hpp errors.hpp

knight.o: knight.hpp base.hpp Chessboard.hpp errors.hpp

queen.o: queen.hpp base.hpp Chessboard.hpp errors.hpp

king.o: king.hpp base.hpp Chessboard.hpp errors.hpp

clean:
	rm -f $(OBJ) chess *.o
