import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

interface InterfaceGerenciadorDeSalas {

    public void adicionaSalaChamada(String nome, int capacidadeMaxima, String descricao);

    public void removeSalaChamada(String nomeDaSala);

    public List<Sala> listaDeSalas();

    public void adicionaSala(Sala sala);

    public Reserva reservaSalaChamada(String nomeDaSala, LocalDateTime dataInicial, LocalDateTime dataFinal);

    public void cancelaReserva(Reserva cancelada);

    public Collection<Reserva> reservasParaSala(String nomeSala);
    
    public void imprimeReservasDaSala(String nomeSala);
}
