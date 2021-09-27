import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class GerenciadorDeSalas implements InterfaceGerenciadorDeSalas {
	
	List<Sala> salas;
	Collection<Reserva> reservas;
	
	GerenciadorDeSalas() {
		this.salas = new ArrayList<Sala>();
		this.reservas = new ArrayList<Reserva>();
	}

    public void adicionaSalaChamada(String nome, int capacidadeMaxima, String descricao) {
    	String[] locObs = descricao.split(":");
    	String local = locObs[0], observacao = locObs[1];
    	Sala novaSala = new Sala(nome, capacidadeMaxima, local, observacao);
    	this.adicionaSala(novaSala);
    }

    public void removeSalaChamada(String nomeDaSala) {
    	Sala remover = null;
    	for(Sala sala : salas) {
    		if (sala.getNome().equals(nomeDaSala)) {
    			remover = sala;
    		}
    	}
    	if(remover != null) salas.remove(remover);
    }

    public List<Sala> listaDeSalas() {
    	return this.salas;
    }

    public void adicionaSala(Sala sala) {
    	this.salas.add(sala);
    }

    public Reserva reservaSalaChamada(String nomeDaSala, LocalDateTime dataInicial, LocalDateTime dataFinal) {
    	Reserva reservaSala = null;
    	for (Sala sala : salas) {
    		if (sala.getNome().equals(nomeDaSala)) {
    			reservaSala = new Reserva(dataInicial, dataFinal, sala);
    		}
    	}

    	if (reservaSala == null)  this.cancelaReserva(reservaSala);
    	
    	reservas.add(reservaSala);
    	
    	return reservaSala;
    }

    public void cancelaReserva(Reserva cancelada) {
    	try {
	    	throw new Exception("Não foi possível reservar uma sala, pois não existe uma sala com esse nome.");
    	} catch (Exception e) {
    		e.printStackTrace();
    		System.err.println("Não foi possível reservar uma sala, pois não existe uma sala com esse nome.");
    	}
    }

    public Collection<Reserva> reservasParaSala(String nomeSala) {
    	Collection<Reserva> reservasDaSala = new ArrayList<Reserva>();
    	for (Reserva reserva : reservas) {
    		if(reserva.sala().getNome().equals(nomeSala)) {
    			reservasDaSala.add(reserva);
    		}
    	}
    	return reservasDaSala;
    }

    public void imprimirUmaReserva(Reserva reserva) {
    	System.out.println("\nSala: " + reserva.sala().getNome());
		DateTimeFormatter formatador = DateTimeFormatter.ofPattern("dd MMM uuuu HH:MM");
    	System.out.println("Início: " + formatador.format(reserva.inicio()));
    	System.out.println("Fim: " + formatador.format(reserva.fim()));
    }
    
    public void imprimeReservasDaSala(String nomeSala) {
    	if(this.reservas.isEmpty()) {
			System.out.println("Não foi encontradas reservas para a sala " + nomeSala);
			return;
		}
    	for(Reserva reserva : reservas) {
    		imprimirUmaReserva(reserva);
    	}
    }
}
