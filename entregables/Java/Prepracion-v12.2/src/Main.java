import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		final int EDAD_MINIMA=21;
		final int EDAD_MAXIMA=120;
		Scanner cin;
		cin = new Scanner(System.in);
		byte edad1,edad2;
		float estaturaMetros1,estaturaMetros2;
		
		System.out.println("Datos personales\n");
		
		System.out.println("Primer persona");
		System.out.printf("Dame su edad (en años de %d a %d): ", EDAD_MINIMA, EDAD_MAXIMA);
		edad1 = cin.nextByte();
		System.out.printf("Dame su estatura:");
		estaturaMetros1=cin.nextFloat();
		
		System.out.println("\nSegunda persona");
		System.out.printf("Dame su edad (en años de %d a %d): ", EDAD_MINIMA, EDAD_MAXIMA);
		edad2 = cin.nextByte();
		System.out.printf("Dame su estatura:");
		estaturaMetros2=cin.nextFloat();
		
		cin.close();
		
		System.out.println("\nLos datos cpaturados son\n");
		
		System.out.println("Datos de la primera persona");
		System.out.println("Edad: " + edad1);
		System.out.println("Estatara: " + estaturaMetros1);
		System.out.println("\nDatos de la segunda persona");
		System.out.println("Edad: " + edad2);
		System.out.println("Estatara: " + estaturaMetros2);

	}

}
