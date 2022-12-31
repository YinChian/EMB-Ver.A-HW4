/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef RULEVIEWBASE_HPP
#define RULEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/rule_screen/rulePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>

class ruleViewBase : public touchgfx::View<rulePresenter>
{
public:
    ruleViewBase();
    virtual ~ruleViewBase() {}
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
    touchgfx::ScalableImage scalableImage1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ruleViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // RULEVIEWBASE_HPP