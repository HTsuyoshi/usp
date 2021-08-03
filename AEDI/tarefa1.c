int verificarOrdem(int vetor[], int N){

    int crescente = 1, decrescente = 1, identicos = 1, i, aux = vetor[0];

    for(i = 1; i < N; i++){

        if(aux < vetor[i]) {
            decrescente = 0;
            identicos = 0;
        }

        if(aux > vetor[i]){
            crescente = 0;
            identicos = 0;
        }

        aux = vetor[i];
    }

    if(identicos == 1) return 0;
    if(crescente == 1) return 1;
    if(decrescente == 1) return -1;
    else return 99;

}
