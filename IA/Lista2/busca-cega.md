- Busca em largura sem repetir nós na árvore.

```mermaid
	flowchart TD
		A((A 1)) --> B((B 2))
		A --> C((C 3))
		B --x|Repeated| C1((C))
		B --> D((D 4))
		C --x|Repeated| A1((A))
		C --x|Repeated| B1((B))
		C --x|Repeated| D1((D))
		C --> E((E 5))
		C --> F(((F 6)))
```

- Busca em largura sem checar para repetição de nós (permita que nós sejam repitidos).

```mermaid
	flowchart TD
		A1((A 1)) --> B2((B 2))
		A1 --> C3((C 3))
		B2 --> D4((D 4))
		B2 --> C5((C 5))
		C3 --> A6((A 6))
		C3 --> B7((A 7))
		C3 --> D8((D 8))
		C3 --> E9((E 9))
		C3 --> F10(((F 10)))
```

- Busca em profundidade sem repetir nós na árvore.

```mermaid
	flowchart TD
		A1((A 1)) --> B2((B 2))
		B2 --> C3((C 3))
		C3 --x|Repeated| A((A))
		C3 --x|Repeated| BR1((B))
		C3 --> D4((D 4))
		D4 --x|Repeated| BR2((B))
		D4 --x|Repeated| C((C))
		D4 --> F5((F 5))
```

- Busca em profundidade limita ($l = 6$nós) sem checar para repetição de nós (permita que nós sejam repitidos).

```mermaid
	flowchart TD
		A1((A 1)) --> B2((B 2))
		B2 --> A3((A 3))
		A3 --> B4((B 4))
		B4 --> A5((A 5))
		A5 -->|Max| B6((B 6))
		A5 -->|Max| C6((C 6))
		B4 --> C5((C 5))
		C5 -->|Max| A6((A 6))
		C5 -->|Max| B6((B 6))
		C5 -->|Max| D6((D 6))
		C5 -->|Max| E6((E 6))
		C5 -->|Max| F6(((F 6)))
```

- Busca em profundidade iterativa sem checar para repetição de nós (permita que nós sejam repitidos)

$$l = 1$$

```mermaid
	flowchart TD
		A1((A 1))
```

$$l = 2$$

```mermaid
	flowchart TD
		A1((A 1)) -->|Max| B2((B 2))
		A1((A 1)) -->|Max| C3((C3))
```

$$l = 3$$

```mermaid
	flowchart TD
		A1((A 1)) --> B2((B 2))
		B2 -->|Max| A3((A 3))
		B2 -->|Max| C3((C 3))
		B2 -->|Max| D3((D 3))
		A1 --> C2((C 2))
		C2 -->|Max| B3((B 3))
		C2 -->|Max| D3((D 3))
		C2 -->|Max| E3((E 3))
		C2 -->|Max| F3(((F 3)))
```

- Busca de custo uniforme (desempate pelo nó mais raso e depois pela ordem alfabética ). Quando ocorrer nós repitidos, mantenha apenas o de menor custo acumulado.

```mermaid
	flowchart TD
		AR1((A 1)) -->|T = 1| BR2((B 2))
		BR2 --x|T = 2 Higher| AR3((A))
		BR2 -->|T = 3| CR3((C 4))
		CR3 --x|T = 8 Higher| AR4((A))
		CR3 --x|T = 5 Higher| BR4((B))
		CR3 --x|T = 8 Higher| DR4((D))
		CR3 --x|T = 6 Higher| FR4((F))
		CR3 -->|T = 4| ER4((E 5))
		ER4 --x|T = 5 Higher| CR51((C))
		ER4 --x|T = 5| FR5((F 8))
		BR2 -->|T = 2| DR3((D 3))
		DR3 --x|T = 4 Higher| BR41((B))
		DR3 --x|T = 8 Higher| FR41((F))
		DR3 --x|T = 8 Higher| CR4((C))
		AR1 --x|T = 5 Higher| CR2((C 6))
```

