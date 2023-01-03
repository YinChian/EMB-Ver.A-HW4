#include <gui/rule_screen/ruleView.hpp>

ruleView::ruleView()
{

}

void ruleView::setupScreen()
{
    ruleViewBase::setupScreen();
}

void ruleView::tearDownScreen()
{
    ruleViewBase::tearDownScreen();
    presenter->setSeed(seed);
}


void ruleView::RNG()
{
    // Override and implement this function in rule
    if (seed < 10000) {
        seed++;
    }
    else {
        seed = 0;
    }
    
}
