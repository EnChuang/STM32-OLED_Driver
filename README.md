# OLED SSD1351 1.46" Display Driver – STM32F103VET6  

---

## 簡介 | Introduction

**中文：**  
本專案使用 STM32F103VET6 搭配 HAL 函式庫驅動 OLED 顯示器（型號：SSD1351_1.46" NO29-P23903）。主要控制程式包含 `bsp_oled.c` 和 `bsp_oled.h`，具備良好的可移植性。字型顯示與圖像渲染可透過 `font.h` 自行擴充與修改。

**English:**  
This project drives the SSD1351 1.46" OLED display (NO29-P23903) using the STM32F103VET6 and the HAL library. The core driver is implemented in `bsp_oled.c` and `bsp_oled.h`, which are generally portable. Font display and image rendering functionalities can be customized and extended via `font.h`.

---

## 📂 建議檔案結構 | Recommended File Structure

├── Core/
│ ├── Inc/
│ │ ├── bsp_oled.h
│ │ ├── font.h
│ │ └── font.h
│ └── Src/
│ │ ├── bsp_oled.c
│ │ └── font.h
└──  README.md
 
