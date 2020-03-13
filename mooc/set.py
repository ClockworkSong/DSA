s = set()
s.add(11)
s.add(3)
s.add(22)
s.add(33)
s2 = set()
s2.add(11)
s2.add(666)
s2.add(2333)
print(s.union(s2))#集合并集操作
print(s)
print(s | s2)#并集
print(s & s2)#交集
print(s-s2)