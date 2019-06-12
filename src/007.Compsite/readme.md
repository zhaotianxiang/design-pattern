# Composite 组合模式

#### 1.简介

组合模式，就是在一个对象中包含其他对象，这些被包含的对象可能是终点对象（不再包含别的对象），也有可能是非终点对象（其内部还包含其他对象，或叫组对象），我们将对象称为节点，即一个根节点包含许多子节点，这些子节点有的不再包含子节点，而有的仍然包含子节点，以此类推。

所谓组合模式，其实说的是对象包含对象的问题，通过组合的方式（在对象内部引用对象）来进行布局，我认为这种组合是区别于继承的，而另一层含义是指树形结构子节点的抽象（将叶子节点与数枝节点抽象为子节点），区别于普通的分别定义叶子节点与数枝节点的方式。

#### 2. 应用场景

**目录和文件的组合**
组合模式是树形结构，终结点叫叶子节点，非终节点（组节点）叫树枝节点，第一个节点叫根节点。同时也类似于文件目录的结构形式：文件可称之为终节点，目录可称之为非终节点（组节点）。
我们分别定义了文件节点对象与目录节点对象，这是因为文件与目录之间的操作不同，文件没有下级节点，而目录可以有下级节点，但是我们能不能这么想：既然文件与目录都是可以作为一个节点的下级节点而存在，那么我们可不可以将二者抽象为一类对象，虽然二者的操作不同，但是我们可以在实现类的方法实现中具体定义，比如文件没有新增下级节点的方法，我们就可以在文件的这个方法中抛出一个异常，不做具体实现，而在目录中则具体实现新增操作。显示操作二者都有，可以各自实现。而且由于我们将文件与目录抽象为一个类型，那么结合多态我们可以进行如下实现：

```java
/**
   * 将文件与目录统一看作是一类节点，做一个抽象类来定义这种节点，然后以其实现类来区分文件与目录，在实现类中分别定义各自的具体实现内容
    */
public abstract class Node {
    protected String name;//名称
    //构造器赋名
    public Node(String name) {
        this.name = name;
    }
    //新增节点：文件节点无此方法，目录节点重写此方法
    public void addNode(Node node) throws Exception{
        throw new Exception("Invalid exception");
    }
    //显示节点：文件与目录均实现此方法
    abstract void display();
}


/**
   * 实现文件节点
    */
public class Filer extends Node {
    //通过构造器为文件节点命名
    public Filer(String name) {
        super(name);
    }
    //显示文件节点
    @Override
    public void display() {
        System.out.println(name);
    }
}


import java.util.*;
/**
   * 实现目录节点
    */
public class Noder extends Node {
    List<Node> nodeList = new ArrayList<Node>();//内部节点列表（包括文件和下级目录）
    //通过构造器为当前目录节点赋名
    public Noder(String name) {
        super(name);
    }
    //新增节点
    public void addNode(Node node) throws Exception{
        nodeList.add(node);
    }
    //递归循环显示下级节点
    @Override
    void display() {
        System.out.println(name);
        for(Node node:nodeList) {
            node.display();
        }
    }
}

public class Clienter {
    public static void createTree(Node node) throws Exception{
        File file = new File(node.name);
        File[] f = file.listFiles();
        for(File fi : f) {
            if(fi.isFile()) {
                Filer filer = new Filer(fi.getAbsolutePath());
                node.addNode(filer);
            }
            if(fi.isDirectory()) {
                Noder noder = new Noder(fi.getAbsolutePath());
                node.addNode(noder);
                createTree(noder);//使用递归生成树结构
            }
        }
    }
    public static void main(String[] args) {
        Node noder = new Noder("E://ceshi");
        try {
            createTree(noder);
        } catch (Exception e) {
            e.printStackTrace();
        }
        noder.display();
    }
}
```

#### 3. 总结
这种组合模式正是应树形结构而生，所以组合模式的使用场景就是出现树形结构的地方。比如：文件目录显示，多及目录呈现等树形结构数据的操作。
