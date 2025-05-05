#include "bsp_oled.h"
#include "bsp_flash64.h"
#include "font.h"

/* Private define ------------------------------------------------------------*/
#define abss(a) ((a) < 0 ? -(a) : a)
/* Private struct ------------------------------------------------------------*/
typedef struct ColorStucture
{
    uint8_t R;
    uint8_t G;
    uint8_t B;
} Color;



/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  PortVal: specifies the value to be written to the port output data register.
  * @retval None
  */
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

    GPIOx->ODR = PortVal;
}


//OLED_SSD1351_1.46" NO29-P23903 ªì©l¤Æ
void OLED_Init(void)
{
    OLED_RES_Set();
    HAL_Delay(5);
    OLED_RES_Clr();
    OLED_RES_Set();
    HAL_Delay(5);
    OLED_CS_Set();
    OLED_CS_Clr();

    OLED_WR_Byte(0x00fd,OLED_CMD);//set command lock
    OLED_WR_Byte(0x0012,OLED_DATA);
    OLED_WR_Byte(0x00fd,OLED_CMD);//set command lock
    OLED_WR_Byte(0x00b1,OLED_DATA);
    OLED_WR_Byte(0x00ae,OLED_CMD);//display off
    OLED_WR_Byte(0x0015,OLED_CMD);//set column address
    OLED_WR_Byte(0x0000,OLED_DATA);
    OLED_WR_Byte(0x007f,OLED_DATA);
    OLED_WR_Byte(0x0075,OLED_CMD);//set row address
    OLED_WR_Byte(0x0000,OLED_DATA);
    OLED_WR_Byte(0x007f,OLED_DATA);
    OLED_WR_Byte(0x005c,OLED_CMD);//set write ram
    OLED_WR_Byte(0x005d,OLED_CMD);//set  read ram
    OLED_WR_Byte(0x00a0,OLED_CMD);//set re-map&color depth
    OLED_WR_Byte(0x0074,OLED_DATA);
    OLED_WR_Byte(0x00a1,OLED_CMD);//set display start line
    OLED_WR_Byte(0x0000,OLED_DATA);
    OLED_WR_Byte(0x00a2,OLED_CMD);//set display offset
    OLED_WR_Byte(0x0000,OLED_DATA);
    OLED_WR_Byte(0x00a6,OLED_CMD);//set display mode
    OLED_WR_Byte(0x00ab,OLED_CMD);//funcion selection
    OLED_WR_Byte(0x0001,OLED_DATA);
    OLED_WR_Byte(0x00af,OLED_CMD);//set display on
    OLED_WR_Byte(0x00b1,OLED_CMD);//set phase length
    OLED_WR_Byte(0x0032,OLED_DATA);
    OLED_WR_Byte(0x00b3,OLED_CMD); //display clock divider / oscillator frequency
    OLED_WR_Byte(0x00f1,OLED_DATA);
    OLED_WR_Byte(0x00b4,OLED_CMD);//set segment low voltage
    OLED_WR_Byte(0x00a0,OLED_DATA);
    OLED_WR_Byte(0x00b5,OLED_DATA);
    OLED_WR_Byte(0x0055,OLED_DATA);
    OLED_WR_Byte(0x00b5,OLED_CMD);//set gpio
    OLED_WR_Byte(0x000a,OLED_DATA);
    OLED_WR_Byte(0x00b6,OLED_CMD);//set second pre-charge period
    OLED_WR_Byte(0x0001,OLED_DATA);
    OLED_WR_Byte(0x00b8,OLED_CMD);//gamma look up table
    OLED_WR_Byte(0x0002,OLED_DATA);
    OLED_WR_Byte(0x0003,OLED_DATA);
    OLED_WR_Byte(0x0004,OLED_DATA);
    OLED_WR_Byte(0x0005,OLED_DATA);
    OLED_WR_Byte(0x0006,OLED_DATA);
    OLED_WR_Byte(0x0007,OLED_DATA);
    OLED_WR_Byte(0x0008,OLED_DATA);
    OLED_WR_Byte(0x0009,OLED_DATA);
    OLED_WR_Byte(0x000a,OLED_DATA);
    OLED_WR_Byte(0x000b,OLED_DATA);
    OLED_WR_Byte(0x000c,OLED_DATA);
    OLED_WR_Byte(0x000d,OLED_DATA);
    OLED_WR_Byte(0x000e,OLED_DATA);
    OLED_WR_Byte(0x000f,OLED_DATA);
    OLED_WR_Byte(0x0010,OLED_DATA);
    OLED_WR_Byte(0x0011,OLED_DATA);
    OLED_WR_Byte(0x0012,OLED_DATA);
    OLED_WR_Byte(0x0013,OLED_DATA);
    OLED_WR_Byte(0x0015,OLED_DATA);
    OLED_WR_Byte(0x0017,OLED_DATA);
    OLED_WR_Byte(0x0019,OLED_DATA);
    OLED_WR_Byte(0x001b,OLED_DATA);
    OLED_WR_Byte(0x001d,OLED_DATA);
    OLED_WR_Byte(0x001f,OLED_DATA);
    OLED_WR_Byte(0x0021,OLED_DATA);
    OLED_WR_Byte(0x0023,OLED_DATA);
    OLED_WR_Byte(0x0025,OLED_DATA);
    OLED_WR_Byte(0x0027,OLED_DATA);
    OLED_WR_Byte(0x002a,OLED_DATA);
    OLED_WR_Byte(0x002d,OLED_DATA);
    OLED_WR_Byte(0x0030,OLED_DATA);
    OLED_WR_Byte(0x0033,OLED_DATA);
    OLED_WR_Byte(0x0036,OLED_DATA);
    OLED_WR_Byte(0x0039,OLED_DATA);
    OLED_WR_Byte(0x003c,OLED_DATA);
    OLED_WR_Byte(0x003f,OLED_DATA);
    OLED_WR_Byte(0x0042,OLED_DATA);
    OLED_WR_Byte(0x0045,OLED_DATA);
    OLED_WR_Byte(0x0048,OLED_DATA);
    OLED_WR_Byte(0x004c,OLED_DATA);
    OLED_WR_Byte(0x0050,OLED_DATA);
    OLED_WR_Byte(0x0054,OLED_DATA);
    OLED_WR_Byte(0x0058,OLED_DATA);
    OLED_WR_Byte(0x005c,OLED_DATA);
    OLED_WR_Byte(0x0060,OLED_DATA);
    OLED_WR_Byte(0x0064,OLED_DATA);
    OLED_WR_Byte(0x0068,OLED_DATA);
    OLED_WR_Byte(0x006c,OLED_DATA);
    OLED_WR_Byte(0x0070,OLED_DATA);
    OLED_WR_Byte(0x0074,OLED_DATA);
    OLED_WR_Byte(0x0078,OLED_DATA);
    OLED_WR_Byte(0x007d,OLED_DATA);
    OLED_WR_Byte(0x0082,OLED_DATA);
    OLED_WR_Byte(0x0087,OLED_DATA);
    OLED_WR_Byte(0x008c,OLED_DATA);
    OLED_WR_Byte(0x0091,OLED_DATA);
    OLED_WR_Byte(0x0096,OLED_DATA);
    OLED_WR_Byte(0x009b,OLED_DATA);
    OLED_WR_Byte(0x00a0,OLED_DATA);
    OLED_WR_Byte(0x00a5,OLED_DATA);
    OLED_WR_Byte(0x00aa,OLED_DATA);
    OLED_WR_Byte(0x00af,OLED_DATA);
    OLED_WR_Byte(0x00b4,OLED_DATA);
    OLED_WR_Byte(0x00bb,OLED_CMD);//set pre-charge period
    OLED_WR_Byte(0x0017,OLED_DATA);
    OLED_WR_Byte(0x00be,OLED_CMD);//set vcomh voltage
    OLED_WR_Byte(0x0005,OLED_DATA);
    OLED_WR_Byte(0x00c1,OLED_CMD);//set contrast current
    OLED_WR_Byte(0x00c8,OLED_DATA);
    OLED_WR_Byte(0x0080,OLED_DATA);
    OLED_WR_Byte(0x00c8,OLED_DATA);
    OLED_WR_Byte(0x00c7,OLED_CMD);//set master current control
    OLED_WR_Byte(0x000f,OLED_DATA);//0f
    OLED_WR_Byte(0x00ca,OLED_CMD);//set multiplex ratio
    OLED_WR_Byte(0x007f,OLED_DATA);
    OLED_WR_Byte(0x00af,OLED_CMD);//set display on

    OLED_CS_Set();
}


