import java.time.LocalDateTime;

public class Reserva {

	private LocalDateTime inicio;
	private LocalDateTime fim;
	private Sala sala;
	 
	Reserva(LocalDateTime inicio, LocalDateTime fim, Sala sala) {
		this.sala = sala;
		this.inicio = inicio;
		this.fim = fim;
	}
	
    public Sala sala() {
    	return this.sala;
    }

    public LocalDateTime inicio() {
    	return this.inicio;
    }

    public LocalDateTime fim() {
    	return this.fim;
    }
    	
}
