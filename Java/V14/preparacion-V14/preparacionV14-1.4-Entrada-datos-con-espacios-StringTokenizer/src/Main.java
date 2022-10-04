import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		String nombre, apellido, nombreCompleto, datosCompletos, primerNombre, segundoNombre, primerApellido, segundoApellido;
		int edad;
		float estatura;
		Scanner consola;
		consola = new Scanner(System.in);
		StringTokenizer separadorPalabras;
		System.out.printf("Dame tú(s) nombre: ");
		nombre = consola.nextLine();
		System.out.printf("Dame tus apellidos: ");
		apellido = consola.nextLine();
		consola.close();
		edad = 23;
		estatura = 1.77f;
		nombreCompleto = nombre + " " + apellido;
		datosCompletos = "\nNombre:" + nombreCompleto + "\nEdad: " + edad + "años" + "\nEstatura: " + estatura + "mts";
		
		System.out.print("\n Tu datos completos son:");
		System.out.print(datosCompletos);
		
		System.out.printf(" \n\n Datos separados \n");
		
		separadorPalabras = new StringTokenizer(nombre); //Nos ayudara a gurdar el string con espacios
		primerNombre = separadorPalabras.nextToken();//Nos permite separar un pedaso que se encuentre antes del primer espacio en el string
		segundoNombre = separadorPalabras.nextToken();
		
		separadorPalabras = new StringTokenizer(apellido);
		primerApellido = separadorPalabras.nextToken();
		segundoApellido = separadorPalabras.nextToken();
		
		System.out.println("Primer nombre: " + primerNombre);
		System.out.println("Segundo nombre: " + segundoNombre);
		System.out.println("Primer apellido: " + primerApellido);
		System.out.println("Segundo apellido: " + segundoApellido);
	}

}
