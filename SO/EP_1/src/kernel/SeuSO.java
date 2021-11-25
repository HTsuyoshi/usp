package kernel;
import java.util.List;

import operacoes.Operacao;
import operacoes.OperacaoES;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.HashMap;
import java.util.Comparator;
import java.util.Collections;

import static kernel.SO.Escalonador.*;
import static kernel.SO.Escalonador.SRTFBC;

class ComparadorId implements Comparator<PCB> {
	public int compare(PCB processo_1, PCB processo_2) {
		return processo_1.idProcesso - processo_2.idProcesso;
	}
}

class ComparadorSJF implements Comparator<PCB> {
	public int compare(PCB processo_1, PCB processo_2){
		if (processo_1.mediaExponencial == processo_2.mediaExponencial)
			return processo_1.idProcesso - processo_2.idProcesso;
		return processo_1.mediaExponencial - processo_2.mediaExponencial;
	}
}

public class SeuSO extends SO {

	public Queue<PCB> processosProntos;
	public HashMap<Integer, Queue<PCB>> processosEsperando;

	public PCB processoNovo = null;
	public PCB processoExecutando = null;
	public PCB processoRecem = null;
	public ArrayList<PCB> processosTerminado = new ArrayList<>();
	public PriorityQueue<PCB> adicionarListaDePronto = new PriorityQueue<>(new ComparadorId());

	public int processosCriados = 0;
	public int trocasDeContexto = 0;
	public int cicloAtual = 0;
	public int quantum = 5;

	public Escalonador escalonador;

	@Override
	// ATENCÃO: cria o processo mas o mesmo 
	// só estará "pronto" no próximo ciclo
	protected void criaProcesso(Operacao[] codigo) {
		if (this.escalonador == SRTFBC)
			processoRecem = new PCB(codigo, processosCriados, cicloAtual, quantum, true);
		else
			processoRecem = new PCB(codigo, processosCriados, cicloAtual, quantum);
		processosCriados++;
	}

	@Override
	protected void trocaContexto(PCB pcbAtual, PCB pcbProximo) {
		this.trocasDeContexto++;
		if (pcbAtual != null)
			System.arraycopy(processador.registradores, 0, pcbAtual.registradores, 0, 5);

		if (pcbProximo != null)
			System.arraycopy(pcbProximo.registradores, 0, processador.registradores, 0, 5);
	}

	@Override
	// Assuma que 0 <= idDispositivo <= 4
	protected OperacaoES proximaOperacaoES(int idDispositivo) {
		Queue<PCB> fila = processosEsperando.get(idDispositivo);
		if (fila.isEmpty()) return null;
		PCB processo = fila.peek();
		return (OperacaoES) processo.codigo[processo.contadorDePrograma];
	}

	@Override
	protected Operacao proximaOperacaoCPU() {
		if (processosProntos.isEmpty()) return null;
		else {
			PCB processo = processosProntos.peek();
			return processo.codigo[processo.contadorDePrograma];
		}
	}

