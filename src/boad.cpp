#include "board.hpp"
/*
 * Game Board
 * Created 5/20/2026
 */

Board::Board(uint8_t customSize)
    : m_Size(customSize)
{
    m_Grid = (TileState**)malloc(sizeof(TileState*) * customSize);
    for (uint8_t i{}; i < customSize; ++i)
        m_Grid[i] = (TileState*)malloc(sizeof(TileState) * customSize);

    resetBoard();
}

Board::~Board() {
    for (uint8_t i{}; i < m_Size; ++i)
        free(m_Grid[i]);

    free(m_Grid);
}

void
Board::resetBoard() {
    for (uint8_t x{}; x < m_Size; ++x) for (uint8_t y{}; y < m_Size; ++y) 
        m_Grid[x][y] = TileState::None;
}

inline std::ostream 
&operator<<(std::ostream &target, const TileState &tile) {
    switch (tile) {
    case TileState::None: target << " "; break;
    case TileState::Cross: target << "\x1b[31mX\x1b[0m"; break;
    case TileState::Circle: target << "\x1b[34mO\x1b[0m"; break;
    }

    return target;
}

void
Board::render(std::ostream &target) 
const {
    for (uint8_t x{}; x < m_Size; ++x) {
        target << "|";
        for (uint8_t y{}; y < m_Size; ++y) 
            target << m_Grid[x][y] << "|";
        target << '\n';
    }
}

std::optional<TileState> 
Board::getTile(uint8_t x, uint8_t y) 
const {
    if (x >= m_Size || y >= m_Size || x < 0 || y < 0)
        return std::nullopt;

    return m_Grid[x][y];
}

std::optional<TileState*> 
Board::getTile(uint8_t x, uint8_t y) {
    if (x >= m_Size || y >= m_Size || x < 0 || y < 0)
        return std::nullopt;

    return &m_Grid[x][y];
}