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
	if (Serial1.available()>=2) //se espera hasta que existan datos que leer
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
    // else
    // {
    //     return -1;
    // }
}

int hexToByte (char a, char b){
    //Serial.println(a);
    int first = charToDigit(a);
    //Serial.println(first);

    //Serial.println(a);
    int secon = charToDigit(b);
    //Serial.println(secon);

    
    return first * 16+secon;
}