	@Override
	protected void executaCicloKernel() {

		/* Contar espera */
		for (PCB processo : processosProntos) {
			processo.espera++;
		}

		/* Processos de ES */
		for (int i=0; i<5; i++) {
			Queue<PCB> fila = processosEsperando.get(i);
			if (fila.isEmpty()) continue;

			PCB processo = fila.peek();
			processo.contadorBurst++;

			/* Gastar um quantum */
			if (this.escalonador == ROUND_ROBIN_QUANTUM_5) {
				processo.quantum--;
			}

			/* Resposta de execucao */
			if (processo.resposta == -1)
				processo.resposta = cicloAtual;

			OperacaoES opES = (OperacaoES) processo.codigo[processo.contadorDePrograma];

			/* Acabou de executar a operacaoES */
			if (opES.ciclos == 0) {
				processo.contadorDePrograma++;
			} else {
				/* Nao acabou de executar a operacaoES */

				/* Se for um escalonador ROUND_ROBIN_QUANTUM_5 */
				if (this.escalonador == ROUND_ROBIN_QUANTUM_5 &&
						processo.quantum == 0) {
					processo.quantum = this.quantum;
					fila.remove();
					fila.add(processo);
				}

				continue;
			}

			/* Fim do processo */
			if (processo.contadorDePrograma == processo.codigo.length) {
				processo.retorno = cicloAtual;
				fila.remove();
				processo.estado = PCB.Estado.TERMINADO;
				processosTerminado.add(processo);

				/* Zerar os registradores do processador */
				for (int j=0; j<processador.registradores.length; j++)
					processador.registradores[j] = 0;

				continue;
			}

			Operacao op = processo.codigo[processo.contadorDePrograma];
			fila.remove();

			/* Fim da operacaoES */
			if (!(op instanceof OperacaoES)) {
				processo.calcularMedia(); // SJF e SRTF (Acabou o burst de ES)
				processo.estado = PCB.Estado.PRONTO;
				adicionarListaDePronto.add(processo);
			} else {
				opES = (OperacaoES) op;
				Queue<PCB> novaFila = processosEsperando.get(opES.idDispositivo);
				novaFila.add(processo);
			}

		}

		// Processo Executando
		if (processoExecutando != null) {

			if (this.escalonador == ROUND_ROBIN_QUANTUM_5) {
				processoExecutando.quantum--;
			}

			processoExecutando.contadorBurst++;
			processoExecutando.contadorDePrograma++;

			if (processoExecutando.resposta == -1)
				processoExecutando.resposta = cicloAtual;

			if (processoExecutando.contadorDePrograma == processoExecutando.codigo.length) {
				processoExecutando.retorno = cicloAtual;
				processoExecutando.estado = PCB.Estado.TERMINADO;
				processosTerminado.add(processoExecutando);

				/* Zerar os registradores do processador */
				for (int j=0; j<processador.registradores.length; j++)
					processador.registradores[j] = 0;

				processoExecutando = null;
			} else {
				Operacao op = processoExecutando.codigo[processoExecutando.contadorDePrograma];
				if (op instanceof OperacaoES) {
					if (this.escalonador == ROUND_ROBIN_QUANTUM_5) {
						processoExecutando.quantum = this.quantum;
					}
					processoExecutando.calcularMedia(); // (Acabou o burst de CPU)
					processoExecutando.estado = PCB.Estado.ESPERANDO;
					Queue<PCB> fila = processosEsperando.get(((OperacaoES) op).idDispositivo);
					fila.add(processoExecutando);
					processoExecutando = null;
				} else {

					if (this.escalonador == ROUND_ROBIN_QUANTUM_5 &&
							processoExecutando.quantum == 0) {
						processoExecutando.quantum = this.quantum;
						PCB preemptivo = processosProntos.peek();
						if (preemptivo != null) {
							processosProntos.remove();
							processoExecutando.estado = PCB.Estado.PRONTO;
							adicionarListaDePronto.add(processoExecutando);
							preemptivo.estado = PCB.Estado.EXECUTANDO;
							processoExecutando = preemptivo;
							trocaContexto(processoExecutando, preemptivo);
						}
					}

					if (this.escalonador == SHORTEST_REMANING_TIME_FIRST ||
							this.escalonador == SRTFBC) {
						PCB preemptivo = processosProntos.peek();
						if (preemptivo != null) {
							if (preemptivo.mediaExponencial < processoExecutando.mediaExponencial) {
								processosProntos.remove();
								processoExecutando.estado = PCB.Estado.PRONTO;
								adicionarListaDePronto.add(processoExecutando);
								preemptivo.estado = PCB.Estado.EXECUTANDO;
								processoExecutando = preemptivo;
								trocaContexto(processoExecutando, preemptivo);
							}
						}
					}

				}
			}
		}

		/* Arrumar os processos novos */
		if (processoNovo != null) {
			adicionarListaDePronto.add(processoNovo);
			processoNovo = null;
		}

		for (PCB processo : adicionarListaDePronto) {
			processo.estado = PCB.Estado.PRONTO;
			processosProntos.add(processo);
		}
		adicionarListaDePronto.clear();

		/* Arrumar os processos prontos */
		for (PCB processo : processosProntos) {
			Operacao op = processo.codigo[processo.contadorDePrograma];
			if (op instanceof OperacaoES) {
				processo.estado = PCB.Estado.ESPERANDO;
				Queue<PCB> fila = processosEsperando.get(((OperacaoES) op).idDispositivo);
				fila.add(processo);
			}
		}
		processosProntos.removeIf(pcb -> pcb.codigo[pcb.contadorDePrograma] instanceof OperacaoES);

		/* Se tiver nao tiver algum processo executando */
		if (processoExecutando == null) {
			/* Se tiver processos para usar a CPU */
			processoExecutando = processosProntos.poll();
			if (processoExecutando != null)
				processoExecutando.estado = PCB.Estado.EXECUTANDO;
		}

		/* Colocar na fila de prontos caso tenha um processo novo */
		if (processoRecem != null) processoNovo = processoRecem;
		processoRecem = null;


		cicloAtual++;
	}

