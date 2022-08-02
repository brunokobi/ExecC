public class Teste2 {
	public static void main(String[] args) {
		IAgenda A = new AgendaImplementada();
		IContato c;
		long tempo = System.currentTimeMillis();
		for (int i = 0; i < 1000; i++) {
			c = new ContatoImplementado("nome " + i, i);
			A.insereContato(c);
		}
		tempo = System.currentTimeMillis() - tempo;
		System.out.println("Total de Registros = " + A.totalContatos());
		A.mostraDadosContatos();
		System.out.println("Inseridos em " + tempo + " milisegundo(s)");
	}
}