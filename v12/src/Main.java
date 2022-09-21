import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner cin;
		cin = new Scanner(System.in);
		byte edad;
		float estaturaMetros;
		System.out.println("Datos personales");
		System.out.printf("Dame tu edad: ");
		edad = cin.nextByte();
		System.out.printf("Dame tu estatura:");
		estaturaMetros=cin.nextFloat();
		cin.close();
		
		System.out.println("Edad: " + edad);
		System.out.println("Estatara: " + estaturaMetros);
		
	}

}
