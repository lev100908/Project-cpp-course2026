#pragma once

#include "Board.h"
#include "Tetramino.h"
#include "TetraminoStrategy\BaseTetraminoStrategy.h"
#include "TetraminoStrategy\IStrategy.h"
#include "TetraminoStrategy\TetraminoStrategyFabric.h"
#include <memory>

class MainModel
{
private:
    Board board_ = Board();

    std::unique_ptr<BaseTetrominoStrategy> getRandomTetraminoStrategy();

    std::shared_ptr<BaseCellState> filled_state_current_tetramino_;

    Tetromino current_tetramino_;

    bool is_game_over_;
    int score_;

    bool checkExistThisPos(std::array<Config::Position, 4> positions);

    bool canFall();

    void lockTetramino();

public:
    MainModel();

    Config::DisplayBoard getDisplayBoard() const;

    void moveLeft();
    void moveRight();
    void moveFastDown();
    void rotate();

    void update();

    

    bool isGameOver();
    int score();

};