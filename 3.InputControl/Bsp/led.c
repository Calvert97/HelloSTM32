//
// Created by CalvertLee on 2023/5/21.
//

#include "led.h"

// LED IO 初始化

void LED_Init(void){
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_Initure.Pin = GPIO_PIN_1 | GPIO_PIN_5;
    GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP; //推挽输出模式
    GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH; //高速模式
    GPIO_Initure.Pull = GPIO_PULLUP; //上拉
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);

    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
}

