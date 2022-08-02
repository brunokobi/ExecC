public class Teste1 {
	public static void main(String[] args) {
		IAgenda A = new AgendaImplementada();
		A.insereContato(new ContatoImplementado("pai", 123));
		A.insereContato(new ContatoImplementado("mae", 456));
		A.insereContato(new ContatoImplementado("irma", 789));
		System.out.println("Existem " + A.totalContatos() + " contatos inseridos");
		A.mostraDadosContatos();
		System.out.println("-----------------");
		A.removeContato(new ContatoImplementado("pai", 123));
		System.out.println("Existem " + A.totalContatos() + " contatos inseridos");
		A.mostraDadosContatos();
		System.out.println("-----------------");
		A.altera(0, new ContatoImplementado("pai", 123));
		System.out.println("Existem " + A.totalContatos() + " contatos inseridos");
		A.mostraDadosContatos();
		System.out.println("-----------------");
		A.altera(1, new ContatoImplementado("mae", 456));
		System.out.println("Existem " + A.totalContatos() + " contatos inseridos");
		A.mostraDadosContatos();
		System.out.println("-----------------");
		A.removeContato(new ContatoImplementado("pai", 123));
		System.out.println("Existem " + A.totalContatos() + " contatos inseridos");
		A.mostraDadosContatos();
		System.out.println("-----------------");
		System.out.println(A.posicao(new ContatoImplementado("mae", 456)));
		System.out.println("-----------------");
		System.out.println(A.posicao(new ContatoImplementado("pai", 123)));
		System.out.println("-----------------");
		System.out.println(A.altera(0, new ContatoImplementado("pai", 123)));
		System.out.println("-----------------");
		System.out.println(A.selecionaContato(0));
		System.out.println("-----------------");
		A.removeTodos();
		System.out.println("Existem " + A.totalContatos() + " contatos inseridos");
	}
}