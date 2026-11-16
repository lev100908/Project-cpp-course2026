#include "Cell.h"

Cell::Cell() : cell_state_(nullptr) {}


Cell::Cell(const std::shared_ptr<const BaseCellState> &cell_state) : cell_state_(cell_state) {}

void Cell::changeState(const std::shared_ptr<const BaseCellState>& new_state) {
    cell_state_ = new_state;
}

bool Cell::isFilled() const
{
    return cell_state_ -> isFilled();
}

Config::Color Cell::getColor() const
{
    return cell_state_ -> getColor();
}
