#ifndef RESULTVIEW_HPP
#define RESULTVIEW_HPP

#include <gui_generated/result_screen/resultViewBase.hpp>
#include <gui/result_screen/resultPresenter.hpp>

class resultView : public resultViewBase
{
public:
    resultView();
    virtual ~resultView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RESULTVIEW_HPP
