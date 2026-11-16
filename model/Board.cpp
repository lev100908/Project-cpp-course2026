#include "Board.h"

#include <memory>
#include <algorithm>

Board::Board() 
{
    empty_cell_state_ = std::make_shared<EmptyCellState>();
    clear();
}

Cell &Board::getCell(int row, int column)
{
    return table_.at(row).at(column);
}

const Cell &Board::getCell(int row, int column) const
{
    return table_.at(row).at(column);
}

bool Board::isInside(int row, int column) const
{
    return row >= 0 &&
           row < Config::BOARD_HEIGHT &&
           column >= 0 &&
           column < Config::BOARD_WIDTH;
}

std::array<std::array<Cell, Config::BOARD_WIDTH>, Config::BOARD_HEIGHT> Board::getTable() const
{
    return table_;
}

void Board::clear()
{
    for (auto& row : table_)
    {
        for (auto& cell : row)
        {
            cell.changeState(empty_cell_state_);
        }
    }
}
