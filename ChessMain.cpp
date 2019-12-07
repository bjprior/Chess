#include"Chessboard.hpp"

#include<iostream>

using namespace std;

int main() {

	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";
	
	ChessBoard cb;
	cout << '\n';
	
	cb.submitMove("D7", "D6");
	cout << '\n';
	
	cb.submitMove("D4", "H6");
	cout << '\n';
	
	cb.submitMove("D2", "D4");
	cout << '\n';
	
	cb.submitMove("F8", "B4");
	cout << '\n';
	
	/// EXTRA MOVES
	cb.submitMove("A7", "A5");
	cout << '\n';

	cb.submitMove("D4", "D5");
	cout << '\n';

	cb.submitMove("A5", "A4");
	cout << '\n';
	
	cb.submitMove("D5", "D6");
	cout << '\n';

	cb.submitMove("E7", "D6");
	cout << '\n';
	
	cb.submitMove("A2", "A4");
	cout << '\n';

	cb.submitMove("A5", "G5");
	cout << '\n';

	cb.submitMove("G2", "G4");
	cout << '\n';

	cb.submitMove("B8", "B7");
	cout << '\n';

	cb.submitMove("B8", "A6");
	cout << '\n';

	cb.submitMove("E1", "E2");
	cout << '\n';

	cb.submitMove("E1", "D2");
	cout << '\n';

	cb.submitMove("A6", "B4");
	cout << '\n';

	cb.submitMove("D2", "D3");
	cout << '\n';

	cb.submitMove("B7", "B7");
	cout << '\n';

	cb.submitMove("D7", "D5");
	cout << '\n';

	cb.submitMove("D1", "D2");
	cout << '\n';

	cb.submitMove("D8", "D6");
	cout << '\n';

	cb.submitMove("D2", "G5");
	cout << '\n';

	cb.submitMove("D6", "H2");
	cout << '\n';

	cb.submitMove("G5", "G1");
	cout << '\n';

	cb.submitMove("G5", "G4");
	cout << '\n';

	cb.submitMove("G5", "B5");
	cout << '\n';
	

	
	cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";
	
	cb.resetBoard();
	cout << '\n';
       
	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E6");
	cout << '\n';
	
	cb.submitMove("D2", "D4");
	cb.submitMove("D7", "D5");
	cout << '\n';

	cb.submitMove("B1", "C3");
	cb.submitMove("F8", "B4");
	cout << '\n';

	cb.submitMove("F1", "D3");
	cb.submitMove("B4", "C3");
	cout << '\n';

	cb.submitMove("B2", "C3");
	cb.submitMove("H7", "H6");
	cout << '\n';

	cb.submitMove("C1", "A3");
	cb.submitMove("B8", "D7");
	cout << '\n';

	cb.submitMove("D1", "E2");
	cb.submitMove("D5", "E4");
	cout << '\n';

	cb.submitMove("D3", "E4");
	cb.submitMove("G8", "F6");
	cout << '\n';

	cb.submitMove("E4", "D3");
	cb.submitMove("B7", "B6");
	cout << '\n';

	cb.submitMove("E2", "E6");
	
	cb.submitMove("F7", "E6");
	cout << '\n';
	
	cb.submitMove("D3", "G6");
	cout << '\n';
	
	cout << "==========Additonal Tests ================";
	cout << endl << endl;

	cb.resetBoard();
	cout << endl;
	
	cb.submitMove("E2", "E3");
	cout << endl;

	cb.submitMove("A7", "A5");
	cout << endl;

	cb.submitMove("D1", "H5");
	cout << endl;

	cb.submitMove("A8", "A6");
	cout << endl;

	cb.submitMove("H5", "A5");
	cout << endl;

	cb.submitMove("H7", "H5");
	cout << endl;

	cb.submitMove("H2", "H4");
	cout << endl;

	cb.submitMove("A6", "H6");
	cout << endl;

	cb.submitMove("A5", "C7");
	cout << endl;

	cb.submitMove("F7", "F6");
	cout << endl;

	cb.submitMove("C7", "D7");
	cout << endl;

	cb.submitMove("E8", "F7");
	cout << endl;

	cb.submitMove("D7", "B7");
	cout << endl;

	cb.submitMove("D8", "D3");
	cout << endl;

	cb.submitMove("B7", "B8");
	cout << endl;

	cb.submitMove("D3", "H7");
	cout << endl;

	cb.submitMove("B8", "C8");
	cout << endl;

	cb.submitMove("F7", "G6");
	cout << endl;

	cb.submitMove("C8", "E6");
	cout << endl;
	
	return 0;
}
