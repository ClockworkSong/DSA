N = int(input())
op = input().split()
# print(op)
q = []#人数
while op[0] != '#':
	if op[0] == 'In':
		pid = op[1]
		if len(q) == N:
			print(pid, 'rejected.')
		else:
			q.append(pid)
			print(pid, 'joined. Total:%d' % len(q))
	else:
		if len(q) == 0:
			print('No one!')
		else:
			pid = q.pop(0)
			print(pid, 'Called. Total:%d' % len(q))
	op = input().split()