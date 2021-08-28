.data
    # Frases que serao usadas para a interface de usuario
    qntNum:
    	.asciiz "Digite a quantidade de números: "
    	
    entNum:
    	.asciiz "Digite o numero: "
    	
    qntEscolhida:
    	.asciiz "A quantidade escolhida foi: "
    	
    resultadoModulo1:
    	.asciiz "O modulo entre os numeros ("
    	
    resultadoModulo2:
    	.asciiz ") é "
    	
    quebraDeLinha:
    	.asciiz "\n"
    	
    virgula:
    	.asciiz ", "
    	
.text
    main:
    
    # Imprime a mensagem para receber o tamanho do array
    imprimirQntNum:
   	li $v0, 4			# Preparar para imprimir uma string
    	la $a0, qntNum	# Imprimir a string que esta armazenada em qntNum
    	syscall			# Imprimir
    	
    # Recebe o tamanho do array
    lerQntNum:
    	jal lerInt		# Chamar a funcao que le um inteiro e armazena no registrador t2
    	move $t1, $t2	# Mover o tamanho do array para o registrador t1 (onde ele vai ficar pelo resto do programa)
    
    move $t0, $zero 	# Contar quantas vezes recebeu um numero
    
    # Imprime a mensagem para receber os elementos do array 
    lerArray:
    	beq $t0, $t1, imprimirEscolhido	# Condicao de parada da estrutura de desvio e vai para imprimirEscolhido caso o registrador t0 seja igual ao t1
    	jal fraseLer			# Funcao que imprime o texto para o usuario colocar o elemento do array
    	jal lerInt				# Chamar a funcao que le um inteiro e armazena no registrador t2
    	addi $sp, $sp, -4		# Aumentar o tamanho da stack
    	sw $t2, ($sp)			# Armazenar o valor que esta no registrador t2 no array na memoria ocupada pela variavel $t4
    	addi $t0, $t0, 1		# Incrementar um na quantidade de vezes que passou o array
    	j lerArray				# Volta para o comeco do loop
    
    # Imprime a quantidade de elementos escolhidos pelo usuario
    imprimirEscolhido:  
    	li $v0, 4				# Preparar para imprimir uma string
    	la $a0, qntEscolhida	# Imprimir a string que esta armazenada em qntEscolhida
    	syscall					# Imprimir
    	  	
    	li $v0, 1		# Preparar para imprimir um inteiro
    	move $a0, $t1	# Imprimir o inteiro no registrador t1
    	syscall			# Imprimir
    	
    	li $v0, 4				# Preparar para imprimir uma string
    	la $a0, quebraDeLinha	# Imprimir a string que esta armazenada em qntEscolhida
    	syscall					# Imprimir
    	
    addi $t0, $zero, 1 		# Contar quantas vezes recebeu um numero
    addi $t5, $zero, 4 		# Index do array
    lw $a0, ($sp)			# Coloca o primeiro elemento do array no registrador $a0
    
    # Calcula o modulo
    calcularModulo:
    	beq $t0, $t1, imprimirModulo1	# Condicao de parada da estrutura de desvio e vai para imprimirModulo1 caso o registrador t0 seja igual ao t1
    	lb $a1, ($sp)			# Pega o valor do array que esta em t5 e coloca em a1
    	jal mdc							# Pula para a funcao mdc com os argumentos nos registradores a0 e a1
    	addi $t0, $t0, 1				# Incrementar um na quantidade de vezes que passou o array
    	addi $sp, $sp, 4				# Andar pela stack
    	move $a0, $v1					# Coloca o resultado do mdc no registrador a0 para ser usado na proxima conta
    	j calcularModulo				# Volta para o comeco do loop
    	
    # Imprime a primeira parte da menssagem do resultado
    imprimirModulo1:
   	move $t6, $v1					# Armazena o resultado da conta no registrador t6 para ser impresso depois
    	li $v0, 4					# Prepara para imprimir uma string
    	la $a0, resultadoModulo1	# Imprimir a string que esta armazenada em resultadoModulo1
    	syscall						# Imprimir
    	
    addi $t0, $zero, 1 # Index do array
    addi $t5, $zero, 0 # Index do array na memoria
    
    lw $t2, ($sp) # Pega o primeiro elemento da lista
    	addi $sp, $sp, -4		# Incrementar um na memoria que sera armazenada o elemento
   
    li $v0, 1		# Preparar para imprimir um inteiro
    move $a0, $t2	# Imprimir o inteiro no registrador t2
    syscall		# Imprimir
    	
    addi $t5, $zero, 4 	# Incrementa o index do array na memoria
    
    # Imprime todos os numeros que foi feito o mdc
    imprimirModulo2:
    	beq $t0, $t1, imprimirModulo3	# Condicao de parada da estrutura de desvio e vai para imprimirModulo3 caso o registrador t0 seja igual ao t1
    	lw $t2, ($sp)			# Pega o valor do array que esta em t5 e coloca em t2
    	
    	li $v0, 4			# Prepara para imprimir uma string
    	la $a0, virgula		# Imprimir a string que esta armazenada em virgula
    	syscall				# Imprimir
    	
    	li $v0, 1			# Prepara para imprimir um inteiro
    	move $a0, $t2		# Imprimir a string que esta armazenada no registrador t2
    	syscall				# Imprimir
    	
    	addi $t0, $t0, 1		# Incrementar um na quantidade de vezes que passou o array
    	addi $sp, $sp, -4		# Voltar na stack
    	j imprimirModulo2
    
    # Imprime o resto da string que mostra o mdc
    imprimirModulo3:
    	li $v0, 4					# Prepara para imprimir uma string
    	la $a0, resultadoModulo2	# Imprimir a string que esta armazenada em resultadoModulo2
    	syscall						# Imprimir
    	
    	li $v0, 1				# Prepara para imprimir um inteiro
    	move $a0, $t6			# Imprimir um inteiro que esta armazenada no registrador t6
    	syscall					# Imprimir
    
    # Encerra o program
    encerrar:
    	li $v0, 10	# Prepara para encerrar o programa
    	syscall		# Encerrar
	
	# Imprime a frase para o usuario digitar os elementos do array
    fraseLer:
   		li $v0, 4 		# Prepara para imprimir uma string
    	la $a0, entNum	# Imprime a string armazenada em entNum
    	syscall			# Imprimir
    	jr $ra			# Retorna para onde foi chamado usando o registrador $ra
    	
    # Le um inteiro e armazena no registrador t2
    lerInt:
    	li $v0, 5		# Prepara para ler inteiro
    	syscall			# Ler
    	la $t2, ($v0)	# Coloca a entrada no registrador t2
    	jr $ra			# Retorna para onde foi chamado usando o registrador $ra
    	
    # Troca o conteudo de a0 com o conteudo de a1
    trocar:
    	move $t4, $a0	# Usa o registrador t4 como auxiliar para trocar os valores de a0 e a1
    	move $a0, $a1	# Coloca o valor do registrador a1 em a0
    	move $a1, $t4	# Coloca o valor do registrador t4 em a1
    	jr $ra			# Retorna para onde foi chamado usando o registrador $ra
    	
    # Faz a divisao entre a0 e a1 e coloca o resto em v1
    modulo: 
    	divu $a0, $a1	# Divide o numero a0 pelo numero a1 e coloca o resto en HI
    	mfhi $v1		# Pega o resto da divisao de a0 por a1 que foi armazenado em HI e colca no registrador v1
    	jr $ra			# Retorna para onde foi chamado usando o registrador $ra
    	
    # Calcula o mdc entre a0 e a1
    mdc: 
    	move $t3, $ra			# Armazena o endereco de retorno no registrador t3, posa outras funcoes serao usadas dentro dessa funcao
    	bge $a0, $a1, loopMdc	# Caso a0 seja maior que a1 ele vai para a funcao loopMdc
    	jal trocar				# Casp a0 seja menor que a1 troca o conteudo dos dois registradores
    	
    	# Enquanto a1 nao for igual a zero continua fazendo o modulo
    	loopMdc: 
    		beq $a1, $zero, fimMdc	# Condicao de parada, se o registrador de a1 for maior que zero vai parao fim da funcao mdc--
    		jal modulo				# Faz o modulo entre a0 e a1
    		move $a0, $v1			# Coloca o conteudo do registrador v1 no registrador a0
    		jal trocar				# Troca os valores a0 e a1 de lugar, pois depois da divisao o valor de a0 vai ser maior que o valor de a1
    		j loopMdc				# Volta para o começo do loop
    	
    	# Retorna o modulo de a0 e a1 em v1
    	fimMdc: 
    		move $v1, $a0		# Coloca o valor do registrador a0 em v1 para retornar
    		move $ra, $t3		# Pega o valor de retorno que ficou armazenado no registrador t3 e coloca em ra
    		jr $ra				# Retorna para a funcao main
