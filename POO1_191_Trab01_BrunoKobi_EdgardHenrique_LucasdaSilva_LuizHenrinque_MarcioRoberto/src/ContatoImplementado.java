
public class ContatoImplementado implements IContato {
	
	private String nome;
	private int telefone;

	public ContatoImplementado(String nome, int telefone) {
		this.nome = nome;
		this.telefone = telefone;
	}

	@Override
	public String getNome() {
		return this.nome;
	}

	@Override
	public int getTelefone() {
		return this.telefone;
	}
	
	@Override
	public boolean equals(Object o) {
		ContatoImplementado ci;
		
		if (this == o) return true;
		if (! (o instanceof ContatoImplementado) ) return false;
		
		ci = (ContatoImplementado) o;		
		
		return (this.nome.equalsIgnoreCase(ci.nome) && this.telefone == ci.telefone);
	}
	
	@Override
	public String toString() {
		return this.nome + " tel: " + this.telefone;
	}
}
