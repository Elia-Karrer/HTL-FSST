#define TIME 500
byte mode, ctr;
byte ctr;

void setup(void)
{
    DDRD = 0xFF;
    mode = 0xC0;
    ctr = 0;
}

void loop(void)
{
    if(millis() % TIME == 0)
    {
        mode = (ctr < 5) ? mode >> 1 : mode << 1;
        PORTD = mode;
        ctr++;
        if(ctr == 12)
            ctr = 0;
    }
}
