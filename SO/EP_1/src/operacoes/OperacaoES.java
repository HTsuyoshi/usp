package operacoes;

public class OperacaoES extends Operacao {

	public int idDispositivo;
	
	public int ciclos;

	public OperacaoES(int idDispositivo, int ciclos) {
		validaParam(idDispositivo);
		
		if(ciclos <= 0) {
			throw new RuntimeException("Número de ciclos de E/S deve ser positivo");
		}
		
		this.idDispositivo = idDispositivo;
		this.ciclos = ciclos;
	}
}
