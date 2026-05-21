#pragma once
/*
 * Game Board
 * Created 5/20/2026
 */

// INCLUDES -----
#include <cstdint>
#include <optional>
#include <iostream>
// ----- INCLUDES

/*
 * Game board tile state
 *
 * None - No player has claimed this tile
 * Cross - The X player has claimed this tile
 * Circle - The O Plater has claimed this tile
 */
enum class TileState {
    None   = 0b000,
    Cross  = 0b010, // Synced with Player
    Circle = 0b011,
};

/*
 * Game Board
 *
 * Stores and manages board operations
 */
class Board {
public:
    Board(uint8_t customSize = 3);
    ~Board();

    std::optional<TileState> getTile(uint8_t x, uint8_t y) const;
    std::optional<TileState*> getTile(uint8_t x, uint8_t y);

    /*
     * Sets all tiles to None
     */
    void resetBoard();

    /*
     * Renders the board to a ostream
     */
    void render(std::ostream &target) const;

private:
    TileState **m_Grid;
    const uint8_t m_Size;
};
