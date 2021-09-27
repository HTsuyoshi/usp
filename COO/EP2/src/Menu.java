import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Scanner;
import java.util.List;

import java.util.InputMismatchException;

public class Menu {
	
	/*
	 * Classe Menu vai servir como a interface principal que o usuario vai lidar
	 * a classe Menu vai gerenciar as classes MarcadorDeReuniao e GerenciadorDeSalas
	 */
	
	Scanner ler;
	MarcadorDeReuniao marcadorDeReuniao;
	GerenciadorDeSalas gerenciadorDeSala;
	
	Menu(Scanner ler) {
		this.ler = ler;
		gerenciadorDeSala = null;
		marcadorDeReuniao = null;
	}
	
	/*
	 * Mostrar as escolhas do menu principal
	 */
	
	public int imprimirMenuSelecao() {
		System.out.println("\n--------------------");
		System.out.println("1 - Marcar reuniao\n2 - Ver reuniao marcada\n3 - Adicionar sala");
		System.out.println("4 - Remover sala\n5 - Ver salas\n6 - Adicionar reserva");
		System.out.println("7 - Mostrar reservas\n0 - Sair do programa\n");
		System.out.println("--------------------");
		System.out.print("Entrada: ");
		int escolha = this.receberInteiro();
		return escolha;
	}
	
	/*
	 * Tratar as escolhas do menu principal
	 */
	
	public void menuPrincipal() {
		int opcao = -1;
		while (opcao != 0) {
			opcao = this.imprimirMenuSelecao();
			switch(opcao) {
				case 0:
					return;
					
				case 1:
					this.marcarReuniao();
					break;
					
				case 2:
					this.mostrarReuniao();
					break;
					
				case 3:
					this.gerenciadorDeSalas();
					break;
					
				case 4:
					if(this.gerenciadorDeSala == null) {
						System.out.println("Não foram criadas salas");
						continue;
					}
					this.removerSala();
					break;
					
				case 5:
					if(this.gerenciadorDeSala == null) {
						System.out.println("Não foram criadas salas");
						continue;
					}
					this.verSalas();
					break;

				case 6:
					if(this.gerenciadorDeSala == null) {
						System.out.println("Não foram criadas salas");
						continue;
					}
					this.adicionarReserva();
					break;
					
				case 7:
					if(this.gerenciadorDeSala == null) {
						System.out.println("Não foram criadas salas");
						continue;
					}
					this.verReservas();
					break;
					
				default:
					continue;
			}
		}
	}
	
	// OPCAO 1

	/*
	 * Marcar uma reuniao
	 */
	
	public void marcarReuniao() {
		this.marcadorDeReuniao = new MarcadorDeReuniao();
		
		imprimirSeparador("\nEscolha os participantes");
		Collection<String> participantes = this.escolherParticipantes();
		this.marcadorDeReuniao.instanciarParticipantes(participantes);
		this.marcadorDeReuniao.instanciarDisponibilidade();
		imprimirSeparador("Coloque o horário dos participantes");
		for (String participante : participantes) {
			LocalDateTime inicio = LocalDateTime.MAX;
			LocalDateTime fim = LocalDateTime.MIN;
			while(inicio.isAfter(fim)) {
				System.out.printf("\nHorario para o participante %s\n", participante);
				System.out.println("\nEscolha o horario inicial\n");
				inicio = this.escolherHorario();
				System.out.println("\nEscolha o horario final\n");
				fim = this.escolherHorario();
				if(inicio.isAfter(fim)) {
					System.err.println("O horario incial precisa ser antes do horario final.");
				}
			}
			this.marcadorDeReuniao.indicaDisponibilidadeDe(participante, inicio, fim);
		}
		this.marcadorDeReuniao.mostrarSobreposicao();
		
		LocalDateTime inicio = LocalDateTime.MAX;
		LocalDateTime fim = LocalDateTime.MIN;
		while(inicio.isAfter(fim)) {
			imprimirSeparador("\nEscolha o horário da reunião");
			System.out.println("\nEscolha o horario inicial\n");
			inicio = this.escolherHorario();
			System.out.println("\nEscolha o horario final\n");
			fim = this.escolherHorario();
			if(inicio.isAfter(fim)) {
				System.err.println("O horario incial precisa ser antes do horario final.");
			}
		}
		System.out.println("\nOs participantes que podem participar da reuniao são:\n");
		for(String participante : this.marcadorDeReuniao.listaDeParticipantes) {
			System.out.println(participante);
		}
	}
	
	/*
	 * Menu dos participantes
	 */
	
	public int imprimirParticipantes() {
		imprimirSeparador("1 - Adicionar participante\n0 - Terminar");
		System.out.println("--------------------");
		System.out.print("Entrada: ");
		int escolha = this.receberInteiro();
		return escolha;
	}

	/*
	 * Trata e recebe os participantes
	 */
	
	public Collection<String> escolherParticipantes() {
		Collection<String> participantes = new ArrayList<String>();
		int entrada = 1, qntPart = 1;
		while(entrada != 0) {
			if(entrada == 1) {
				System.out.printf("\nParticipante %d: ", qntPart);
				String participante = ler.nextLine();
				qntPart++;
				participantes.add(participante);
			}
			entrada = imprimirParticipantes();
		}
		return participantes;
	}
	
	
	// OPCAO 2

	/*
	 * Mostra a ultima reuniao que foi marcada
	 */
	
