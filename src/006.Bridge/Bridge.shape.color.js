public abstract class Shape {
    Color color;

    public void setColor(Color color) {
        this.color = color;
    }

    public abstract void draw();
}


public class Circle	 extends Shape {
    public void draw() {
        color.bepaint("圆形");
    }
}

public interface Color{
    public void bepaint(String shape);
}

public class White implements Color {
    public void bepaint(String shape) {
        System.out.print("白色的"+shape);
    }
}


public class Client {
    public static void main(String[] args) {
        //白色
        Color white = new White();
        //正方形
        Shape square = new Square();
        //白色的正方形
        square.setColor(white);
        square.draw();

        //长方形
        Shape rectange = new Rectangle();
        rectange.setColor(white);
        rectange.draw();
    }
}
