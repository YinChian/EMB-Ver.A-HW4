#include <btnCtrl.hpp>
#include <main.h>
#include <touchgfx/hal/HAL.hpp>

extern "C"{
extern uint8_t User_ButtonState;
}

void PhysicalButtonController::init()
{
	previousState = 0xFF;
}

bool PhysicalButtonController::sample(uint8_t& key)
{
    if (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_11) == GPIO_PIN_SET)
    {
    	previousState = 0x00;
	    key = 48;
	    return true;
    }
    previousState = 0xFF;
    return false;
}
