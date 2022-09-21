
public class Main {

	public static void main(String[] args) {
		int a, b ,c , aux;
		
		a = 10;
		b = 15;
		c = 20;
		
		System.out.println("Valores iniciales\n");
		System.out.println("A = " + a);
		System.out.println("B = " + b);
		System.out.println("C = " + c);
		
		aux = c;
		
		c = b;
		b = a;
		a = aux;
		
		System.out.println("\nValores modicados\n");
		System.out.println("A = " + a);
		System.out.println("B = " + b);
		System.out.println("C = " + c);
		
	}

}
