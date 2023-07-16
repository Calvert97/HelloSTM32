//
// Created by CalvertLee on 2023/7/16.
//

#include "exti.h"

u16 Counter_Num;

void EXTI_Init(void){
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_Initure.Pin = GPIO_PIN_14;
    GPIO_Initure.Mode = GPIO_MODE_IT_RISING;
    GPIO_Initure.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_Initure);

    GPIO_Initure.Pin = GPIO_PIN_1;
    HAL_GPIO_Init(GPIOB, &GPIO_Initure);

    //中断线14
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

    //中断线1
    HAL_NVIC_SetPriority(EXTI1_IRQn, 2, 1);
    HAL_NVIC_EnableIRQ(EXTI1_IRQn);
}

// 中断服务函数1
void EXTI15_10_IRQHandler(void){
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_14) != RESET) {
        Counter_Num++;
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_14);
    }
}

// 中断服务函数2
void EXTI1_IRQHandler(void){
    if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != RESET){
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_1);
    }

}

u16 Counter_Get(void){
    return Counter_Num;
}