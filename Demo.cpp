/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include <iostream>

using ariel::Direction;
using namespace std;

int main() {
    cout << " ------------- Erel's example ------------- " << endl;
	ariel::Board board;
	board.post(100,200, Direction::Horizontal, "abcd");
	cout << board.read(99, 201, Direction::Vertical, 3) << endl;
		// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	board.post(99, 202, Direction::Vertical, "xyz");
	cout << board.read(100, 200, Direction::Horizontal, 6) << endl;
		// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).

	board.show(); // shows the board in a reasonable way. For example:
		//    98:  _________
		//    99:  ____x____
		//    100: __abyd___
		//    101: ____z____
		//    102: _________

		cout << endl << endl;

    cout << " ------------- First example ------------- " << endl << endl;
    ariel::Board messageBoard_A;

    cout << " ------------- Post empty message - doesn't show nothing ------------- " << endl << endl;
    messageBoard_A.post(100, 200, Direction::Horizontal, "");
    messageBoard_A.post(100, 200, Direction::Vertical, "");
    cout << endl;
    messageBoard_A.show();

    cout << " ------------- 1 message - spaces ------------- " << endl << endl;
    messageBoard_A.post(100, 200, Direction::Horizontal, " ");
    messageBoard_A.post(100, 200, Direction::Vertical, " ");
    messageBoard_A.show();
    cout << endl;

    cout << " ------------- 2 message ------------- " << endl << endl;
    messageBoard_A.post(100, 200, Direction::Horizontal, "Apartment for sale");
    messageBoard_A.show();
    cout << endl;

    cout << " ------------- 3 message ------------- " << endl << endl;
    messageBoard_A.post(100, 200, Direction::Vertical, "Apartment for sale");
    messageBoard_A.show();
    cout << endl;

    cout << " ------------- 4 message ------------- " << endl << endl;
    messageBoard_A.post(100, 200, Direction::Horizontal, "Apartment for rent");
    messageBoard_A.show();
    cout << endl;

    cout << " ------------- 5 message ------------- " << endl << endl;
    messageBoard_A.post(100, 200, Direction::Vertical, "Apartment for rent");
    messageBoard_A.show();
    cout << endl;

    cout << " ------------- 6 message ------------- " << endl << endl;
    messageBoard_A.post(100, 202, Direction::Vertical, "babysitter");
    messageBoard_A.show();
    cout << endl;

    cout << " ------------- 7 message ------------- " << endl << endl;
    messageBoard_A.post(105, 200, Direction::Horizontal, "English teacher");
    messageBoard_A.show();
    cout << endl;

    cout << " ------------- Second example ------------- " << endl << endl;
    ariel::Board messageBoard_B;

    cout << " ------------- 1 message ------------- " << endl << endl;
    messageBoard_B.post(0, 0, Direction::Horizontal, "Tenants meeting at 6 p.m.");
    messageBoard_B.show();
    cout << endl;

    cout << " ------------- 2 message ------------- " << endl << endl;
    messageBoard_B.post(0, 0, Direction::Vertical, "Call for more details");
    messageBoard_B.show();
    cout << endl;

    cout << " ------------- Third example ------------- " << endl << endl;
    ariel::Board messageBoard_C;

    cout << " ------------- 1 message ------------- " << endl << endl;
    messageBoard_C.post(UINT_MAX, UINT_MAX - 20, Direction::Horizontal, "Call for more details");
    messageBoard_C.show();
    cout << endl;

    cout << " ------------- 2 message ------------- " << endl << endl;
    messageBoard_C.post(UINT_MAX - 25, UINT_MAX, Direction::Vertical, "Tenants meeting at 6 p.m.");
    messageBoard_C.show();
    cout << endl;

    cout << " ------------- Fourth example - Big message board ------------- " << endl << endl;
    ariel::Board messageBoard_D;

    messageBoard_D.post(10000, 10200, Direction::Horizontal, "Call for more details");
    messageBoard_D.post(10009, 10150, Direction::Vertical, "Tenants meeting at 6 p.m.");
    messageBoard_D.post(10002, 10100, Direction::Horizontal, "English teacher");
    messageBoard_D.post(10010, 10110, Direction::Vertical, "babysitter");
    messageBoard_D.post(10008, 10130, Direction::Horizontal, "Apartment for rent");
    messageBoard_D.post(10008, 10140, Direction::Vertical, "Apartment for sale");
    messageBoard_D.show();
}

