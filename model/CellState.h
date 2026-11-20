#pragma once

#include "..\config\config.h"

class BaseCellState
{
public:
    virtual ~BaseCellState() = default;

    virtual bool isFilled() const = 0;

    virtual Config::Color getColor() const = 0;
};

class EmptyCellState : public BaseCellState
{
public:
    bool isFilled() const override {return false; };

    Config::Color getColor() const override { return Config::EMPTY_CELL_COLOR;}
};

class FilledCellState : public BaseCellState
{
public:
    bool isFilled() const override {return true; };
    Config::Color getColor() const override { return Config::WHITE;}
};

class ITetraminoCellState : public FilledCellState
{
public:
    Config::Color getColor() const override { return Config::BLUE;}
};

class OTetraminoCellState : public FilledCellState
{
public:
    Config::Color getColor() const override { return Config::PURPLE;}
};

class TTetraminoCellState : public FilledCellState
{
public:
    Config::Color getColor() const override { return Config::YELLOW;}
};

class STetraminoCellState : public FilledCellState
{
public:
    Config::Color getColor() const override { return Config::GREEN;}
};

class ZTetraminoCellState : public FilledCellState
{
public:
    Config::Color getColor() const override { return Config::CYAN;}
};

class JTetraminoCellState : public FilledCellState
{
public:
    Config::Color getColor() const override { return Config::RED;}
};

class LTetraminoCellState : public FilledCellState
{
public:
    Config::Color getColor() const override { return Config::RED;}
};

