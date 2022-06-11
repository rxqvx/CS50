
h = input("Height: ")

def is_input_valid(input):
    try:
        parsed = int(input)
        return parsed>0 and parsed<9
    except:
        return False

while not is_input_valid(h):
    h = input("Height: ")

h = int(h)

for i in range(1,h+1):
    whitespaces = h-i
    print(" " * whitespaces + "#" * i + "  " + "#" * i)
