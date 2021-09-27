
public class Sala implements InterfaceSala {
	
    private String nome;
    private int capacidade;
    private String local;
    private String observacao;

    Sala (String nome, int capacidadeMaxima, String local, String observacoes){
        this.nome = nome;
        this.capacidade = capacidadeMaxima;
        this.local = local;
        this.observacao = observacoes;
    }

    public String getNome() {
        return this.nome;
    }

    public int getCapacidadeMaxima() {
        return this.capacidade;
    }

    public String getLocal() {
        return this.local;
    }
    
    public String getObservacoes() {
        return this.observacao;
    }

}
