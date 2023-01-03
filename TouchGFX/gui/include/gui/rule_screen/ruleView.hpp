#ifndef RULEVIEW_HPP
#define RULEVIEW_HPP

#include <gui_generated/rule_screen/ruleViewBase.hpp>
#include <gui/rule_screen/rulePresenter.hpp>

class ruleView : public ruleViewBase
{
public:
    ruleView();
    virtual ~ruleView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void RNG();
protected:
    int seed = 0;
};

#endif // RULEVIEW_HPP
