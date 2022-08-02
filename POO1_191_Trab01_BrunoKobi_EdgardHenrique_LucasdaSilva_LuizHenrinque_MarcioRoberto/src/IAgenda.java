
public interface IAgenda {
	
	public void insereContato(IContato contato);
	public int totalContatos();
	public void mostraDadosContatos();
	public void removeContato(IContato contato);
	public void removeTodos();
	public IContato selecionaContato(int posicao);
	public int posicao(IContato contato);
	public boolean altera(int posicao, IContato contatoEntra);
}
