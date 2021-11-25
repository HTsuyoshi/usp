package kernel;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

import operacoes.Carrega;
import operacoes.Operacao;
import operacoes.OperacaoES;
import operacoes.Soma;

public abstract class SO {

	protected Processador processador = new Processador();
	private HashMap<Integer, Operacao[]> novosProcessos = new HashMap<Integer, Operacao[]>();
	private int contadorCiclos = 0;

	public enum Escalonador {
		FIRST_COME_FIRST_SERVED, // não preemptivo
		SHORTEST_JOB_FIRST, // não preemptivo (média exponencial comecando em 5)
		SHORTEST_REMANING_TIME_FIRST, // preemptivo (média exponencial comecando em 5)
		ROUND_ROBIN_QUANTUM_5, // preemptivo
		SRTFBC // preemptivo
	}

	public void simula() {
		while (!novosProcessos.isEmpty() || temTarefasPendentes()) {
			Operacao[] codigo = novosProcessos.get(contadorCiclos);

			if (codigo != null) {
				novosProcessos.remove(contadorCiclos);
				criaProcesso(codigo);
			}

			executaUmCiclo();
			//imprimeEstado();
		}

		imprimeEstatisticas();
	}

	private void imprimeEstatisticas() {
		//System.out.println();
		//System.out.println("============ Estatísticas ============");
		System.out.println("Tempo de retorno médio: " + tempoRetornoMedio());
		System.out.println("Tempo de resposta médio: " + tempoRespostaMedio());
		System.out.println("Tempo de espera médio: " + tempoEsperaMedio());
		System.out.println("Trocas de contexto: " + trocasContexto());
		//System.out.println("======================================");
	}

	private void imprimeEstado() {
		System.out.println();
		System.out.println("                    ---- x ----");
		System.out.println();
		System.out.println("Ciclo: " + contadorCiclos);

		if (idProcessoNovo() != null)
			System.out.println("Processo novo: " + idProcessoNovo());

		if (idProcessoExecutando() != null)
			System.out.println("Processo executando: " + idProcessoExecutando());

		System.out.print("Processos prontos: ");

		for (Integer id : idProcessosProntos()) {
			System.out.print(id + " ");
		}

		System.out.print("Processos esperando: ");

		for (Integer id : idProcessosEsperando()) {
			System.out.print(id + " ");
		}

		System.out.print("Processos terminados: ");

		for (Integer id : idProcessosTerminados()) {
			System.out.print(id + " ");
		}
	}

	private void executaUmCiclo() {
		executaCicloKernel();
		executaUmCicloCPU();
		executaUmCicloES();
		contadorCiclos++;
	}

	private void executaUmCicloCPU() {
		Operacao op = proximaOperacaoCPU();
		processador.executa(op);
	}

	private void executaUmCicloES() {
		for (int i = 0; i < 5; i++) {
			OperacaoES op = proximaOperacaoES(i);

			if (op != null && op.ciclos > 0)
				op.ciclos--;
		}
	}

	public void leArquivoEntrada(String arq) throws FileNotFoundException {
		Scanner in = new Scanner(new File(arq));
		int nProcessos = in.nextInt();

		for (int i = 0; i < nProcessos; i++) {
			int instanteChegada = in.nextInt();
			int nOperacoes = in.nextInt();
			Operacao[] codigo = new Operacao[nOperacoes];

			for (int j = 0; j < nOperacoes; j++) {
				int codOp = in.nextInt();

				if (codOp == 1) {
					codigo[j] = new OperacaoES(in.nextInt(), in.nextInt());
				} else if (codOp == 2) {
					codigo[j] = new Carrega(in.nextInt(), in.nextInt());
				} else if (codOp == 3) {
					codigo[j] = new Soma(in.nextInt(), in.nextInt(), in.nextInt());
				} else {
					throw new RuntimeException("Código de operacão inválido");
				}
			}

			if (novosProcessos.containsKey(instanteChegada)) {
				throw new RuntimeException("Só pode chegar no máximo um processo a cada instante");
			}

			novosProcessos.put(instanteChegada, codigo);
		}
	}

	protected abstract void criaProcesso(Operacao[] codigo);

	protected abstract void trocaContexto(PCB pcbAtual, PCB pcbProximo);

	// Assuma que 0 <= idDispositivo <= 4
	protected abstract OperacaoES proximaOperacaoES(int idDispositivo);

	protected abstract Operacao proximaOperacaoCPU();

	protected abstract void executaCicloKernel();

	protected abstract boolean temTarefasPendentes();

	protected abstract Integer idProcessoNovo();

	protected abstract List<Integer> idProcessosProntos();

	protected abstract Integer idProcessoExecutando();

	protected abstract List<Integer> idProcessosEsperando();

	protected abstract List<Integer> idProcessosTerminados();

	protected abstract int tempoEsperaMedio();

	protected abstract int tempoRespostaMedio();

	protected abstract int tempoRetornoMedio();
	
	protected abstract int trocasContexto();
	
	public abstract void defineEscalonador(Escalonador e);
}
