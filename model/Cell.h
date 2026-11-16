#pragma once

#include "..\config\config.h"
#include "CellState.h"
#include <memory>

class Cell
{
private:
    std::shared_ptr<const BaseCellState> cell_state_;
    
public:
    Cell();

    Cell(const std::shared_ptr<const BaseCellState>& cell_state);
    
    void changeState(const std::shared_ptr<const BaseCellState>& new_state);

    bool isFilled() const;
    
    Config::Color getColor() const;

};