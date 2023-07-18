//
// Created by CalvertLee on 2023/7/16.
//

#ifndef INC_7_BASICTIM_TIM_H
#define INC_7_BASICTIM_TIM_H

#include "sys.h"
#include "stm32f1xx_hal_tim.h"

extern TIM_HandleTypeDef TIM3_Handler;      //定时器句柄

void TIM3_Init(u16 arr,u16 psc);

u16 ShowNum(void);

#endif //INC_7_BASICTIM_TIM_H
