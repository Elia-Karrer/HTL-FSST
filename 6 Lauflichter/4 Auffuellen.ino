#define TIME 500

byte ctr = 0, values[37] = {0};

void setup(void)
{
    uint8_t i, j, value;
    
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8-i; j++)
        {
            if(j != 0)
                value &= ~(1<<(7-(j-1)));
            value |= 1<<(7-j);
            values[ctr+1] = value;
            ctr++;
        }
    
    DDRD = 0xFF;
    ctr = 0;
}

void loop(void)
{
    if(millis() % TIME == 0)
    {
        PORTD = values[ctr];

        ctr++;
        if(ctr == 37)
            ctr = 0;
    }
}