//¤À§O¼g¤J¦æ¡B¦Cªº¦a§}(0-127,0-127,0-127,0-127)
void Set_Address(uint32_t a,uint32_t b,uint32_t c,uint32_t d)
{
    OLED_WR_Byte(0x0015,OLED_CMD);//set column address
    OLED_WR_Byte(a,OLED_DATA);//start address
    OLED_WR_Byte(b,OLED_DATA);//end address

    OLED_WR_Byte(0x0075,OLED_CMD);//set row address
    OLED_WR_Byte(c,OLED_DATA);//start address
    OLED_WR_Byte(d,OLED_DATA);//end address
}




//®y¼ÐX,Y¥æ´«
void Swaps(uint8_t *x, uint8_t *y)
{
    uint8_t t = *x;

    *x = *y;
    *y = t;
}


//¼g¤Jbyte
void OLED_WR_Byte(int dat,uint8_t cmd)
{


    if(cmd)
    {
        OLED_DC_Set();
    }
    else
    {
        OLED_DC_Clr();
    }
    OLED_CS_Clr();


#if (TRANSFER_METHOD == SPI_mode)
    //uint8_t i;
    dat_u8 = dat;
    for(i=0; i<8; i++)
    {
        OLED_SCL_Clr();
        if(dat_u8&0x80)
            OLED_SDA_Set();
        else
            OLED_SDA_Clr();
        OLED_SCL_Set();
        dat_u8<<=1;
    }

#elif (TRANSFER_METHOD == SDIO_mode)
    dat = dat<<8;
    GPIO_Write(GPIOE,dat);

    OLED_WR_Clr();
    OLED_WR_Set();
#endif

    OLED_CS_Set();
    OLED_DC_Set();
}

