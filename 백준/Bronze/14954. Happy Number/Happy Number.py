def isHappy(n):
  lists = []

  while True:
  
    if n==1 :
      return True
    
    if n in lists :
       return False 
    lists.append(n)
    n_str = str(n)
    n = 0
    for i in n_str:
      n += (int(i)**2)
  
  return False


a = input()
if isHappy(a) : 
    print("HAPPY")
else : 
    print("UNHAPPY")
