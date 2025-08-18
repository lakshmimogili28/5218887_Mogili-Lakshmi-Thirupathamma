import sys

# Fast token reader
tokens = sys.stdin.buffer.read().split()
it = iter(tokens)

Q = int(next(it))          # number of operations
S = []                     # current text as a list of chars
history = []               # stack of (op_type, payload) for undo
out = []                   # collected outputs for type-3

for _ in range(Q):
    t = next(it).decode()  # operation type: '1','2','3','4'

    if t == '1':           # append W
        w = next(it).decode()
        S.extend(w)
        history.append(('1', len(w)))

    elif t == '2':         # delete k
        k = int(next(it))
        if k:
            deleted = ''.join(S[-k:])
            del S[-k:]
        else:
            deleted = ''
        history.append(('2', deleted))

    elif t == '3':         # print k-th character (1-indexed)
        k = int(next(it))
        out.append(S[k - 1])

    else:                  # t == '4' -> undo last type 1 or 2
        op, payload = history.pop()
        if op == '1':      # undo append: remove last payload chars
            if payload:
                del S[-payload:]
        else:              # undo delete: restore deleted string
            S.extend(payload)

sys.stdout.write('\n'.join(out))