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
	if (Serial1.available()>=6) //se espera hasta que existan datos que leer
    {
        code ="";
        code=Serial1.readString();//se almacena toda la cadena en la variable code 
        Serial.println(code);//linea de testeo
    }    
}

int charToDigit (char c){
    if ((c >= '0')&&(c <= '9'))
    {
        return c - '0';
    } 
    else if ((c >= 'A')&&(c <= 'F'))
    {
        return c - 'A';
    } 
    else if ((c >= 'a')&&(c <= 'f'))
    {
        return c - 'a';
    } 
    else
    {
        return -1;
    }
}

int hexToByte (char a, char b){

}
