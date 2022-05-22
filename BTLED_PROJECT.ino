String code = "";
void setup()
{
	Serial.begin(9600);
    Serial1.begin(9600);
    Serial.println("System Online");
}

void loop()
{
	if (Serial1.available()>=6)
    {
        code = Serial1.readString();
        Serial.println(code);
        
    }

    
}
