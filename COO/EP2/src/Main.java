import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		Menu menu = new Menu(ler);
		menu.menuPrincipal();
		ler.close();
	}
}
