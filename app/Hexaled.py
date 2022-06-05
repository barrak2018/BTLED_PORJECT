
import serial
try:
    bt = serial.Serial("con11",9600)

    print ("hexaled hex generator")
    print("solo usar valores entre 0 y 255")
    Rojo=int(input("ingrese el valor del color Rojo:  "))
    Verde=int(input("ingrese el valor del color Verde:  "))
    Azul=int(input("ingrese el valor del color Azul:  "))

    if (Rojo<=255 and Verde<=255 and Azul<=255)and(Rojo>=0 and Verde>=0 and Azul>=0):
    
      CODE=f"{Rojo:02x}{Verde:02x}{Azul:02x}"

    else:
        print("error de formato")




except TimeoutError:
    print("error")
finally:
    print("done")