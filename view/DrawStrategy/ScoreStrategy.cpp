#include "ScoreStrategy.h"
#include <string>

void ScoreStrategy::draw(sf::RenderWindow& window, const DrawingContext& context) const
{
    const float cx = static_cast<float>(Config::WINDOW_WIDTH);
    int score = context.score;
    drawPixelText(window, "Score", cx - 90, 40, 9.f, toSfColor(Config::CYAN));
    drawPixelText(window, std::to_string(score), cx - 90, 100, 7.f, toSfColor(Config::WHITE));
}
