void adjacencia2incidencia(VERTICE* g, int n)
{
	// Por causa do slide eu considerei os valores v começando em 1 e nao em 0 como seria normalmente
	int i, j;
	NO* auxiliar[n][n];
	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j)
			auxiliar[i][j] = NULL;

	// Iterar sobre os NOs
	NO* aux;
	for(i=0; i<n; ++i)
		if(g[i].inicio) {
			NO* iterar = g[i].inicio;
			NO* prox;
			while(iterar) {
				prox = iterar->prox ? iterar->prox : NULL;
				auxiliar[i][iterar->v-1] = iterar;
				iterar->v = i+1;
				iterar->prox = NULL;
				iterar = prox;
			}}

	// Resetar o vetor
	for(i=0; i<n; ++i)
		g[i].inicio = NULL;

	// Colocar os valores no lugar certo
	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j)
			if (auxiliar[i][j])
				if(g[j].inicio) {
					aux = g[j].inicio;
					if (aux->prox)
						while (aux->prox)
							aux = aux->prox;
					aux->prox = auxiliar[i][j];
				} else
						g[j].inicio = auxiliar[i][j];
}
