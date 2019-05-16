import Circle;
import Shape;

public class ShapeFactory{
    public static Shape getShape(String type){
        if(type.equals("Circle")){
            return new Circle();
        }
        if(type.equals("Square")){
            return new Square();
        }
        throw new RuntimeException("Bad Shape creation: "+type);
    }
}

