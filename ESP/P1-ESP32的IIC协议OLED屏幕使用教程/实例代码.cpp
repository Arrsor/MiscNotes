#include <Arduino.h>
#include <U8g2lib.h> //新使用的u8g2库
#include <Wire.h> //修改I2C引脚所要用到的库

#define I2C_SCL xx //xx处填写SCL连接的引脚编号，比如14，需要修改
#define I2C_SDA yy //yy处填写SDA连接的引脚编号，比如25，需要修改

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0,U8X8_PIN_NONE); //这里的构造函数选步骤四中适合你的屏幕的构造函数。现在创建了一个对象u8g2(名字不为一),以后对屏幕的操控都要用它

void setup(){
    Wire.begin(I2C_SDA,I2C_SCL); //这里来规定SDA和SCL的引脚编号是多少
    u8g2.begin(); //开始屏幕的使用
    u8g2.enableUTF8Print(); //提供UTF-8支持
}

void loop(){
    u8g2.clearBuffer(); //清除缓冲区的内容

    u8g2.setDrawColor(1); //设置打印颜色为亮色(1为亮色，0为暗色(不发光))
    u8g2.setFont(u8g2_font_wqy16_t_gb2312);//设置字体
    u8g2.setCursor(0,18); //设置打印文字时的光标位置
    u8g2.print("请输入文本"); //设置打印内容为“请输入文本”

    u8g2.sendBuffer(); //把缓冲区的内容发送到屏幕上
    delay(5000); //等待5s刷新，避免一直刷新屏幕
}

