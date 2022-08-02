
public class AgendaImplementada implements IAgenda {
	
	private IContato[] contatos;
	private int quantidade;
	
	public AgendaImplementada() {
		this.contatos = new IContato[1];
		this.contatos[0] = null;
		this.quantidade = 0;
	}

	@Override
	public void insereContato(IContato contato) {
		this.contatos[this.quantidade++] = contato;
		if (this.quantidade == this.contatos.length) {
			IContato[] novo_array = new IContato[this.quantidade*2];
			for (int i = 0; i < this.contatos.length; i++) {
				novo_array[i] = this.contatos[i];
			}
			for (int i = this.quantidade; i < novo_array.length; i++) {
				novo_array[i] = null;
			}
			this.contatos = novo_array;
		}
	}

	@Override
	public int totalContatos() {
		return this.quantidade;
	}

	@Override
	public void mostraDadosContatos() {
		for (int i = 0; i < this.quantidade; i++) {
			System.out.println("Posição " + i + " = " + this.contatos[i]);
		}
	}

	@Override
	public void removeContato(IContato contato) {
		int pos = this.posicao(contato);
		if (pos >= 0) {
			for (int i = pos; i < this.quantidade-1; i++) {
				this.contatos[i] = this.contatos[i+1];
			}
			this.contatos[--this.quantidade] = null;
		}
	}

	@Override
	public void removeTodos() {
		this.contatos = new IContato[1];
		this.contatos[0] = null;
		this.quantidade = 0;		
	}

	@Override
	public IContato selecionaContato(int posicao) {
		if (posicao < 0 || posicao >= this.quantidade)
			return null;
		
		return this.contatos[posicao];
	}

	@Override
	public int posicao(IContato contato) {
		for (int i = 0; i < this.quantidade; i++) {
			if (this.contatos[i].equals(contato))
				return i;
		}
		return -1;
	}

	@Override
	public boolean altera(int posicao, IContato contatoEntra) {
		if (this.selecionaContato(posicao) == null)
			return false;
		
		this.contatos[posicao] = contatoEntra;
		return true;
	}
}
