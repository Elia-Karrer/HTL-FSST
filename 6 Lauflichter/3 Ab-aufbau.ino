#define TIME 500

byte ctr, len;
byte md[] = {0x00,0x80,0xC0,0xE0,0xF0,0xF8,0xFC,0xFE,0xFF,0x7F,0x3F,0x1F,0x0F,0x07, 0x03, 0x01};

void setup(void)
{
    DDRD = 0xFF;
    ctr = 0;
    len = sizeof(md) / sizeof(byte);
}

void loop(void)
{
    if(millis() % TIME == 0)
    {
        PORTD = md[ctr];
        ctr++;
        if(ctr == len)
            ctr = 0;
    }
}
