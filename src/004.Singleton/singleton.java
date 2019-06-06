public class Singleton
{
	private static Singleton instance = new Singleton();

	// 关键操作 私有化构造函数。
	private Singleton(){};

	public static Singleton getInstance()
	{
		return instance;
	}

}
