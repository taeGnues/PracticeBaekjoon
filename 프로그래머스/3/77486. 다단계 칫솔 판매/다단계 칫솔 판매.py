def solution(enroll, referral, seller, amount):
    
    adj = {enroll[i] : referral[i] for i in range(len(referral))}
    revenues = {e:0 for e in enroll}
    
    def go(money, curr):
        if curr not in adj: # 민호 도달 혹은 분배할 돈 1원 미만.
            return
        
        if (money // 10) == 0 :
            revenues[curr] += money
            return

        send = money // 10
        mine = money - send

        revenues[curr] += mine

        go(send, adj[curr])

    for i in range(len(seller)):
        go(100*amount[i], seller[i])
        
        
    return list(revenues.values())