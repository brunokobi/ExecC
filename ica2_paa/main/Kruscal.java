package main;
import tad.Grafo;

public class Kruscal {
	
	private Grafo agm;
	
	public void execute(Grafo grafo) {
		this.agm = new Grafo(grafo.quantVertices());
		int componentes[] = new int[grafo.quantVertices()];
		int proxComponente = grafo.quantVertices();
		int adicionadas = 0;

		for(int i = 0; i < grafo.quantVertices(); i++)
			componentes[i] = i;//no início cada vértice é um componente

		int listaArestas[][] = grafo.arestasOrdenadas();
		int t = listaArestas.length;
		for(int i=0; i < t && adicionadas < grafo.quantArestas(); i++){
			//se estiverem em componentes diferentes então pode colocar na arvore
			int de = listaArestas[i][0];
			int para = listaArestas[i][1];

			if (componentes[de]!=componentes[para]) {
				this.agm.addAresta(listaArestas[i][0], listaArestas[i][1], grafo.getPeso(listaArestas[i][0], listaArestas[i][1]));
				int compDe = componentes[de];
				int compPara = componentes[para];
				for(int k=0; k<componentes.length; k++){
					if(componentes[k] == compDe || componentes[k] == compPara)
						componentes[k] = proxComponente;//coloca no mesmo componente
				}
				proxComponente++;
				adicionadas++;
			}
		}
	}
	
	public Grafo getAgm() {
		return agm;
	}
	
	public int[][] tracaRota(int origem, int[] peso_vertices) {
		int[][] vertices = agm.getVertices();
		int[][] arestas = agm.getListaArestas();
		
		int inicio, k = 0;
		for (int i = 0; i < vertices.length; i++) {
			inicio = k;
			for (int j = i+1; j < vertices.length; j++) {
				if (vertices[i][j] > 0) {
					arestas[k][0] = i;
					arestas[k][1] = j;
					k++;
				}
			}
			ordenaPorPeso(arestas, i, peso_vertices, inicio, k);
		}
		return arestas;
	}
	
	private void ordenaPorPeso(int[][] arestas, int vertice, int[] peso_vertices, int inicio, int fim) {
		int[] troca;
		int posicao, peso, maior_peso;
		
		for (int i = inicio; i < fim-1; i++) {
			maior_peso = peso = arestas[i][0] == vertice ? peso_vertices[arestas[i][1]] : peso_vertices[arestas[i][0]];
			posicao = i;
			for (int j = i+1; j < fim; j++) {
				peso = arestas[j][0] == vertice ? peso_vertices[arestas[j][1]] : peso_vertices[arestas[j][0]];
				if (peso > maior_peso) {
					peso = maior_peso;
					posicao = j;
				}
			}
			troca = arestas[i];
			arestas[i] = arestas[posicao];
			arestas[posicao] = troca;
		}
	}
	
//	public int[][] tracaRota(int origem, int[] peso_vertices) {
//		int[][] arestas = agm.getListaArestas();
//		int[] troca;
//		int vertice = 0, posicao = 0;
//		
//		for (int i = 0; i < arestas.length-1; i++) {
//			posicao = i;
//			for (int j = i+1; j < arestas.length; j++) {
//				if (arestas[j][0] == vertice || arestas[j][1] == vertice) {
//					posicao = j;
//					j = arestas.length;
//				}
//			}
//			vertice = arestas[posicao][0] == vertice ? arestas[posicao][1] : arestas[posicao][0];
//			troca = arestas[i];
//			arestas[i] = arestas[posicao];
//			arestas[posicao] = troca;
//		}
//		return arestas;
//	}
}
