package operacoes;

public class Operacao {

	protected void validaParam(int i) {
		if(i < 0 || i > 4) {
			throw new RuntimeException("Registradores e "
					+ "dispositivos devem estar entre 0 e 4");
		}
	}
}
