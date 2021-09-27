import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Collection;
import java.time.format.DateTimeFormatter;

class Participante {
	String nome;
	LocalDateTime inicio;
	LocalDateTime fim;
}

public class MarcadorDeReuniao implements InterfaceMarcadorDeReuniao {
	
	LocalDateTime dataInicial;
	LocalDateTime dataFinal;
	Collection<String> listaDeParticipantes;
	Collection<Participante> disponibilidade;
	
	MarcadorDeReuniao() {
		this.dataInicial = null;
		this.dataFinal = null;
	}
	
	public void marcarReuniaoEntre(LocalDateTime dataInicial, LocalDateTime dataFinal, Collection<String> listaDeParticipantes) {
		this.dataInicial = dataInicial;
		this.dataFinal = dataFinal;
		for(Participante participante : disponibilidade) {
			if(participante.inicio.isBefore(dataFinal)) {
				listaDeParticipantes.add(participante.nome);
			} else if(participante.fim.isAfter(dataInicial)) {
				listaDeParticipantes.add(participante.nome);
			}
		}
	}

    public void indicaDisponibilidadeDe(String participante, LocalDateTime inicio, LocalDateTime fim) {
    	Participante participanteDisponibilidade = new Participante();
    	participanteDisponibilidade.nome = participante;
    	participanteDisponibilidade.inicio = inicio;
    	participanteDisponibilidade.fim = fim;
    	this.disponibilidade.add(participanteDisponibilidade);
    }
    
    public void mostrarSobreposicao() {
    	this.limparLista();
    	LocalDateTime comeco = LocalDateTime.MIN;
    	LocalDateTime fim = LocalDateTime.MAX;
    	boolean foiPossivelColocarTodos = true;
		DateTimeFormatter formatador = DateTimeFormatter.ofPattern("dd MMM uuuu HH:MM");
    	for(Participante participante : disponibilidade) {
    		System.out.printf("O participante %s pode participar de %s até %s\n", 
    				participante.nome, formatador.format(participante.inicio), 
    				formatador.format(participante.fim));
    		
    		if(participante.inicio.isBefore(fim) && participante.fim.isAfter(comeco)) {
	    		if(participante.fim.isBefore(fim)) {
	    			fim = participante.fim;
	    		}
	    		if(participante.inicio.isAfter(comeco)) {
	    			comeco = participante.inicio;
	    		}
    		} else {
    			foiPossivelColocarTodos = false;
    		}
    	}
    	
    	if(foiPossivelColocarTodos) {
			System.out.printf("\nTodos os participantes estão disponíveis entre %s até %s\n", 
					formatador.format(comeco), formatador.format(fim));
			for(Participante participante : disponibilidade)
				listaDeParticipantes.add(participante.nome);
    	} else {
    		System.out.println("Não foi possível encontrar um horario em que todos os participantes estão disponíveis");
    	}
    }

    public void limparLista() {
    	this.listaDeParticipantes.clear();
    }
    
    public void instanciarParticipantes(Collection<String> listaDeParticipantes) {
    	this.listaDeParticipantes = listaDeParticipantes;
    }
    
    public void instanciarDisponibilidade() {
		this.disponibilidade = new ArrayList<Participante>();
    }
    
}