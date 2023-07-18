//
// Created by CalvertLee on 2023/7/16.
//

#include "tim.h"

u16 counterNum;

TIM_HandleTypeDef TIM3_Handler;      //定时器句柄


void TIM3_Init(u16 arr,u16 psc) {
  TIM3_Handler.Instance=TIM3;                          //通用定时器3
  TIM3_Handler.Init.Prescaler=psc;                     //分频系数
  TIM3_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //向上计数器
  TIM3_Handler.Init.Period=arr;                        //自动装载值
  TIM3_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//时钟分频因子
  HAL_TIM_Base_Init(&TIM3_Handler);

  HAL_TIM_Base_Start_IT(&TIM3_Handler); //使能定时器3和定时器3更新中断：TIM_IT_UPDATE
}


//定时器底册驱动，开启时钟，设置中断优先级
//此函数会被HAL_TIM_Base_Init()函数调用
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
  if(htim->Instance==TIM3)
  {
    __HAL_RCC_TIM3_CLK_ENABLE();            //使能TIM3时钟
    HAL_NVIC_SetPriority(TIM3_IRQn,1,3);    //设置中断优先级，抢占优先级1，子优先级3
    HAL_NVIC_EnableIRQ(TIM3_IRQn);          //开启ITM3中断
  }
}

//定时器3中断服务函数
void TIM3_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&TIM3_Handler);
}

//回调函数，定时器中断服务函数调用
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim==(&TIM3_Handler))
  {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);        //LED1反转
    counterNum++;
  }
}

u16 ShowNum(void) {
  return counterNum;
}