#ifndef PLAYSCREENPRESENTER_HPP
#define PLAYSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class playscreenView;

class playscreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    playscreenPresenter(playscreenView& v);

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

    void setWinner(bool winner) {
        model->setWinnerSide(winner);
    }

    virtual ~playscreenPresenter() {};

private:
    playscreenPresenter();

    playscreenView& view;
};

#endif // PLAYSCREENPRESENTER_HPP
