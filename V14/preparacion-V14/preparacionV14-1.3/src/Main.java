
public class Main {

	public static void main(String[] args) {
		String nombre, apellido, nombreCompleto, datosCompletos;
		int edad;
		float estatura;
		
		nombre = "Christian Alejandro";
		apellido = "Ramos Pérez";
		edad = 23;
		estatura = 1.77f;
		nombreCompleto = nombre + " " + apellido;
		datosCompletos = "\n Nombre:" + nombreCompleto + "\n Edad: " + edad + " años" + "\n Estatura: " + estatura + "mts";
		System.out.print("\n Tu datos completos son\n");
		System.out.print(datosCompletos);
	}

}
