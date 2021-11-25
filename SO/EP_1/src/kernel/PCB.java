package kernel;
import operacoes.Operacao;
import operacoes.OperacaoES;

public class PCB {
	public enum Estado {NOVO, PRONTO, EXECUTANDO, ESPERANDO, TERMINADO};
	public Estado estado = Estado.NOVO;
	public int idProcesso; // primeiro processo criado deve ter id = 0
	public int[] registradores = new int[5];
	public int contadorDePrograma = 0;
	public Operacao[] codigo;

	// Todos
	public int tempoDeChegada;
	public int espera = 0;
	public int resposta = -1;
	public int retorno = 0;

	// Preemptivo
	public int mediaExponencial = 5;
	public int contadorBurst = 0;
	public boolean bolaDeCristal = false;

	// RoundRobin
	public int quantum;

	PCB(Operacao[] codigo, int idProcesso, int tempoDeChegada, int quantum) {
		this.idProcesso = idProcesso;
		this.codigo = codigo;

		this.tempoDeChegada = tempoDeChegada;

		this.quantum = quantum;
	}

	PCB(Operacao[] codigo, int idProcesso, int tempoDeChegada, int quantum, boolean bolaDeCristal) {
		this.idProcesso = idProcesso;
		this.codigo = codigo;

		this.tempoDeChegada = tempoDeChegada;
		this.bolaDeCristal = true;

		this.quantum = quantum;
		usarBolaDeCristal();
	}

	void usarBolaDeCristal() {
		this.mediaExponencial = 0;
		Operacao op = this.codigo[contadorDePrograma];

		/*
		// Priorizando processos de CPU
		boolean opES = false;
		if (op instanceof OperacaoES)
			opES = true;

		for (int i=contadorDePrograma; i<codigo.length; i++) {
			mediaExponencial++;
			if (opES && !(codigo[i] instanceof OperacaoES)) break;
			if (!opES && (codigo[i] instanceof OperacaoES)) break;
		}
		 */


		// Contabilizando cada ciclo do burst de ES

		boolean opES = false;
		if (op instanceof OperacaoES)
			opES = true;

		if (opES) {
			mediaExponencial += ((OperacaoES) codigo[contadorDePrograma]).ciclos;
		} else {
			mediaExponencial++;
		}
		for (int i=contadorDePrograma + 1; i<codigo.length; i++) {
			if (opES) {
				if (!(codigo[i] instanceof OperacaoES)) {
					break;
				} else {
					mediaExponencial += ((OperacaoES) codigo[i]).ciclos;
				}
			} else {
				if (codigo[i] instanceof OperacaoES) {
					break;
				} else {
					mediaExponencial++;
				}
			}
		}

	}

	void calcularMedia() {
		if (bolaDeCristal) {
			usarBolaDeCristal();
		} else {
			this.mediaExponencial = (int) (this.mediaExponencial + this.contadorBurst) / 2;
			this.contadorBurst = 0;
		}
	}
}
