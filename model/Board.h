#pragma once

#include "Cell.h"
#include "..\config\config.h"
#include <array>

class Board
{
private:
    std::shared_ptr<const BaseCellState> empty_cell_state_;
    std::array<std::array<Cell, Config::BOARD_WIDTH>, Config::BOARD_HEIGHT> table_;

public:
    Board();

    Cell& getCell(int row, int column);
    const Cell& getCell(int row, int column) const;

    bool isInside(int row, int column) const;

    int checkBoard();

    int getShortestDistanceUnderPosition(const std::array<Config::Position, 4>& positions);

    std::array<std::array<Cell, Config::BOARD_WIDTH>, Config::BOARD_HEIGHT> getTable() const;

    void clear();
};