//Åã¥Ü¦r²Å¦ê
//x,y:°_ÂI
//size1:¦rÅé¤j¤p
//*chr:¦r²Å°_©l¦a§}
void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t size1,uint8_t r, uint8_t g, uint8_t b)
{
    while((*chr>=' ')&&(*chr<='~'))//§PÂ_¬O¤£¬O«Dªk¦r²Å
    {
        OLED_ShowChar(x,y,*chr,size1,r, g, b);
        if(size1==8)x+=6;
        else x+=size1/2;
        chr++;
    }
}

//x:0~127
//y:0~63
//size1:¿ï¾Ü¦rÅé¤j¤p 6x8/6x12/8x16/12x24
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size1,uint8_t r, uint8_t g, uint8_t b)
{
    int i,m,temp,size2,chr1;
    uint8_t chr2;
    uint8_t x0=x,y0=y;

    if(size1==8)size2=8;
    else if(size1==64)size2=256;
    else if(size1==46)size2=138;
    else size2=(size1/8+((size1%8)?1:0))*(size1/2);  //±o¨ìÂI°}¹ÏÁ`¼Æ

    chr1=chr-' ';  //ASCII ­pºâ°¾²¾­È
    chr2=chr-0x30;
    for(i=0; i<size2; i++)
    {
        if(size1==8)
        {
            temp=asc2_0806[chr1][i];   //0806
        }
        else if(size1==12)
        {
            temp=asc2_1206[chr1][i];   //1206
        }
        else if(size1==16)
        {
            temp=asc2_1608[chr1][i];   //1608
        }
        else if(size1==24)
        {
            temp=asc2_2412[chr1][i];   //2412
        }
        else if(size1==64)
        {
            temp=Pic32x64[chr2][i];   //6432
        }
        else if(size1==46)
        {
            temp=Pic23x48[chr2][i];   //4823
        }
        else return;

        for(m=0; m<8; m++)
        {
            DrawPixel(x,y,r,g,b);
            temp>>=1;
            y++;
        }
        x++;
        if((size1!=8)&&((x-x0)==size1/2))
        {
            x=x0;
            y0=y0+8;
        }
        y=y0;
    }
}

/**************************************OLED°ò¥»¥\¯à***********************************************/
//RGB¤è¶ô
void FillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t dX, dY;
    uint8_t data1 = ((r<<3) & 0xF8) | (g>>3);
    uint8_t data2 = b | (g<<5);
    Set_Address(x, x + w - 1, y, y + h - 1);
    OLED_WR_Byte(0x5c,OLED_CMD);


    OLED_DC_Set();
    for (dY = 0; dY < h; dY++)
    {
        for (dX = 0; dX < w; dX++)
        {
            OLED_WR_Byte(data1,OLED_DATA);
            OLED_WR_Byte(data2,OLED_DATA);
        }
    }
    OLED_DC_Clr();
}


//¥þ«ÌRGB
void FillRGB(uint8_t r,uint8_t g,uint8_t b)//  r:0~31 g:0~63 B:0~31
{
    uint8_t x,y;
    uint8_t data1 = ((r<<3) & 0xF8) | (g>>3);
    uint8_t data2 = b | (g<<5);
    Set_Address(0, 127, 0, 127);
    OLED_WR_Byte(0x5c,OLED_CMD);

    OLED_DC_Set();
    for (x=0; x<128; x++)
    {
        for (y=0; y<128; y++)
        {
            OLED_WR_Byte(data1,OLED_DATA);
            OLED_WR_Byte(data2,OLED_DATA);
        }
    }
    OLED_DC_Clr();
}

