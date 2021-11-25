package operacoes;
public class Carrega extends Operacao {
	
	public int registrador;
	
	public int valor;

	public Carrega(int registrador, int valor) {
		validaParam(registrador);
		this.registrador = registrador;
		this.valor = valor;
	}
}
