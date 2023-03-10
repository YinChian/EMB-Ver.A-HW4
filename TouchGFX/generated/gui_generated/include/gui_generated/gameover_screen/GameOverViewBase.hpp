/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef GAMEOVERVIEWBASE_HPP
#define GAMEOVERVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/gameover_screen/GameOverPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class GameOverViewBase : public touchgfx::View<GameOverPresenter>
{
public:
    GameOverViewBase();
    virtual ~GameOverViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Button button1;
    touchgfx::TextAreaWithOneWildcard showWin;
    touchgfx::TextArea textArea2;

    /*
     * Wildcard Buffers
     */
    static const uint16_t SHOWWIN_SIZE = 10;
    touchgfx::Unicode::UnicodeChar showWinBuffer[SHOWWIN_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<GameOverViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // GAMEOVERVIEWBASE_HPP