//³æÂIRGB
void DrawPixel(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t data1 = ((r<<3) & 0xF8) | (g>>3);
    uint8_t data2 = b | (g<<5);

    Set_Address(x, x, y, y);
    OLED_WR_Byte(0x5c,OLED_CMD);


    OLED_DC_Set();
    OLED_WR_Byte(data1,OLED_DATA);
    OLED_WR_Byte(data2,OLED_DATA);
    OLED_DC_Clr();
}

//³æ½uRGB
void DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t dx, dy;
    int8_t dyStep;
    int8_t steep;
    int16_t calc;

    OLED_WR_Byte(0x5c,OLED_CMD);
    // Vertical Line
    if (x1 == x2)
    {
        if (y1 > y2)
        {
            Swaps(&y1, &y2);
        }

        FillRect(x1, y1, 1, y2 - y1,  r,  g,  b);
        return;
    }

    // Horizontal Line
    if (y1 == y2)
    {
        if (x1 > x2)
        {
            Swaps(&x1, &x2);
        }

        FillRect(x1, y1, x2 - x1, 1,  r,  g,  b);
        return;
    }

    steep = abss(y2 - y1) > abss(x2 - x1);

    if (steep)
    {
        Swaps(&x1, &y1);
        Swaps(&x2, &y2);
    }

    if (x1 > x2)
    {
        Swaps(&x1, &x2);
        Swaps(&y1, &y2);
    }

    dx = x2 - x1;
    dy = abss(y2 - y1);
    calc = dx >> 1;
    dyStep = (y1 < y2 ? 1 : -1);

    for (; x1 <= x2; x1++)
    {
        if (steep)
        {
            DrawPixel(y1, x1,  r,  g,  b);
        }
        else
        {
            DrawPixel(x1, y1,  r,  g,  b);
        }

        calc -= dy;

        if (calc < 0)
        {
            y1 += dyStep;
            calc += dx;
        }
    }
}

//Bresenham's circle algorithm
//¤Q¦r¥Í¶êˆA
void draw_circle_8(int xc, int yc, int x, int y, int r, int g, int b) {
    DrawPixel(xc + x, yc + y, r,g,b);
    DrawPixel(xc - x, yc + y, r,g,b);
    DrawPixel(xc + x, yc - y, r,g,b);
    DrawPixel(xc - x, yc - y, r,g,b);
    DrawPixel(xc + y, yc + x, r,g,b);
    DrawPixel(xc - y, yc + x, r,g,b);
    DrawPixel(xc + y, yc - x, r,g,b);
    DrawPixel(xc - y, yc - x, r,g,b);
}

void draw_circle(int xc, int yc, int ra, int fill,  int r, int g, int b) {

    int x = 0, y = ra, yi, d;
    d = 3 - 2 * ra;

    if (fill) {
        // ¶ñ¥R
        while (x <= y) {
            for (yi = x; yi <= y; yi ++)
                draw_circle_8(xc, yc, x, yi, r, g, b);

            if (d < 0) {
                d = d + 4 * x + 6;
            } else {
                d = d + 4 * (x - y) + 10;
                y --;
            }
            x++;
        }
    } else {
        // ¤£¶ñ¥R
        while (x <= y) {
            draw_circle_8(xc, yc, x, y, r, g, b);

            if (d < 0) {
                d = d + 4 * x + 6;
            } else {
                d = d + 4 * (x - y) + 10;
                y --;
            }
            x ++;
        }
    }
}


/*********************************OLEDÅã¥Ü¹Ï¤ù******************************************/
//15x15 Pic
void DrawPicture15x15(uint8_t x, uint8_t y,uint8_t Pic[15][15],uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t i,j;
    for(i=0; i<15; i++)
    {
        for(j=0; j<15; j++)
        {
            if(Pic[i][j])
                DrawPixel( x+j,  y+i, r, g, b);
        }
    }
}
//30x15 Pic
void DrawPicture30x15(uint8_t x, uint8_t y,uint8_t Pic[15][30],uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t i,j;
    for(i=0; i<15; i++)
    {
        for(j=0; j<30; j++)
        {
            if(Pic[i][j])
                DrawPixel( x+j,  y+i, r, g, b);
        }
    }
}

//58x30 Pic
void DrawPicture58x30(uint8_t x, uint8_t y,uint8_t Pic[30][58],uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t i,j;
    for(i=0; i<30; i++) //15
    {
        for(j=0; j<58; j++) //15
        {
            if(Pic[i][j])
                DrawPixel( x+j,  y+i, r, g, b);
        }
    }
}
