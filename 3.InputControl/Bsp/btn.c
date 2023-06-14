//
// Created by CalvertLee on 2023/5/21.
//

#include "btn.h"

void Btn_Init(void ){

    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_Initure;

    GPIO_Initure.Pull = GPIO_PIN_1 | GPIO_PIN_11;
    GPIO_Initure.Mode = GPIO_MODE_INPUT;
    GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_Initure.Pull = GPIO_PULLUP;

    HAL_GPIO_Init(GPIOB,&GPIO_Initure);
}

/**

  * @brief   检测是否有按键按下

  * @param   具体的端口和端口位

  *		@arg GPIOx: x可以是（A...G）

  *		@arg GPIO_PIN 可以是GPIO_PIN_x（x可以是1...16）

  * @retval  按键的状态

  *		@arg KEY_ON:按键按下

  *		@arg KEY_OFF:按键没按下

  */

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)

{

    /*检测是否有按键按下 */

    if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == KEY_ON )

    {

        /*等待按键释放 */

        while(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == KEY_ON);

        return 	KEY_ON;

    }

    else

        return KEY_OFF;

}