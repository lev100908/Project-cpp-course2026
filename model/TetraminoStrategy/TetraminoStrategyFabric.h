#pragma once

#include <memory>
#include "IStrategy.h"
#include "JStrategy.h"
#include "LStrategy.h"
#include "OStrategy.h"
#include "SStrategy.h"
#include "TStrategy.h"
#include "ZStrategy.h"


#include "BaseTetraminoStrategy.h"
#include "../CellState.h"

struct TetraminoComponents {
    std::unique_ptr<BaseTetrominoStrategy> strategy;
    std::shared_ptr<BaseCellState> cell_state;
};

class StrategyFactory {
public:
    static TetraminoComponents createRandomStrategy();
};