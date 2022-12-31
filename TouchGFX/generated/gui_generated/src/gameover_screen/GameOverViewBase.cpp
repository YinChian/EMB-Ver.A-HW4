/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/gameover_screen/GameOverViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

GameOverViewBase::GameOverViewBase() :
    buttonCallback(this, &GameOverViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    button1.setXY(0, 0);
    button1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BACKGROUNDS_MAIN_BG_TEXTURE_480X272PX_ID), touchgfx::Bitmap(BITMAP_BLUE_BACKGROUNDS_MAIN_BG_TEXTURE_480X272PX_ID));
    button1.setAction(buttonCallback);

    showWin.setXY(101, 80);
    showWin.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    showWin.setLinespacing(0);
    Unicode::snprintf(showWinBuffer, SHOWWIN_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_R3W9).getText());
    showWin.setWildcard(showWinBuffer);
    showWin.resizeToCurrentText();
    showWin.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IJ45));

    textArea2.setXY(107, 173);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IGYS));

    add(__background);
    add(button1);
    add(showWin);
    add(textArea2);
}

void GameOverViewBase::setupScreen()
{

}

void GameOverViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button1)
    {
        //Interaction1
        //When button1 clicked change screen to rule
        //Go to rule with no screen transition
        application().gotoruleScreenNoTransition();
    }
}