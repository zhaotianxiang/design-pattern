class Builder(object):
	def head(self):
		raise NotImplementedError()
	def body(self):
		raise NotImplementedError()

class ThinBuilder(Builder):
	def head(self):
		print('build thin head')
	def body(self):
		print('build thin body')

class FatBuilder(Builder):
	def head(self):
		print('build fat head')
	def body(self):
		print('build fat body')

class Director(object):
	def build(self, builder):
		builder.head();
		builder.body();

# 感觉除了增加client的调用负担外，似乎没什么用处。为什么不把产品构建过程放在Builder基类中呢
def client():
	director = Director();
	director.build(ThinBuilder());

client()
