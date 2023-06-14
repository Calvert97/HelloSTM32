//
// Created by CalvertLee on 2023/5/28.
//

#include "LightSensor.h"


void LightSensor_Init(){
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_Initure;

    GPIO_Initure.Pin = GPIO_PIN_11;
    GPIO_Initure.Mode = GPIO_MODE_INPUT;
    GPIO_Initure.Pull = GPIO_PULLUP;
    GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_Initure);

}


u8 LightSensor_Get(void){
    return HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11);
}