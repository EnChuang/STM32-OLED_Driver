#include "stdint.h"
#include "gpio.h"

#define SPI_mode         (0)
#define SDIO_mode        (1)
#define TRANSFER_METHOD  (SDIO_mode)

//-----------------OLED�ݤf�w�q----------------

#define OLED_CMD   0   // �g�R�O
#define OLED_DATA  1   // �g�ƾ�

#if (TRANSFER_METHOD == SPI_mode)    // I/O ���� SPI
// SPI(I/O ����)
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

#elif (TRANSFER_METHOD == SDIO_mode) // OLED ��� D0-D7 -> Port ��X (8080 �Ҧ�)
#define OLED_RD_Clr()     digitalLo(GPIOB, GPIO_PIN_11) // Ū���� E/RD3
#define OLED_RD_Set()     digitalHi(GPIOB, GPIO_PIN_11)

#define OLED_WR_Clr()     digitalLo(GPIOB, GPIO_PIN_12) // �g���� RW(WR)4
#define OLED_WR_Set()     digitalHi(GPIOB, GPIO_PIN_12)

#define OLED_CS_Clr()     digitalLo(GPIOB, GPIO_PIN_13) // ����H�� CS5
#define OLED_CS_Set()     digitalHi(GPIOB, GPIO_PIN_13)

#define OLED_DC_Clr()     digitalLo(GPIOB, GPIO_PIN_14) // �ƾ�/�R�O���� DC6
#define OLED_DC_Set()     digitalHi(GPIOB, GPIO_PIN_14)

#define OLED_RES_Clr()    digitalLo(GPIOB, GPIO_PIN_15) // �_�� RES7
#define OLED_RES_Set()    digitalHi(GPIOB, GPIO_PIN_15)
#endif

/******* �q�� *******/
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
void OLED_Init(void);
void Swaps(uint8_t *x, uint8_t *y);
void OLED_WR_Byte(int dat, uint8_t cmd);
void Set_Address(uint32_t a, uint32_t b, uint32_t c, uint32_t d);

/******* �򥻥\�� *******/
void DrawPixel(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b);
void DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t r, uint8_t g, uint8_t b);
void FillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, uint8_t g, uint8_t b);
void FillRGB(uint8_t r, uint8_t g, uint8_t b);
void OLED_DrawCircle(uint8_t x, uint8_t y, uint8_t R, uint8_t r, uint8_t g, uint8_t b);

/******* �r�� *******/
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t size1, uint8_t r, uint8_t g, uint8_t b);
void OLED_ShowString(uint8_t x, uint8_t y, uint8_t *chr, uint8_t size1,
                     uint8_t r, uint8_t g, uint8_t b,
                     uint8_t backr, uint8_t backg, uint8_t backb);

/******* �Ϥ� *******/
void DrawPicture15x15(uint8_t x, uint8_t y, uint8_t Pic[15][15], uint8_t r, uint8_t g, uint8_t b);
void DrawPicture30x15(uint8_t x, uint8_t y, uint8_t Pic[15][30], uint8_t r, uint8_t g, uint8_t b);
void DrawPicture58x30(uint8_t x, uint8_t y, uint8_t Pic[30][58], uint8_t r, uint8_t g, uint8_t b);