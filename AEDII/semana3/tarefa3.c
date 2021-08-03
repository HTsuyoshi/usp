typedef struct registro {
	int i;
	struct registro* prox;
} REGISTRO;

typedef struct {
	REGISTRO* inicio;
	REGISTRO* fim;
} FILA;

void inicializarFila(FILA* f) {
	f->inicio = NULL;
	f->fim = NULL;
}

int sairFila(FILA* f) {
	if (!f->inicio) return -1;
	int i = f->inicio->i;
	REGISTRO* apagar = f->inicio;
	f->inicio = f->inicio->prox;
	free(apagar);
	if (!f->inicio) f->fim = NULL;
	return i;
}

void entrarFila (FILA* f, int i) {
	REGISTRO* novo = (REGISTRO*)malloc(sizeof(REGISTRO*));
	novo->i = i;
	novo->prox = NULL;
	if (!f->inicio) f->inicio = novo;
	else f->fim->prox = novo;
	f->fim = novo;
}

int custoChaveMaisProxima(VERTICE* g, int i) {
	int custo;
	FILA f;
	inicializarFila(&f);
	g[i].flag = 1;
	entrarFila(&f, i);

	while (f.inicio) {
		custo = 0;
		i = sairFila(&f);
		NO* p = g[i].inicio;
		while (p) {
			custo += p->peso;
			if(g[p->v].flag==0) {
				g[p->v].flag = 1;
				entrarFila(&f, p->v);
			}
			if (g[i].temChave == 1)	break;
			p = p->prox;
		}
		if (g[i].temChave == 1)	break;
		g[i].flag = 2;
	}
	return custo;
}
