#define TIME 500
byte ctr;

void setup(void)
{
    DDRD = 0xFF;
    ctr = 0;
}

void loop(void)
{
    if(millis() % TIME == 0)
    {
        PORTD = (1 << (mode+1)) - 1;
        ctr++;
        if(ctr == 7)
            ctr = 0;
    }
}
