public class Singleton
{
	private static Singleton instance;
	// 关键操作 私有化构造函数。
	private Singleton(){};

	public static synchronized Singleton getInstance()
	{
		if(instance != null)
		{
			return instance;
		}
		return new Singleton();
	}

}
