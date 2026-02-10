class Addition {
    int num1;
    int num2;

    Addition(int a, int b) {
        num1 = a;
        num2 = b;
    }

    void add() {
        int sum = num1 + num2;
        System.out.println("Sum = " + sum);
    }
}

public class Main {
    public static void main(String[] args) {
        Addition obj = new Addition(10, 20);
        obj.add();
    }
}
