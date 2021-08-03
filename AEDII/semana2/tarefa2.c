void salasComChaves(VERTICE* g, int i, NO** listaLigada)
{
	g[i].flag = 1;

	if(g[i].temChave == 1) {
		if(!(*listaLigada)) {
			(*listaLigada) = (NO*) malloc(sizeof(NO*));
			(*listaLigada)->v = g[i].inicio->v;
			(*listaLigada)->peso = g[i].inicio->peso;
			(*listaLigada)->prox = NULL;
		} else {
			NO* aux = (*listaLigada);
			while(aux->prox)
				aux = aux->prox;
			aux->prox = (NO*) malloc(sizeof(NO*));
			aux->prox->v = g[i].inicio->v;
			aux->prox->peso = g[i].inicio->peso;
			aux->prox->prox = NULL;
		}
	}

	NO* p = g[i].inicio;

	while(p) {
		if(g[p->v].flag == 0)
			salasComChaves(g, p->v, listaLigada);
		p = p->prox;
	}

	g[i].flag = 2;
}
