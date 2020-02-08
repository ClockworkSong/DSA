# 3 5.5 + 2 /

def cal(x, y, op):
	if op == '+':
		return x+y
	elif op == '-':
		return x-y
	elif op == '*':
		return x*y
	else:
		return x/y

exp = input().split()
print(exp)
st = list()
for i in exp:
	if i in '+-*/':
		b = st.pop()
		a = st.pop()
		st.append(cal(a, b, i))
	else:
	    st.append(float(i))

print('%.1f' % st.pop())
