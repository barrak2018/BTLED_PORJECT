# 1 "c:\\Users\\josee\\Documents\\Arduino\\Bluetooth\\BTLED_PORJECT\\bluetooth.ino"
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
        Serial.println("codigo obtenido --------->   ");
        Serial.println(code);

    }


}
