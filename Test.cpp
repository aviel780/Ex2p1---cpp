#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
#include <string>
using namespace std;


TEST_CASE("Good input"){
    ariel::Notebook nbook;
    nbook.write(1, 3, 3, ariel::Direction::Horizontal, "aviel");
    CHECK(nbook.read(1, 3, 3, ariel::Direction::Horizontal, 5) == "aviel");
    nbook.erase(1, 3, 3,ariel::Direction::Horizontal,5);
    CHECK(nbook.read(1, 3, 3, ariel::Direction::Horizontal, 5) == "~~~~~");

    nbook.write(5,7,7,ariel::Direction::Vertical, "edri");
    CHECK(nbook.read(5,7,7, ariel::Direction::Vertical, 5) == "edri");
    nbook.erase(5,7,7,ariel::Direction::Vertical,5);
    CHECK(nbook.read(5,7,7, ariel::Direction::Vertical, 5) == "~~~~~");

    ariel::Notebook nbook2;
    nbook2.write(3,4,4,ariel::Direction::Vertical, "hello world");
    CHECK(nbook2.read(3,4,4, ariel::Direction::Vertical, 11) == "hello world");
    nbook2.erase(3,4,4,ariel::Direction::Vertical,11);
    CHECK(nbook2.read(3,4,4, ariel::Direction::Vertical, 11) == "~~~~~~~~~~~");

    nbook2.write(4, 5, 5, ariel::Direction::Horizontal, "cpp");
    CHECK(nbook2.read(4, 5, 5, ariel::Direction::Horizontal, 3) == "cpp");
    nbook2.erase(4,5,5,ariel::Direction::Horizontal,3);
    CHECK(nbook2.read(4, 5, 5, ariel::Direction::Horizontal, 3) == "~~~");

    ariel::Notebook nbook3;

    nbook3.write(5,50,500,ariel::Direction::Vertical, "ariel");
    CHECK(nbook3.read(5,50,500, ariel::Direction::Vertical, 5) == "ariel");
    nbook3.erase(5,50,500,ariel::Direction::Vertical,5);
    CHECK(nbook3.read(5,50,500, ariel::Direction::Vertical, 5) == "~~~~~");

    nbook3.write(1,10,100,ariel::Direction::Vertical, "ariel universitiy");
    CHECK(nbook3.read(1,10,100, ariel::Direction::Vertical, 17) == "ariel universitiy");
    nbook3.erase(1,10,100,ariel::Direction::Vertical,17);
    CHECK(nbook3.read(1,10,100, ariel::Direction::Vertical, 17) == "~~~~~");

}

TEST_CASE("Bad input"){
    ariel::Notebook nbook;
    nbook.write(1, 0, 0, ariel::Direction::Horizontal, "aviel");
    CHECK_THROWS(nbook.write(1,0,0,ariel::Direction::Horizontal, "avie"));
    nbook.erase(1, 0, 0, ariel::Direction::Horizontal, 4);
    CHECK_THROWS(nbook.write(1,0,0,ariel::Direction::Horizontal, "avie"));

    CHECK_THROWS(nbook.erase(2,0,0,ariel::Direction::Horizontal, 4));

    nbook.erase(1,0,0,ariel::Direction::Horizontal, 4);
    CHECK_THROWS(nbook.erase(1,0,0,ariel::Direction::Horizontal, 4));

    ariel::Notebook nbook2;
    CHECK_THROWS(nbook2.write(2,0,99,ariel::Direction::Horizontal, "aviel"));

    CHECK_THROWS(nbook2.read(3,0,99,ariel::Direction::Horizontal, 5));

    nbook2.write(5,0,0,ariel::Direction::Horizontal, "edri");
    CHECK_THROWS(nbook2.write(5,0,0,ariel::Direction::Vertical, "edri"));

    CHECK_THROWS(nbook2.write(6,0,101,ariel::Direction::Horizontal, "ariel"));

    ariel::Notebook nbook3;
    nbook3.write(7,1,0,ariel::Direction::Horizontal, "aviel");
    CHECK_THROWS(nbook3.write(7,0,0,ariel::Direction::Vertical, "ariel"));

    nbook3.write(8,0,0,ariel::Direction::Horizontal, "cs");
    CHECK_THROWS(nbook3.write(8,0,3, ariel::Direction::Vertical, "ariel"));

    CHECK_THROWS(nbook3.read(9,0,101, ariel::Direction::Horizontal, 5));
    
    CHECK_THROWS(nbook3.read(1,0,0,ariel::Direction::Horizontal,-1));
}

TEST_CASE("negtiv number"){
    ariel::Notebook nbook;
    CHECK_THROWS(nbook.write(-1,0,0,ariel::Direction::Horizontal,"ariel"));
    CHECK_THROWS(nbook.write(1,-1,0,ariel::Direction::Horizontal,"ariel"));
    CHECK_THROWS(nbook.write(1,0,-1,ariel::Direction::Horizontal,"ariel"));
}