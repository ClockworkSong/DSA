
#二叉树节点
class BinNode:
	def __init__(self, data):# init构造函数
		self.data = data
		self.left = None
		self.right = None
#表示完整的二叉树
class BinTree(object):
	"""docstring for BinTree"""
	def __init__(self, arg):
		super(BinTree, self).__init__()
		self.root = BinNode(arg)# 将树根初始化为传入的arg

	def preOrder(self, r):
		if r is None:
			return
		print(r.data, end=' ')
		self.preOrder(r.left)
		self.preOrder(r.right)

	def findX(self, pb, x):
		if pb is None:
			return
		if pb.data == x:
			return pb
		f = self.findX(pb.left, x)
		if f is not None:
			return f
		return self.findX(pb.right, x)

	def insert(self, pb, rdata, lr, data):
		f = self.findX(pb, rdata)
		if f is None:
			return
		if lr == 0:
			if f.left is not None:
				return
			f.left = BinNode(data)
		else:
			if f.right is not None:
				return
			f.right = BinNode(data)

a = BinTree(11)
a.insert(a.root, 11, 0, 22)
a.insert(a.root, 11, 1, 33)
a.insert(a.root, 22, 1, 44)
a.insert(a.root, 22, 0, 55)
a.insert(a.root, 33, 1, 66)
a.preOrder(a.root)


