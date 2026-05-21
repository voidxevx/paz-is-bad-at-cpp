#include "playerController.hpp"
#include "board.hpp"
/*
 * Player Controller
 * Created 5/21/2026
 */

PlayerController::PlayerController(
    std::shared_ptr<Board> board
)
    : m_Board(board)
    , m_CurrentPlayer(Player::Cross)
{}

bool
PlayerController::makeMove(
    uint8_t x,
    uint8_t y
) {
    std::optional<TileState*> tile_opt =
        m_Board->getTile(x, y);

    if (!tile_opt.has_value())
        return false;

    TileState *tile = tile_opt.value();
    if (*tile != TileState::None)
        return false;

    *tile = (TileState)m_CurrentPlayer;

    (*(uint8_t*)&m_CurrentPlayer) ^= 0b001;

    return true;
}
