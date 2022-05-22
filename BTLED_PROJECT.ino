String code = "";
int redLED = 2;
int greenLED = 3;
int blueLED = 4;
void setup()
{
	Serial.begin(9600);//comunicacion serial con el monitor de la pc
    Serial1.begin(9600);// comunicacion con el modulo Bluetooth HC-05 
    Serial.println("System Online");//linea de control
}
void loop()
{
	if (Serial1.available()>=6) //se espera hasta que existan datos que leer
    {
        //-------------------------------------------------------------------------
        code ="";
        code=Serial1.readString();//se almacena toda la cadena en la variable code 
        
        //-------------------lineas de control del programa------------------------

        Serial.print("codigo de color ---------->  ");
        Serial.println(code);

        //--------------------se crea un array y se guardan los datos de code------
        
        char code2 [code.length()+1];
        code.toCharArray(code2,code.length()+1);

        /*--------------------decodificacion del codigo Hexadecimal----------------
                               declaracion de los valores de color                
        */

        int red = hexToByte(code2[0],code2[1]);
        Serial.println(red);
        int green = hexToByte(code2[2],code2[3]);
        Serial.println(green);
        int blue = hexToByte(code2[4],code2[5]);
        Serial.println(blue);

        //-------------------validacion de datos y asignacion de valores de color-----------------------------------
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
        else 
        {

        }
    }
}
/* charToDigit cnvierte un caracter en su valor decimal en base al codigo exadecimal*/
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
/* hexToByte convierte dos caracteres de un codigo hexadecimal en su valor de base 10*/
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