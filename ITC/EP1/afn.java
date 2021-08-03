//Henrique Tsuyoshi Yara (11796083) e Larissa Yurie Maruyama (11295928)

import java.io.*;
import java.util.*;

public class afn {

    public static void main(String args[]) {
		try {
			File entrada = new File("entrada.txt");
			Scanner leitor = new Scanner(entrada);
			FileWriter saida_arquivo = new FileWriter("saida.txt");
			PrintWriter gravar_arquivo = new PrintWriter(saida_arquivo);

			while (leitor.hasNextLine()) {
				int numero_de_automatos = leitor.nextInt();
				leitor.nextLine();

				while (numero_de_automatos > 0) {
					/* Especificacoes */
					String especificacoes[] = leitor.nextLine().split(" ");
					int quantidade_estados = Integer.parseInt(especificacoes[0]);
					int simbolos_alfabeto = Integer.parseInt(especificacoes[1]);
					int qnt_transicoes = Integer.parseInt(especificacoes[2]);
					int indice_estado_inicial = Integer.parseInt(especificacoes[3]);
					int numero_estados_aceitacao = Integer.parseInt(especificacoes[4]);

					/* Aceitacao */
					int[] indices_estado_aceitacao = new int[numero_estados_aceitacao];
					for (int i = 0; i < numero_estados_aceitacao; i++)
						indices_estado_aceitacao[i] = leitor.nextInt();
					leitor.nextLine();

					Estado[] lista_estados = new Estado[quantidade_estados];
					Estado.aceitou = false;
					for (int i = 0; i < quantidade_estados; ++i)
						lista_estados[i] = new Estado(
								false, simbolos_alfabeto, i);

					/* Setar estados de aceitacao o objeto estado */
					for (int i = 0; i < numero_estados_aceitacao; i++)
						lista_estados[indices_estado_aceitacao[i]].aceita = true;

					/* Receber as transicoes */
					while (qnt_transicoes > 0) {
						int recebe = leitor.nextInt();
						int simbolo = leitor.nextInt();
						int destino = leitor.nextInt();
						leitor.nextLine();

						lista_estados[recebe].transicao.get(simbolo).add(destino);
						qnt_transicoes--;
					}

					/* Ler os testes */
					int qnt_teste = leitor.nextInt();
					leitor.nextLine();

					int[] saida = new int[qnt_teste];
					for (int i = 0; i < qnt_teste; i++) {
						String[] linha = leitor.nextLine().split(" ");

						int[] lista_simbolos = new int[linha.length];
						for (int aux = 0; aux < linha.length; ++aux)
							lista_simbolos[aux] = Integer.parseInt(linha[aux]);

						simular (lista_estados, indice_estado_inicial, lista_simbolos, 0);

						if (Estado.aceitou) {
							saida[i] = 1;
							Estado.aceitou = false;
						} else
							saida[i] = 0;
					}

					/* Print do resultado dos testes no terminal */
					printSaida(saida, saida_arquivo, gravar_arquivo);

					/* Passa para o proximo automato */
					numero_de_automatos--;
				}
			}
			leitor.close();
			saida_arquivo.close();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	static void simular (Estado[] lista_estados, int estado_atual, int[] expressao, int index) {
		ListIterator<Integer> estados_vazios = lista_estados[estado_atual].transicao.get(0).listIterator();
		while (estados_vazios.hasNext())
			simular (lista_estados, estados_vazios.next(), expressao, index);

		/* Fim da expressao */
		if (index > expressao.length - 1) {
			/* Se acabar em um estado em que ele e aceito coloque true na variavel aceitou*/
			if (lista_estados[estado_atual].aceita)
				Estado.aceitou = true;
			return;
		}

		/* Otimizar */
		if (Estado.aceitou) return;

		/* Andar estados*/
		ListIterator<Integer> andar_pelos_estados =
				lista_estados[estado_atual].transicao.get(expressao[index]).listIterator();
		while (andar_pelos_estados.hasNext() &&
				!Estado.aceitou)
			simular (lista_estados, andar_pelos_estados.next(), expressao, index + 1);

		return;
	}

	static void printSaida (int[] saida, FileWriter saida_arquivo, PrintWriter gravar_arquivo){
		for (int i = 0; i < saida.length; i++)
			if (i == saida.length - 1)
				gravar_arquivo.println(saida[i]);
			else
				gravar_arquivo.print(saida[i] + " ");
	}
}

class Estado {
	static boolean aceitou;
	boolean aceita;
	int indice;
	ArrayList<LinkedList<Integer>> transicao;

	Estado (boolean aceita, int estados, int indice) {
		this.aceita = aceita;
		this.indice = indice;
		this.transicao = new ArrayList<LinkedList<Integer>>();
		for (int i = 0; i < estados; i++)
			transicao.add(new LinkedList<Integer>());
	}
}
