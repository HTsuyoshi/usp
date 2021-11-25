package kernel;
import operacoes.Carrega;
import operacoes.Operacao;
import operacoes.Soma;

public class Processador {

	public int[] registradores = new int[5];

	public void executa(Operacao op) {
		if (op instanceof Carrega) {
			Carrega c = (Carrega) op;
			registradores[c.registrador] = c.valor;
		} else if (op instanceof Soma) {
			Soma s = (Soma) op;
			int a = registradores[s.registradorParcela1];
			int b = registradores[s.registradorParcela2]; 
			registradores[s.registradorTotal] = a + b;
		} else if (op == null) {
		} else {
			throw new RuntimeException("Operacão Inválida");
		}
	}
}
