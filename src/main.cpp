#include <iostream>

// INCLUDES -----
#include "board.hpp"

int
main() {
    Board brd{};

    *brd.getTile(0, 0).value() = TileState::Circle;

    brd.render(std::cout);
    return 0;
}