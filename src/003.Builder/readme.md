# Builder - 生成器模式

#### 1. 一句话描述

> 构造函数的参数过多时使用生成器**Builder**

#### 2. 学术化语言

> 将一个复杂的对象的构建和其表示分离，使得同样的构建方式有多种表示方法。

#### 3. 部件的装配过程 

@startuml
Title "BundleLauncher类图"
interface BundleExtractor
abstract class BundleLauncher
abstract class SoBundleLauncher
abstract class AssetBundleLauncher
BundleLauncher <|-- ActivityLauncher
BundleLauncher <|-- SoBundleLauncher
SoBundleLauncher <|-- ApkBundleLauncher
BundleExtractor <|.. SoBundleLauncher
SoBundleLauncher <|-- AssetBundleLauncher
AssetBundleLauncher <|-- WebBundleLauncher
class ActivityLauncher {
	+ public preloadBundle(Bundle bundle)
}
class SoBundleLauncher {
	+ public preloadBundle(Bundle bundle)
}
class ApkBundleLauncher {
	+ public loadBundle(Bundle bundle)
}
class AssetBundleLauncher {
	+ public loadBundle(Bundle bundle)
}
@enduml
