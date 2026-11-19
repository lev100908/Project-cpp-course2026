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

MainModel::MainModel() : current_tetramino_(getRandomTetraminoStrategy()),
      is_game_over_(false),
      score_(0)
{
    board_ = Board();
}

Config::DisplayBoard MainModel::getDisplayBoard() const
{
    Config::DisplayBoard display_board{};

    for (int row = 0; row < Config::BOARD_HEIGHT; ++row)
    {
        for (int column = 0; column < Config::BOARD_WIDTH; ++column)
        {
            display_board[row][column].color = board_.getCell(row, column).getColor();
            
        }
    }

    const auto positions = current_tetramino_.getPositions();

    for (const Config::Position& pos : positions)
    {
        if (board_.isInside(pos.y, pos.x))
        {
            display_board[pos.y][pos.x].color =
                filled_state_current_tetramino_->getColor();
        }
    }

    return display_board;
}
