package tad;

public class Grafo {
	private int[][] vertices;
	private int n_arestas;
	private int pesoTotal;

	public Grafo(int n_vertices) {
		this.vertices = new int[n_vertices][n_vertices];
	}

	public Grafo() {
		this(0);
	}
	
	public int[][] getVertices() {
		return vertices;
	}

	public boolean addAresta(int v1, int v2, int peso) {
		if (Math.max(v1, v2) >= vertices.length || peso < 1)
			return false;
		if (this.vertices[v1][v2] > 0)
			return false;
		
		this.n_arestas++;
		vertices[v1][v2] = vertices[v2][v1] = peso;
		this.pesoTotal += peso;
		return true;
	}

	public int addVertice() {
		int[][] vrts = new int[vertices.length+1][vertices.length+1];

		for (int i = 0; i < this.vertices.length; i++) {
			for (int j = 0; j <= i; j++) {
				vrts[i][j] = vrts[j][i] = this.vertices[i][j];
			}
		}
		this.vertices = vrts;
		return vrts.length;
	}

	public int getPeso(int v1, int v2) {
		if (Math.max(v1, v2) >= this.vertices.length)
			return -1;

		return this.vertices[v1][v2];
	}
	
	public int getPeso() {
		return this.pesoTotal;
	}
	
	public int quantVertices() {
		return this.vertices.length;
	}
	
	public int quantArestas() {
		return this.n_arestas;
	}
	
	public int[][] getListaArestas() {
		int[][] arestas = new int[this.n_arestas][2];
		int k = 0;
		for (int i = 0; i < this.vertices.length; i++) {
			for (int j = 0; j <= i; j++) {
				if (this.vertices[i][j] > 0) {
					arestas[k][0] = j;
					arestas[k][1] = i;
					k++;
				}
			}
		}
		return arestas;
	}
	
	public int[][] arestasOrdenadas() {
		int[][] arestas = this.getListaArestas();
		this.ordena(arestas);
		
		return arestas;
	}

	private void ordena(int[][] arestas) {
		quicksort(arestas, 0, arestas.length-1);
	}

	private void quicksort(int[][] matriz, int esq, int dir) {
		int meio = (esq+dir)/2;
		int pivo = this.getPeso(matriz[meio][0], matriz[meio][1]);
		int i = esq, j = dir;
		int[] troca;
		while (i <= j) {
			while (this.getPeso(matriz[i][0], matriz[i][1]) < pivo) i++;
			while (this.getPeso(matriz[j][0], matriz[j][1]) > pivo) j--;
			if (i <= j) {
				troca = matriz[i];
				matriz[i] = matriz[j];
				matriz[j] = troca;
				i++; j--;
			}
		}
		if (esq < j) {
			quicksort(matriz, esq, j);
		}
		if (dir > i) {
			quicksort(matriz, i, dir);
		}
	}
		
	@Override
	public String toString() {
		return "";
	}
}