	@Override
	protected boolean temTarefasPendentes() {
		return processoExecutando != null ||
				processoNovo != null ||
				processoRecem != null ||
				!processosProntos.isEmpty() ||
				!processosEsperando.get(0).isEmpty() ||
				!processosEsperando.get(1).isEmpty() ||
				!processosEsperando.get(2).isEmpty() ||
				!processosEsperando.get(3).isEmpty() ||
				!processosEsperando.get(4).isEmpty();
	}

	@Override
	protected Integer idProcessoNovo() {
		return processoNovo == null ? null : processosCriados - 1;
	}

	@Override
	protected List<Integer> idProcessosProntos() {
		ArrayList<Integer> prontos = new ArrayList<>();
		for (PCB processo : processosProntos) {
			prontos.add(processo.idProcesso);
		}
		Collections.sort(prontos);
		return prontos;
	}

	@Override
	protected Integer idProcessoExecutando() {
		return processoExecutando != null ? processoExecutando.idProcesso : null;
	}

	@Override // Perguntei pro prof
	protected List<Integer> idProcessosEsperando() {
		ArrayList<Integer> esperando = new ArrayList<>();
		for (int i=0; i<5; i++) {
			Queue<PCB> fila = processosEsperando.get(i);
			if (fila.isEmpty()) continue;
			for (PCB processo : fila) {
				esperando.add(processo.idProcesso);
			}
		}
		Collections.sort(esperando);
		return esperando;
	}

	@Override
	protected List<Integer> idProcessosTerminados() {
		ArrayList<Integer> terminou = new ArrayList<>();
		for (PCB processo : processosTerminado) {
			terminou.add(processo.idProcesso);
		}
		Collections.sort(terminou);
		return terminou;
	}

	@Override
	protected int tempoEsperaMedio() {
		int medioEspera = 0,
				total = 0;

		for (PCB processo : processosTerminado) {
			medioEspera += processo.espera;
			total++;
		}

		return medioEspera/total;
	}

	@Override
	protected int tempoRespostaMedio() {
		int mediaResposta = 0,
				total = 0;

		for (PCB processo : processosTerminado) {
			mediaResposta += processo.resposta - processo.tempoDeChegada;
			total++;
		}

		return mediaResposta/total;
	}

	@Override
	protected int tempoRetornoMedio() {
		int mediaRetorno = 0,
			total = 0;

		for (PCB processo : processosTerminado) {
			mediaRetorno += processo.retorno - processo.tempoDeChegada;
			total++;
		}

		return mediaRetorno/total;
	}

	@Override
	protected int trocasContexto() {
		return this.trocasDeContexto;
	}

	@Override
	public void defineEscalonador(Escalonador e) {
		switch (e) {
			case FIRST_COME_FIRST_SERVED:
				escalonador = FIRST_COME_FIRST_SERVED;
				processosProntos = new LinkedList<>();
				processosEsperando = new HashMap<>();
				for (int i = 0; i < 5; ++i) {
					processosEsperando.put(i, new LinkedList<>());
				}
				break;
			case SHORTEST_REMANING_TIME_FIRST:
				escalonador = SHORTEST_REMANING_TIME_FIRST;
				processosProntos = new PriorityQueue<>(new ComparadorSJF());
				processosEsperando = new HashMap<>();
				for (int i = 0; i < 5; ++i) {
					processosEsperando.put(i, new PriorityQueue<>(new ComparadorSJF()));
				}
				break;
			case ROUND_ROBIN_QUANTUM_5:
				escalonador = ROUND_ROBIN_QUANTUM_5;
				processosProntos = new LinkedList<>();
				processosEsperando = new HashMap<>();
				for (int i = 0; i < 5; ++i) {
					processosEsperando.put(i, new LinkedList<>());
				}
				break;
			case SHORTEST_JOB_FIRST:
				escalonador = SHORTEST_JOB_FIRST;
				processosProntos = new PriorityQueue<>(new ComparadorSJF());
				processosEsperando = new HashMap<>();
				for (int i = 0; i < 5; ++i) {
					processosEsperando.put(i, new PriorityQueue<>(new ComparadorSJF()));
				}
				break;
			case SRTFBC:
				escalonador = SRTFBC;
				processosProntos = new PriorityQueue<>(new ComparadorSJF());
				processosEsperando = new HashMap<>();
				for (int i = 0; i < 5; ++i) {
					processosEsperando.put(i, new PriorityQueue<>(new ComparadorSJF()));
				}
				break;
		}
	}
}