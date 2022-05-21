String code = "";
void setup()
{
	Serial.begin(9600);
    Serial1.begin(9600);
    Serial.println("System Online");
}

void loop()
{
	if (Serial1.available())
    {
        char c;
        while (Serial1.available()>0)
        {
            c=Serial1.read();
            if ((c!='\n')&&(c!='\r'))
            {
                code.concat(c);
            }
            
        }
        Serial.printl("codigo obtenido --------->   ");
        Serial.println(code);
        
    }

    
}
