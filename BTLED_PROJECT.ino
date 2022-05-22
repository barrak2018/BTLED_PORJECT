String code = "";
int redLED;
int greenLED;
int blueLED;
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
        code ="";
        code=Serial1.readString();
        Serial.println(code);
        

    }
    


    
}

