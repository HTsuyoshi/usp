import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.List;

import kernel.SO;
import kernel.SO.Escalonador;
import kernel.SeuSO;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		List<Escalonador> escalonadores = new LinkedList<>();	
		escalonadores.add(SO.Escalonador.FIRST_COME_FIRST_SERVED);
		escalonadores.add(SO.Escalonador.SHORTEST_JOB_FIRST);
		escalonadores.add(SO.Escalonador.SHORTEST_REMANING_TIME_FIRST);
		escalonadores.add(SO.Escalonador.ROUND_ROBIN_QUANTUM_5);
		escalonadores.add(SO.Escalonador.SRTFBC);

		for(Escalonador esc : escalonadores) {
			System.out.println(esc.toString());
			for (int i = 0; i <= 24; i++) {
				SO so = new SeuSO();
				so.defineEscalonador(esc);
				try {
					String arquivo = "/home/azz/tmp/final/SO/entradas/teste" + i + ".txt";
					so.leArquivoEntrada(arquivo);
					System.out.println("TESTE " + i);
					so.simula();
				} catch (FileNotFoundException e) {
				}
			}
		}

	}
}
