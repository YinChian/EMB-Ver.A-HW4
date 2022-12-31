#ifndef RULEPRESENTER_HPP
#define RULEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ruleView;

class rulePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    rulePresenter(ruleView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~rulePresenter() {};

private:
    rulePresenter();

    ruleView& view;
};

#endif // RULEPRESENTER_HPP
