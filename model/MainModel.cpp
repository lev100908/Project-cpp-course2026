#include "MainModel.h"
#include <memory>

bool MainModel::checkExistThisPos(std::array<Config::Position, 4> positions)
{
    for (const Config::Position& offset : positions)
    {
        const int x = offset.x;
        const int y = offset.y;

        if (!board_.isInside(y, x))
        {
            return false;
        }

        if (board_.getCell(y, x).isFilled())
        {
            return false;
        }
    }
    return true;
}

bool MainModel::canFall()
{
    bool res = false;
    current_tetramino_.move(0, 1);
    if (checkExistThisPos(current_tetramino_.getPositions())) {res = true;}
    current_tetramino_.move(0,-1);
    return res;
}

std::unique_ptr<BaseTetrominoStrategy> MainModel::getRandomTetraminoStrategy()
{
    TetraminoComponents components = StrategyFactory::createRandomStrategy();
    filled_state_current_tetramino_ = components.cell_state;
    return std::move(components.strategy);
}

void MainModel::lockTetramino()
{
    std::array<Config::Position, 4> positions = current_tetramino_.getPositions();

    for (const Config::Position& pos : positions)
    {
        board_.getCell(pos.y, pos.x).changeState(filled_state_current_tetramino_);
    }
}


