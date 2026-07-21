# variavel local e global
def func1(x):
    x = 10
    print(f'A função func1 - x = {x}')

def func2(x):
    x = 20
    print(f'A função func2 - x = {x}')
    
    return x

vp = 0
print(f'Progama pricincipal -  vp = {vp}')

vp = func1(vp)
print(f'Progama pricincipal -  vp = {vp}')

vp = func2(vp)
print(f'Progama pricincipal -  vp = {vp}')

