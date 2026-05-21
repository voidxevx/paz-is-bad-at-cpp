#pragma once
/*
 * Player Controller
 * Created 5/21/2026
 */

#include "board.hpp"
#include <memory>

enum class Player {
    Cross  = 0b010, // synced with TileState
    Circle = 0b011
};

class PlayerController {
public:
    PlayerController(std::shared_ptr<Board> board);

    bool makeMove(uint8_t x, uint8_t y);

private:
    std::shared_ptr<Board> m_Board;
    Player m_CurrentPlayer;
};
