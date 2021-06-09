while(True):
    try:
        x, a, y, b = map(int, input().split())
        if(x * b == a * y):
            print("=")
        elif (x * b > a * y):
            print(">")
        else:
            print("<")
    except:
        exit()
