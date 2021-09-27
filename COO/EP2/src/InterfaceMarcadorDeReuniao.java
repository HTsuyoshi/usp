import java.time.LocalDateTime;
import java.util.Collection;

interface InterfaceMarcadorDeReuniao {
	
    public void marcarReuniaoEntre(LocalDateTime dataInicial, LocalDateTime dataFinal, Collection<String> listaDeParticipantes);
 
    public void indicaDisponibilidadeDe(String participante, LocalDateTime inicio, LocalDateTime fim);

    public void mostrarSobreposicao();
}
