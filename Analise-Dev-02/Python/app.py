
x = 1 / 2 + 3 // 3 + 4 ** 2
print(x)

def foo(n):
    if n > 1:
        return n * foo(n-1)
    return n

print(foo(4))

