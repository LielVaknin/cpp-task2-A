#include "doctest.h"
#include "Board.hpp"
#include <climits>

using namespace ariel;
using namespace std;

TEST_CASE ("Test read before post any message") {
    Board messageBoard;
            CHECK(messageBoard.read(100, 200, Direction::Horizontal, 0) == "");
            CHECK(messageBoard.read(100, 200, Direction::Vertical, 0) == "");
            CHECK(messageBoard.read(100, 200, Direction::Horizontal, 1) == "_");
            CHECK(messageBoard.read(100, 200, Direction::Vertical, 1) == "_");
            CHECK(messageBoard.read(100, 200, Direction::Horizontal, 10) == "__________");
            CHECK(messageBoard.read(100, 200, Direction::Vertical, 10) == "__________");
}

TEST_CASE ("Test spaces and empty messages") {
    Board messageBoard;
    messageBoard.post(100, 200, Direction::Horizontal, "");
            CHECK(messageBoard.read(100, 200, Direction::Horizontal, 1) == "_");
    messageBoard.post(100, 200, Direction::Vertical, "");
            CHECK(messageBoard.read(100, 200, Direction::Vertical, 1) == "_");

    messageBoard.post(100, 200, Direction::Horizontal, " ");
            CHECK(messageBoard.read(100, 200, Direction::Horizontal, 1) == " ");
    messageBoard.post(100, 200, Direction::Vertical, " ");
            CHECK(messageBoard.read(100, 200, Direction::Vertical, 1) == " ");

    messageBoard.post(100, 200, Direction::Horizontal, "Apartment for sale");
            CHECK(messageBoard.read(100, 200, Direction::Horizontal, 18) != "Apartment_for_sale");
            CHECK(messageBoard.read(100, 200, Direction::Horizontal, 18) == "Apartment for sale");

    messageBoard.post(100, 200, Direction::Vertical, "Apartment for sale");
            CHECK(messageBoard.read(100, 200, Direction::Vertical, 18) != "Apartment_for_sale");
            CHECK(messageBoard.read(100, 200, Direction::Vertical, 18) == "Apartment for sale");
}

TEST_CASE ("Test for post and read") {
    Board messageBoard;
    messageBoard.post(100, 200, Direction::Horizontal, "Apartment for sale");
            CHECK(messageBoard.read(100, 200, Direction::Horizontal, 18) == "Apartment for sale");
    messageBoard.post(100, 200, Direction::Horizontal, "Apartment for rent");
            CHECK(messageBoard.read(100, 200, Direction::Horizontal, 18) == "Apartment for rent");

    messageBoard.post(100, 200, Direction::Vertical, "Apartment for sale");
            CHECK(messageBoard.read(100, 200, Direction::Vertical, 18) == "Apartment for sale");
    messageBoard.post(100, 200, Direction::Vertical, "Apartment for rent");
            CHECK(messageBoard.read(100, 200, Direction::Vertical, 18) == "Apartment for rent");

    messageBoard.post(100, 202, Direction::Vertical, "babysitter");
            CHECK(messageBoard.read(100, 202, Direction::Vertical, 10) == "babysitter");
            CHECK(messageBoard.read(100, 200, Direction::Horizontal, 18) == "Apbrtment for rent");

    messageBoard.post(105, 200, Direction::Horizontal, "English teacher");
            CHECK(messageBoard.read(105, 200, Direction::Horizontal, 15) == "English teacher");
            CHECK(messageBoard.read(100, 200, Direction::Vertical, 18) == "ApartEent for rent");
            CHECK(messageBoard.read(100, 202, Direction::Vertical, 10) == "babysgtter");
}

TEST_CASE ("Test for messageBoard size") {
    Board messageBoard;
    messageBoard.post(0, 0, Direction::Horizontal, "Tenants meeting at 6 p.m.");
            CHECK(messageBoard.read(0, 0, Direction::Horizontal, 25) == "Tenants meeting at 6 p.m.");
    messageBoard.post(0, 0, Direction::Vertical, "Tenants meeting at 6 p.m.");
            CHECK(messageBoard.read(0, 0, Direction::Vertical, 25) == "Tenants meeting at 6 p.m.");

    messageBoard.post(UINT_MAX, UINT_MAX - 20, Direction::Horizontal, "Call for more details");
            CHECK(messageBoard.read(UINT_MAX, UINT_MAX - 20, Direction::Horizontal, 21) == "Call for more details");
    messageBoard.post(UINT_MAX - 20, UINT_MAX - 20, Direction::Vertical, "Call for more details");
            CHECK(messageBoard.read(UINT_MAX - 20, UINT_MAX - 20, Direction::Vertical, 21) == "Call for more details");
}