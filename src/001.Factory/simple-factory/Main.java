import Shape;
import ShapeFactory;

public class Main {
    public static void main(String [] args){

        Shape shape = ShapeFactory.getShape("Circle");
        shape.draw();
        
    }
}
