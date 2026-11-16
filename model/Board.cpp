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

bool Board::checkRow(int row)
{
    bool res = true;
    for (int column = 0; column < Config::BOARD_WIDTH; ++column)
    {
        if (!table_[row][column].isFilled())
        {
            res = false;
            break;
        }
    }
    return res;
}

int Board::checkBoard()
{
    int full_rows = 0;

    for (int row = Config::BOARD_HEIGHT - 1; row >= 0; --row)
    {
        bool is_full = true;

        for (int column = 0; column < Config::BOARD_WIDTH; ++column)
        {
            if (!table_[row][column].isFilled())
            {
                is_full = false;
                break;
            }
        }

        if (is_full)
        {
            ++full_rows;

            for (int upper_row = row; upper_row > 0; --upper_row)
            {
                table_[upper_row] = table_[upper_row - 1];
            }

            for (int column = 0; column < Config::BOARD_WIDTH; ++column)
            {
                table_[0][column].changeState(empty_cell_state_);
            }

            ++row;
        }
    }

    return full_rows;
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
