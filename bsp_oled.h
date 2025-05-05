#include "stdint.h"
#include "gpio.h"

#define SPI_mode         (0)
#define SDIO_mode        (1)
#define TRANSFER_METHOD  (SDIO_mode)

//-----------------OLED端口定義----------------

#define OLED_CMD   0   // 寫命令
#define OLED_DATA  1   // 寫數據

#if (TRANSFER_METHOD == SPI_mode)    // I/O 模擬 SPI
// SPI(I/O 模擬)
// #define OLED_SCL_Clr()  GPIO_ResetBits(GPIOD, GPIO_PIN_14) // SCL
// #define OLED_SCL_Set()  GPIO_SetBits(GPIOD, GPIO_PIN_14)

// #define OLED_SDA_Clr()  GPIO_ResetBits(GPIOD, GPIO_PIN_5)  // SDA
// #define OLED_SDA_Set()  GPIO_SetBits(GPIOD, GPIO_PIN_5)

// #define OLED_RES_Clr()  GPIO_ResetBits(GPIOD, GPIO_PIN_4)  // RES
// #define OLED_RES_Set()  GPIO_SetBits(GPIOD, GPIO_PIN_4)

// #define OLED_DC_Clr()   GPIO_ResetBits(GPIOD, GPIO_PIN_15) // DC
// #define OLED_DC_Set()   GPIO_SetBits(GPIOD, GPIO_PIN_15)

// #define OLED_CS_Clr()   GPIO_ResetBits(GPIOD, GPIO_PIN_1)  // CS
// #define OLED_CS_Set()   GPIO_SetBits(GPIOD, GPIO_PIN_1)

#elif (TRANSFER_METHOD == SDIO_mode) // OLED 資料 D0-D7 -> Port 輸出 (8080 模式)
#define OLED_RD_Clr()     digitalLo(GPIOB, GPIO_PIN_11) // 讀控制 E/RD3
#define OLED_RD_Set()     digitalHi(GPIOB, GPIO_PIN_11)

#define OLED_WR_Clr()     digitalLo(GPIOB, GPIO_PIN_12) // 寫控制 RW(WR)4
#define OLED_WR_Set()     digitalHi(GPIOB, GPIO_PIN_12)

#define OLED_CS_Clr()     digitalLo(GPIOB, GPIO_PIN_13) // 片選信號 CS5
#define OLED_CS_Set()     digitalHi(GPIOB, GPIO_PIN_13)

#define OLED_DC_Clr()     digitalLo(GPIOB, GPIO_PIN_14) // 數據/命令切換 DC6
#define OLED_DC_Set()     digitalHi(GPIOB, GPIO_PIN_14)

#define OLED_RES_Clr()    digitalLo(GPIOB, GPIO_PIN_15) // 復位 RES7
#define OLED_RES_Set()    digitalHi(GPIOB, GPIO_PIN_15)
#endif

/******* 通用 *******/
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
void OLED_Init(void);
void Swaps(uint8_t *x, uint8_t *y);
void OLED_WR_Byte(int dat, uint8_t cmd);
void Set_Address(uint32_t a, uint32_t b, uint32_t c, uint32_t d);

/******* 基本功能 *******/
void DrawPixel(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b);
void DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t r, uint8_t g, uint8_t b);
void FillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, uint8_t g, uint8_t b);
void FillRGB(uint8_t r, uint8_t g, uint8_t b);
void OLED_DrawCircle(uint8_t x, uint8_t y, uint8_t R, uint8_t r, uint8_t g, uint8_t b);

/******* 字體 *******/
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t size1, uint8_t r, uint8_t g, uint8_t b);
void OLED_ShowString(uint8_t x, uint8_t y, uint8_t *chr, uint8_t size1,
                     uint8_t r, uint8_t g, uint8_t b,
                     uint8_t backr, uint8_t backg, uint8_t backb);

/******* 圖片 *******/
void DrawPicture15x15(uint8_t x, uint8_t y, uint8_t Pic[15][15], uint8_t r, uint8_t g, uint8_t b);
void DrawPicture30x15(uint8_t x, uint8_t y, uint8_t Pic[15][30], uint8_t r, uint8_t g, uint8_t b);
void DrawPicture58x30(uint8_t x, uint8_t y, uint8_t Pic[30][58], uint8_t r, uint8_t g, uint8_t b);