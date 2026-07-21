// Implementação da função push(inserir) para a pilha
void push(Pilha *p, Elemento e) {
    if (pilhaCheia(p)) {
        printf("Erro: pilha cheia. Não é possível inserir.\n");
        return;
    }
 
    p->topo++;              // Avança o topo
    p->itens[p->topo] = e;  // Insere o novo elemento
}

// Implementação da função pop(remover) para a pilha 
void pop(Pilha *p, Elemento *e) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há elementos para remover.\n");
        e->valor = -1;  // Define um valor padrão para indicar falha
        return;
    }

    *e = p->itens[p->topo];  // Copia o valor do topo
    p->topo--;               // Decrementa o topo
}

// Implementação da função peek(consulta) o elemento do topo da pilha sem removê-lo
void peek(Pilha *p, Elemento *e) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há elementos no topo.\n");
        e->valor = -1;  // Valor padrão para indicar erro
        return;
    }

    *e = p->itens[p->topo];  // Copia o elemento do topo sem alterar a pilha
}

// Esvazia a pilha: reinicia o topo, mas não libera a memória alocada, pois a pilha é estática
void liberarPilha(Pilha *p) {
    p->topo = -1;  // Define a pilha como vazia novamente
}

// Libera todos os nós da pilha dinâmica, garantindo que a memória alocada seja liberada corretamente
void liberarPilha(Pilha *p) {
    while (p->topo != NULL) {
        No *remover = p->topo;
        p->topo = p->topo->prox;
        free(remover);  // Libera a memória alocada
    }
}