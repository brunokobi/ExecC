package testes;

import main.Kruscal;
import tad.Grafo;

public class Max {

	public static void main(String[] args) {
		Grafo g = new Grafo(3);
		int camisas = 8;
		int custoTotal = 0, custo;
		int[] vencedores = {5,3,2};
		
		g.addAresta(0, 1, 3);
		g.addAresta(0, 2, 2);
//		g.addAresta(1, 3, 5);
//		g.addAresta(2, 3, 1);
//		g.addAresta(2, 4, 1);
		
		Kruscal k = new Kruscal();
		k.execute(g);
		Grafo f = k.getAgm();
		int[][] arestas_kruscal = k.tracaRota(0, vencedores);
		
		camisas-=vencedores[0];
		int i = 0;
		int pais = 0, pais_origem = 0;
		while (camisas > 0) {
			if (arestas_kruscal[i][0] != pais_origem && arestas_kruscal[i][1] != pais_origem)
				pais_origem = pais;
			pais = arestas_kruscal[i][0] == pais_origem ? arestas_kruscal[i][1] : arestas_kruscal[i][0];
			custo = f.getPeso(arestas_kruscal[i][0], arestas_kruscal[i][1]);
			custoTotal += custo;
			System.out.printf("%d,%d: %d%n", arestas_kruscal[i][0], arestas_kruscal[i][1], custo);
			i++;
			camisas -= vencedores[pais];
		}
		System.out.println(custoTotal);
	}
}
