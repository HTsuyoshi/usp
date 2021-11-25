package operacoes;

public class Soma extends Operacao {

	public int registradorParcela1;

	public int registradorParcela2;

	public int registradorTotal;

	public Soma(int registradorParcela1, int registradorParcela2, int registradorTotal) {
		validaParam(registradorParcela1);
		validaParam(registradorParcela2);
		validaParam(registradorTotal);
		this.registradorParcela1 = registradorParcela1;
		this.registradorParcela2 = registradorParcela2;
		this.registradorTotal = registradorTotal;
	}
}
