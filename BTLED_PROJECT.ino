String code = "";
int redLED = 2;
int greenLED = 3;
int blueLED = 4;
void setup()
{
	Serial.begin(9600);
    Serial1.begin(9600);
    Serial.println("System Online");
}
void loop()
{
	if (Serial1.available()>=6) //se espera hasta que existan datos que leer
    {
        //-------------------------------------------------------------------------
        code ="";
        code=Serial1.readString();//se almacena toda la cadena en la variable code 
        
        //-------------------------------------------------------------------------
        Serial.print("codigo de color ---------->  ");
        Serial.println(code);
        //-------------------------------------------------------------------------
        char code2 [code.length()+1];
        code.toCharArray(code2,code.length()+1);
        
        int red = hexToByte(code2[0],code2[1]);
        Serial.println(red);
        int green = hexToByte(code2[2],code2[3]);
        Serial.println(green);
        int blue = hexToByte(code2[4],code2[5]);
        Serial.println(blue);

        if (red < 0)
        {
            red = 0;
            green = 0;
            blue = 0;
            Serial.println("Error de Convercion");
        }
        else if (green < 0)
        {
            red = 0;
            green = 0;
            blue = 0;
            Serial.println("Error de Convercion");
        }
        else if (blue < 0)
        {
            red = 0;
            green = 0;
            blue = 0;
            Serial.println("Error de Convercion");
        }
        
        
        
        
        
    }

}

int charToDigit (char c){
    if ((c >= '0')&&(c <= '9'))
    {
        return c - '0';
    } 
    else if ((c >= 'A')&&(c <= 'F'))
    {
        return 10 + c - 'A';
    } 
    else if ((c >= 'a')&&(c <= 'f'))
    {
        return 10 + c - 'a';
    } 
    else
    {
        return -1;
    }
}

int hexToByte (char a, char b){
    //Serial.println(a);
    int first = charToDigit(a);
    //Serial.println(first);

    //Serial.println(a);
    int secon = charToDigit(b);
    //Serial.println(secon);

    if ((first < 0)||(secon < 0))
    {
        return -1;
    }
    
    return first * 16+secon;
}
