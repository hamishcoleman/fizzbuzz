def buzz():
    for n in range(101):
        if n % 15 == 0:
            print("fizzbuzz")
        else:
            if n % 3 == 0:
                print("fizz")
            else:
                if n % 5 == 0:
                    print("buzz")
                else:
                    print(n)
buzz()
