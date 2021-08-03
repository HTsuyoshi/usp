//Henrique Tsuyoshi Yara (11796083) e Larissa Yurie Maruyama (11295928)

import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.LinkedList;

class Glc {

    /*
     *  Classe para simular uma gramatica de live contexto
     *  
     *  @param simbolosTerminais: guarda quais simbolos sao simbolos terminais
     *  @param regras: guarda respectivamente um simbolo e um conjunto de regras
     *  @param existe: uma variavel para guardar se e possivel gerar certa cadeia
     *  @param estadoInicial: uma variavel para guardar a cadeia inicial
     */

    HashMap<String, LinkedList<String>> regras;
    static boolean existe;
    static String estadoInicial;

    /*
     *  Construtor da classe
     *  
     *  Vai inicializar os atributos existe, regras e estadoInicial
     */

    Glc() {
        existe = false;
        estadoInicial = "";
        this.regras = new HashMap<String, LinkedList<String>>();
    }

    /*
     * Inicializa as regras da glc
     * 
     * Para cada simbolo vai existir uma lista ligada das expressoes que vao substituir o simbolo
     * Caso a lista nao exista vai criar uma lista
     * 
     * @param entrada: String que contem o simbolo e as regras a serem tratadas
     */

    public void intanciarRegra(String entrada) {
        String[] entradaFormatada = entrada.split(" => ");
        String simbolo = entradaFormatada[0];
        String regras = entradaFormatada[1];

        if(this.regras.containsKey(simbolo)) {
            LinkedList<String> conjuntoRegras = this.regras.get(simbolo);
            conjuntoRegras.add(regras);
        } else {
            LinkedList<String> conjuntoRegras = new LinkedList<String>();
            conjuntoRegras.add(regras);
            this.regras.put(simbolo, conjuntoRegras);
        }
    }
}

public class glc {

    /*
	 * Funcao que Intancia a Glc com as entradas recebidas
	 * 
	 * Por utilizarmos HashMap acabamos nao usando a quantidade de numero de variaveis e simbolos terminais
	 * 
	 * @param entrada: e o Scanner que vai receber as entradas
	 * @param glc: o objeto que vai simular as entradas
	 */

    public static void criarGlc(Scanner entrada, Glc glc) {
        int numeroVariaveis = entrada.nextInt(), 
            simbolosTerminais = entrada.nextInt(), 
            numeroRegras = entrada.nextInt();

        entrada.nextLine();

        String[] gramatica = entrada.nextLine().split(" ");
        Glc.estadoInicial = gramatica[0];

        String[] terminaisGramatica = entrada.nextLine().split(" ");

        for(int j=0; j<numeroRegras; j++)
            glc.intanciarRegra(entrada.nextLine());
    }

    /*
	 * Funcao que retorna a quantidade de elementos em uma cadeia
	 * 
	 * @param cadeia: cadeia que vai ser verificada
	 */

    public static int quantidadeElementos(String cadeia) {
        String[] listaCadeia = cadeia.split(" ");
        return listaCadeia.length;
    }

    /*
	  * Funcao recursiva que vai passar por todas as cadeias menores ou iguais a cadeiaFinal
	  * 
	  * Caso exista duas expressoes para substituir ele vai substituir apenas a primeira que achar,
	  * caso a cadeia fique maior que a cadeiaFinal nao entra na proxima recursao
      *
      * Vai dar um break depois da primeira substituicao para otimizar
	  * 
	  * @param cadeia: cadeia de strings que vai ser substituida
	  * @param glc: objeto que vai ser usado para os testes
	  * @param cadeiaFinal: cadeia que queremos chegar
	  */

    public static void simular(String cadeia, Glc glc, String cadeiaFinal) {
        if(cadeia.equals(cadeiaFinal)) Glc.existe = true; 
        if(Glc.existe) return; 

        String[] chaves = cadeia.split(" "); 
        for (String chave : chaves) {
            if(glc.regras.containsKey(chave)) {
                LinkedList<String> listaRegras= glc.regras.get(chave);

                for(String regra: listaRegras) {
                    String cadeiaNova = cadeia.replaceFirst(chave, regra);
                    if(quantidadeElementos(cadeiaNova) <= quantidadeElementos(cadeiaFinal))
                        simular(cadeiaNova.strip(), glc, cadeiaFinal);
                }
                break;
            }
        }
    }

    /*
     * Funcao para simular a glc
     * 
     * Vai chamar a funcao simular e com base no seu resultado colocar 1 ou 0 na string saida
     *
     * Arruma no final do loop a variavel existe para poder fazer o proximo teste
     * 
     * @param cadeia: vai receber as entradas para serem testadas
     * @param glc: o objeto glc que vai ser usado para testar
     */

    public static String testarGlc(Scanner cadeia, Glc glc) {
        int numeroCadeias = cadeia.nextInt();
        cadeia.nextLine();

        String saida = "";
        for(int i=0; i<numeroCadeias; i++) {
            String cadeiaTeste = cadeia.nextLine();
            simular(Glc.estadoInicial, glc, cadeiaTeste);

            if(Glc.existe) saida += "1";
            else saida += "0";
            if(!(i == numeroCadeias - 1)) saida += " ";

            Glc.existe = false;
        }

        return saida;
    }

    /*
     * Funcao principal
     * 
     * Vai ler os arquivos inp-glc.txt para receber as regras da glc
     * Vai ler os arquivos inp-cadeias.txt para receber os casos teste da glc
     * Vai escrever os resultados no arquivo out-status.txt
     */

    public static void main(String[] args) throws IOException {
        File entradaGlc = new File("inp-glc.txt");
        Scanner entrada = new Scanner(entradaGlc);

        File entradaCadeia = new File("inp-cadeias.txt");
        Scanner cadeia = new Scanner(entradaCadeia);

        BufferedWriter escreverSaida = new BufferedWriter(new FileWriter("out-status.txt"));

        int numeroGramaticas = entrada.nextInt();

        String saida;
        for(int i=0; i<numeroGramaticas; i++) {
            Glc glc = new Glc();
            criarGlc (entrada, glc);
            saida = testarGlc(cadeia, glc);
            escreverSaida.append(saida + "\n");
        }
        escreverSaida.close();
        entrada.close();
    }
}
