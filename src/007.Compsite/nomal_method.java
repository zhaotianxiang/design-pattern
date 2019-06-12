public class Noder {
    String nodeName;

    List<Noder> nodelist = new ArrayList<Noder> ();
    List<Filer> filelist = new ArrayList<Noder> ();
    
	public Noder(String name) {
        this.nodeName = name;
    }

    public void addNoder(Noder noder) {
        filelist.add(noder);
    }

    public void addFiler(Filer filer) {
        fileList.add(filer);
    }

    public void display() {
        for(Noder noder:nodeList) {
            System.out.println(noder.nodeName);
            node.display();
        }

        for(Filer file:fileList) {
            filer.display();
        }
    }
	
}


public class Filer {
    String fileName;
    public Filer(String name) {
        this.fileName = name;
    }

    public void display() {
        System.out.println(fileName);
    }

}
