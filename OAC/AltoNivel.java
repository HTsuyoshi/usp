import java.util.Scanner;

class AltoNivel{

    static int maior (int a, int b) {
        if (a > b)
            return a;
        return b;
    }

    static int menor (int a, int b) {
        if (a < b)
            return a;
        return b;
    }

    static int MDC (int maior, int menor) {
        if (menor == 0) {
            return maior;
        }
        return MDC (menor, maior % menor);
    }

    public static void main (String args[]) {
        Scanner ler = new Scanner (System.in);

        
        System.out.print("Digite a quantidade de numeros: ");
        int qnt = ler.nextInt();

        int numeros[] = new int[qnt];
        for (int i=0; i<qnt; i++)
            numeros[i] = ler.nextInt();

        int temp = numeros[0];
        for (int i=1; i<qnt; i++) {
            temp = MDC (maior (temp, numeros[i]), menor (temp, numeros[i]));
            if (temp == 1)
                break;
        }
 
        System.out.print("O Máximo Divisor Comum de (");
        for (int numero : numeros)
            if (numero == numeros[qnt - 1])
                System.out.print(numero);
            else
                System.out.print(numero + ", ");
        System.out.println(") = " + temp);
    }
}