	public void mostrarReuniao() {
		if(this.marcadorDeReuniao == null) {
			System.out.println("\n--------------------");
			System.out.println("Ainda não foi marcada nenhuma reuniao");
			return;
		}
		DateTimeFormatter formatador = DateTimeFormatter.ofPattern("dd MMM uuuu HH:MM");
		System.out.println("\n--------------------");
		System.out.printf("A última reunião marcada foi das %s até as %s\n",
				formatador.format(this.marcadorDeReuniao.dataInicial), formatador.format(this.marcadorDeReuniao.dataFinal));

		System.out.println("Os participantes dessa reuniao são:\n");
		for(String participantes : this.marcadorDeReuniao.listaDeParticipantes)
			System.out.println(participantes);
	}

	/*
	 * Imprimir as informacoes da sala de uma forma organizada
	 */
	
	public void imprimirSala(Sala sala) {
		System.out.println("\nSala: " + sala.getNome());
		System.out.println("Capacidade: " + sala.getCapacidadeMaxima());
		System.out.println("Local: " + sala.getLocal());
		System.out.println("Observacao: " + sala.getObservacoes());
		System.out.println();
	}
	
	// OPCAO 3
	
	/*
	 * Adicionar uma sala
	 */
	
	public void gerenciadorDeSalas() {
		if(this.gerenciadorDeSala == null) this.gerenciadorDeSala = new GerenciadorDeSalas();
		System.out.println("\n--------------------");
		System.out.print("Coloque o nome da nova sala: ");
		String nome = ler.nextLine();
		System.out.print("Coloque a capacidade da nova sala: ");
		int capacidadeMax = this.receberInteiro();
		System.out.print("Coloque a descrição da nova sala (No formato \"local:observacao\": ");
		String descricaoDaSala = ler.nextLine();
		this.gerenciadorDeSala.adicionaSalaChamada(nome, capacidadeMax, descricaoDaSala);
		
	}
	
	// OPCAO 4

	/*
	 * Remover a sala especificada pelo usuario
	 */
	
	public void removerSala() {
		System.out.println("\n--------------------");
		System.out.print("Coloque o nome da sala que vai ser removida: ");
		String nome = ler.nextLine();
		this.gerenciadorDeSala.removeSalaChamada(nome);
		System.out.println("A sala foi removida com sucesso");
	}
	
	// OPCAO 5
	
	/*
	 * Mostra todas as salas existentes
	 */
	
	public void verSalas() {
		List<Sala> salas = gerenciadorDeSala.listaDeSalas();
		if(salas.isEmpty()) {
			System.out.println("Não foram criadas salas");
			return;
		}
		System.out.println("As salas existentes são:");
		for(Sala sala : salas) {
			imprimirSala(sala);
		}
	}
	
	// OPCAO 6
	
	/*
	 * Cria uma reserva em uma sala
	 */
	
	public void adicionarReserva() {
		System.out.print("Coloque o nome da sala que quer reservar: ");
		String sala = ler.nextLine();
		LocalDateTime inicio = LocalDateTime.MAX;
		LocalDateTime fim = LocalDateTime.MIN;
		while(inicio.isAfter(fim)) {
			System.out.println("\nEscolher um horario para reservar");
			System.out.println("\nEscolha o horario inicial\n");
			inicio = this.escolherHorario();
			System.out.println("\nEscolha o horario final\n");
			fim = this.escolherHorario();
			if(inicio.isAfter(fim)) {
				System.err.println("O horario incial precisa ser antes do horario final.");
			}
		}
		gerenciadorDeSala.reservaSalaChamada(sala, inicio, fim);
	}
	
	// OPCAO 7
	
	/*
	 * Imprime todas as reservas da sala recebida pelo Scanner
	 */
	
	public void verReservas() {
		System.out.print("Coloque o nome da sala que quer ver as reservas: ");
		String sala = ler.nextLine();
		gerenciadorDeSala.imprimeReservasDaSala(sala);
	}
	
	// Funcoes abaixo sao funcoes auxiliares genericas que tratam entradas e saida
	
	/*
	 * Verificar se foi escolhido um dia valido
	 * 
	 *  @param ano: representa o ano escolhido pelo usuario
	 *  @param mes: representa o mes escolhido pelo usuario
	 */
	
	public int verificarDia(int ano, int mes) {
		if(mes < 8) {
			if(mes == 2) {
				if(ano % 4 == 0 && ano % 100 != 0) return 29;
				return 28;
			}
			if(mes % 2 == 1) return 31;
			return 30;
		}
		if(mes % 2 == 1) return 30;
		return 31;
	}

	
	/*
	 * Recebe os horarios Ano, mes, dia, hora e minuto
	 */
	
	public LocalDateTime escolherHorario() {
		int[] localTime = new int[5];
		int[] limite = {999999999, 12, 0, 23, 59};
		String[] mensagem = {"Ano: ", "Mes: ", "Dia: ", "Hora: ", "Minuto: "};
		for(int i=0; i<5; i++) {
			int entrada = -1;
			if(i == 2) limite[2] = verificarDia(localTime[0], localTime[1]);
			while(entrada < 1 || entrada > limite[i]) {
				System.out.print(mensagem[i]);
				entrada = this.receberInteiro();
				if(entrada == -1) continue;
			}
			localTime[i] = entrada;
		}
		return LocalDateTime.of(localTime[0], localTime[1], localTime[2], 
							localTime[3], localTime[4]);
	}
	
	/*
	 * Funcao para tratar os erros de entrada
	 */
	
	public int receberInteiro() {
		try {
			int escolha = ler.nextInt();
			ler.nextLine();
			return escolha;
		} catch (InputMismatchException e) {
			System.err.println("A entrada precisa ser um inteiro");
			ler.nextLine();
			return -1;
		}
	}
	
	/*
	 * Imprimir instrucoes
	 */
	
	public void imprimirSeparador(String frase) {
		System.out.println("\n--------------------");
		System.out.println(frase + "\n");
	}
}
