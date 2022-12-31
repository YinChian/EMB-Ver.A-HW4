#include <gui/gameover_screen/GameOverView.hpp>

GameOverView::GameOverView()
{

}

void GameOverView::setupScreen()
{
    GameOverViewBase::setupScreen();
    //touchgfx_printf("\n%s Wins!", presenter->getFinalColor() ? "RED" : "BLACK");
    Unicode::strncpy(showWinBuffer, presenter->getWinner() == 0 ? "RED" : "BLACK", 6); //buffer belongs to textArea
    showWin.resizeToCurrentText(); //resize if necessary
    showWin.invalidate(); //invalidate to render new text
}

void GameOverView::tearDownScreen()
{
    GameOverViewBase::tearDownScreen();
}
