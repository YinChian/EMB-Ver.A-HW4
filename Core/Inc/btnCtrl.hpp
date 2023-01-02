#ifndef BUTTONCONTROLLER_HPP_
#define BUTTONCONTROLLER_HPP_

#include <platform/driver/button/ButtonController.hpp>

class PhysicalButtonController : public touchgfx::ButtonController
{
public:
    virtual void init();
    virtual bool sample(uint8_t& key);
    void reset(){};

protected:
    int previousState;

};
#endif
