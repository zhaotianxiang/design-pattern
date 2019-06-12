# Decorator 装饰器模式

#### 1. 简介

装饰器模式（Decorator Pattern）允许向一个现有的对象添加新的**功能**，同时又不改变其结构。
这种模式创建了一个装饰类，用来包装原有的类，并在保持类方法签名完整性的前提下，提供了额外的功能。

#### 2. 实现

我们将创建一个 Shape 接口和实现了 Shape 接口的实体类。然后我们创建一个实现了 Shape 接口的抽象装饰类 ShapeDecorator，并把 Shape 对象作为它的实例变量。

RedShapeDecorator 是实现了 ShapeDecorator 的实体类。

DecoratorPatternDemo，我们的演示类使用 RedShapeDecorator 来装饰 Shape 对象。




