//
// Created by CalvertLee on 2023/5/21.
//

#ifndef INC_3_INPUTCONTROL_BTN_H
#define INC_3_INPUTCONTROL_BTN_H

#include "sys.h"

//引脚定义
/*******************************************************/
#define KEY1_PIN                  GPIO_PIN_1
#define KEY1_GPIO_PORT            GPIOB
#define KEY1_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()

#define KEY2_PIN                  GPIO_PIN_11
#define KEY2_GPIO_PORT            GPIOB
#define KEY2_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOC_CLK_ENABLE()
/*******************************************************/

/** 按键按下标置宏
   * 按键按下为高电平，设置 KEY_ON=1， KEY_OFF=0
   * 若按键按下为低电平，把宏设置成KEY_ON=0 ，KEY_OFF=1 即可
   */
#define KEY_ON	1
#define KEY_OFF	0

void Btn_Init(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif //INC_3_INPUTCONTROL_BTN_H
