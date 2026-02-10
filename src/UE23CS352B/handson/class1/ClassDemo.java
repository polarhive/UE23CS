class Person {
    private String firstName;
    private int age;

    Person(String firstName, int age) {
        this.firstName = firstName;
        this.age = age;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    void displayInfo() {
        System.out.println("Name: " + firstName);
        System.out.println("Age: " + age);
    }
}

public class ClassDemo {
    public static void main(String[] args) {
        System.out.println("Hello world");

        Person p1 = new Person("John", 25);
        p1.displayInfo();
    }
}
