

N, r, c = map(int, input().split())

bd = {}


def go(level, stx, sty, stv):

    if level == 0 :
        bd[(stx, sty)] = stv
        bd[(stx,sty+1)] = stv+1
        bd[(stx+1, sty)] = stv+2
        bd[(stx+1, sty+1)] = stv+3
        return

    p_acc = 2**level
    v_acc = 4**level

    if r >= stx+p_acc and c >= sty+p_acc :
        go(level-1, stx+p_acc, sty+p_acc, stv+v_acc+v_acc+v_acc)
    elif r >= stx+p_acc and c >= sty :
        go(level-1, stx+p_acc, sty, stv+v_acc+v_acc)
    elif r >= stx and c >= sty+p_acc :
        go(level-1, stx, sty+p_acc, stv+v_acc)
    else :
        go(level-1, stx, sty, stv)
    
    return

go(N-1, 0, 0, 0)

print(bd[(r,c)])

