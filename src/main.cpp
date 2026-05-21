#include <iostream>
#include <memory>

// INCLUDES -----
#include "board.hpp"
#include "playerController.hpp"

int
main() {
    auto board = std::make_shared<Board>();
    PlayerController controller{board};

    bool res = controller.makeMove(0, 0);
    res |= controller.makeMove(1, 1);

    if (!res)
        std::cout << "failed\n";

    board->render(std::cout);
    return 0;
}
